/*
 *
 * ethereum_synchronization
 *
 * Created by El Khalil Bellakrid on 27/07/2018.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Ledger
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include <gtest/gtest.h>
#include "../BaseFixture.h"
#include <set>
#include <api/KeychainEngines.hpp>
#include <api/EthereumLikeTransaction.hpp>
#include <utils/DateUtils.hpp>
#include <wallet/ethereum/database/EthereumLikeAccountDatabaseHelper.h>
#include <wallet/ethereum/transaction_builders/EthereumLikeTransactionBuilder.h>
#include <wallet/ethereum/ERC20/ERC20LikeAccount.h>
#include <iostream>
using namespace std;

class EthereumLikeWalletSynchronization : public BaseFixture {

};

TEST_F(EthereumLikeWalletSynchronization, MediumXpubSynchronization) {
    auto walletName = "e847815f-488a-4301-b67c-378a5e9c8a61";
    auto erc20Count = 0;
    {
        auto pool = newDefaultPool();
        {
            auto configuration = DynamicObject::newInstance();
            configuration->putString(api::Configuration::KEYCHAIN_DERIVATION_SCHEME,"44'/60'/0'/0/<account>'");
            configuration->putString(api::Configuration::BLOCKCHAIN_EXPLORER_API_ENDPOINT,"http://eth-mainnet.explorers.dev.aws.ledger.fr");
            auto wallet = wait(pool->createWallet(walletName, "ethereum", configuration));
            std::set<std::string> emittedOperations;
            {
                auto nextIndex = wait(wallet->getNextAccountIndex());
                EXPECT_EQ(nextIndex, 0);

                auto account = createEthereumLikeAccount(wallet, nextIndex, ETH_KEYS_INFO_LIVE);
                auto receiver = make_receiver([&](const std::shared_ptr<api::Event> &event) {
                    if (event->getCode() == api::EventCode::NEW_OPERATION) {
                        auto uid = event->getPayload()->getString(
                                api::Account::EV_NEW_OP_UID).value();
                        EXPECT_EQ(emittedOperations.find(uid), emittedOperations.end());
                    }
                });

                pool->getEventBus()->subscribe(dispatcher->getMainExecutionContext(),receiver);

                receiver.reset();
                receiver = make_receiver([=, &erc20Count](const std::shared_ptr<api::Event> &event) {
                    fmt::print("Received event {}\n", api::to_string(event->getCode()));
                    if (event->getCode() == api::EventCode::SYNCHRONIZATION_STARTED)
                        return;
                    EXPECT_NE(event->getCode(), api::EventCode::SYNCHRONIZATION_FAILED);
                    EXPECT_EQ(event->getCode(),
                              api::EventCode::SYNCHRONIZATION_SUCCEED);

                    auto balance = wait(account->getBalance());

                    auto erc20Accounts = account->getERC20Accounts();
                    erc20Count = erc20Accounts.size();
                    EXPECT_NE(erc20Count, 0);
                    std::cout << "ERC20 Accounts: " << erc20Count << std::endl;

                    auto erc20Ops = erc20Accounts[0]->getOperations();
                    EXPECT_NE(erc20Ops.size(), 0);
                    EXPECT_NE(erc20Ops[0]->getBlockHeight().value_or(0), 0);

                    auto erc20Balance = wait(std::dynamic_pointer_cast<ERC20LikeAccount>(erc20Accounts[0])->getBalance());
                    auto erc20BalanceFromAccount = wait(account->getERC20Balance(erc20Accounts[0]->getToken().contractAddress));
                    EXPECT_EQ(erc20Balance->toString(10), erc20BalanceFromAccount->toString(10));

                    auto amountToSend = std::make_shared<api::BigIntImpl>(BigInt::fromString("10"));
                    auto transferData = wait(std::dynamic_pointer_cast<ERC20LikeAccount>(erc20Accounts[0])->getTransferToAddressData(amountToSend, "0xabf06640f8ca8fC5e0Ed471b10BeFCDf65A33e43"));
                    EXPECT_GT(transferData.size(), 0);
                    
                    auto operations = wait(std::dynamic_pointer_cast<OperationQuery>(erc20Accounts[0]->queryOperations()->complete())->execute());
                    std::cout << "ERC20 Operations: " << operations.size() << std::endl;
                    EXPECT_NE(operations.size(), 0);

                    int64_t gasPrice = 20, gasLimit = 200;
                    auto currency = account->getWallet()->getCurrency();
                    auto txBuilder = std::dynamic_pointer_cast<EthereumLikeTransactionBuilder>(account->buildTransaction());
                    txBuilder->setGasPrice(api::Amount::fromLong(currency, 20));
                    txBuilder->setGasLimit(api::Amount::fromLong(currency, 200));
                    txBuilder->wipeToAddress("0xfb98bdd04d82648f25e67041d6e27a866bec0b47");
                    auto tx = wait(txBuilder->build());
                    EXPECT_EQ(tx->getValue()->toLong(), balance->toLong() - (gasLimit * gasPrice));

                    dispatcher->stop();
                });

                auto restoreKey = account->getRestoreKey();
                account->synchronize()->subscribe(dispatcher->getMainExecutionContext(),receiver);

                dispatcher->waitUntilStopped();

                auto ops = wait(std::dynamic_pointer_cast<OperationQuery>(account->queryOperations()->complete())->execute());
                std::cout << "Ops: " << ops.size() << std::endl;

                auto block = wait(account->getLastBlock());
                auto blockHash = block.blockHash;
            }
        }
    }
    // Recover account
    {
        auto pool = newDefaultPool();
        auto wallet = wait(pool->getWallet(walletName));
        auto account = std::dynamic_pointer_cast<EthereumLikeAccount>(wait(wallet->getAccount(0)));
        EXPECT_EQ(account->getERC20Accounts().size(), erc20Count);

        wait(pool->freshResetAll());
    }
}

TEST_F(EthereumLikeWalletSynchronization, XpubSynchronization) {
    auto pool = newDefaultPool();
    {
        auto configuration = DynamicObject::newInstance();
        configuration->putString(api::Configuration::KEYCHAIN_DERIVATION_SCHEME,"44'/<coin_type>'/<account>'/<node>/<address>");
        configuration->putString(api::Configuration::BLOCKCHAIN_EXPLORER_API_ENDPOINT,"http://eth-ropsten.explorers.dev.aws.ledger.fr");
        //configuration->putString(api::Configuration::BLOCKCHAIN_EXPLORER_VERSION,"v2");
        auto wallet = wait(pool->createWallet("e847815f-488a-4301-b67c-378a5e9c8a61", "ethereum_ropsten", configuration));
        //auto wallet = wait(pool->createWallet("e847815f-488a-4301-b67c-378a5e9c8a61", "ethereum", configuration));
        std::set<std::string> emittedOperations;
        {
            auto nextIndex = wait(wallet->getNextAccountIndex());
            EXPECT_EQ(nextIndex, 0);

            auto account = createEthereumLikeAccount(wallet, nextIndex, ETH_KEYS_INFO);
            auto keychain = account->getRestoreKey();

            auto receiver = make_receiver([&](const std::shared_ptr<api::Event> &event) {
                if (event->getCode() == api::EventCode::NEW_OPERATION) {
                    auto uid = event->getPayload()->getString(
                            api::Account::EV_NEW_OP_UID).value();
                    EXPECT_EQ(emittedOperations.find(uid), emittedOperations.end());
                }
            });

            auto keyStore = account->getRestoreKey();

            pool->getEventBus()->subscribe(dispatcher->getMainExecutionContext(),receiver);

            receiver.reset();
            receiver = make_receiver([=](const std::shared_ptr<api::Event> &event) {
                fmt::print("Received event {}\n", api::to_string(event->getCode()));
                if (event->getCode() == api::EventCode::SYNCHRONIZATION_STARTED)
                    return;
                EXPECT_NE(event->getCode(), api::EventCode::SYNCHRONIZATION_FAILED);
                EXPECT_EQ(event->getCode(),
                          api::EventCode::SYNCHRONIZATION_SUCCEED);

                auto balance = wait(account->getBalance());
                cout<<" ETH Balance: "<<balance->toLong()<<endl;
                auto txBuilder = std::dynamic_pointer_cast<EthereumLikeTransactionBuilder>(account->buildTransaction());
                auto erc20Accounts = account->getERC20Accounts();
                EXPECT_EQ(erc20Accounts.size(), 1);
                EXPECT_EQ(erc20Accounts[0]->getOperations().size(),1);
                auto erc20Balance = wait(std::dynamic_pointer_cast<ERC20LikeAccount>(erc20Accounts[0])->getBalance());
                EXPECT_EQ(erc20Balance->intValue(), 2500);
                auto contractAddress = erc20Accounts[0]->getToken().contractAddress;
                std::cout << "Contract Address: " << contractAddress << std::endl;
                std::cout << "ERC20 balance: " << erc20Balance->toString(10) << std::endl;
                auto erc20Ops = wait(std::dynamic_pointer_cast<OperationQuery>(erc20Accounts[0]->queryOperations()->complete())->execute());
                EXPECT_EQ(erc20Accounts[0]->getOperations().size(), erc20Ops.size());
                EXPECT_EQ(erc20Ops[0]->isComplete(), true);
                dispatcher->stop();
            });

            auto restoreKey = account->getRestoreKey();
            account->synchronize()->subscribe(dispatcher->getMainExecutionContext(),receiver);

            dispatcher->waitUntilStopped();

            auto opQuery = account->queryOperations()->complete();
            auto ops = wait(std::dynamic_pointer_cast<OperationQuery>(account->queryOperations()->complete())->execute());
            //auto ops = ::wait(std::dynamic_pointer_cast<OperationQuery>(opQuery)->execute());
            std::cout << "Ops: " << ops.size() << std::endl;
            EXPECT_EQ(ops[0]->isComplete(), true);
            auto block = wait(account->getLastBlock());
            auto blockHash = block.blockHash;
        }
    }
}

TEST_F(EthereumLikeWalletSynchronization, XpubETCSynchronization) {
    auto pool = newDefaultPool();
    {
        auto configuration = DynamicObject::newInstance();
        configuration->putString(api::Configuration::KEYCHAIN_DERIVATION_SCHEME,"44'/60'/0'/<account>");
        auto wallet = wait(pool->createWallet("e847815f-488a-4301-b67c-378a5e9c8a61", "ethereum_classic", configuration));
        std::set<std::string> emittedOperations;
        {
            auto infos = wait(wallet->getNextAccountCreationInfo());
            EXPECT_EQ(infos.index, 0);

            infos.publicKeys = ETC_KEYS_INFO_LIVE.publicKeys;
            infos.chainCodes = ETC_KEYS_INFO_LIVE.chainCodes;

            // Test that the cointype we use is the one set by KEYCHAIN_DERIVATION_SCHEME
            EXPECT_EQ(infos.derivations[0], "44'/60'/0'/0");
            auto account = createEthereumLikeAccount(wallet, infos.index, infos);

            auto keychain = account->getRestoreKey();

            auto receiver = make_receiver([&](const std::shared_ptr<api::Event> &event) {
                if (event->getCode() == api::EventCode::NEW_OPERATION) {
                    auto uid = event->getPayload()->getString(
                            api::Account::EV_NEW_OP_UID).value();
                    EXPECT_EQ(emittedOperations.find(uid), emittedOperations.end());
                }
            });

            auto keyStore = account->getRestoreKey();

            pool->getEventBus()->subscribe(dispatcher->getMainExecutionContext(),receiver);

            receiver.reset();
            receiver = make_receiver([=](const std::shared_ptr<api::Event> &event) {
                fmt::print("Received event {}\n", api::to_string(event->getCode()));
                if (event->getCode() == api::EventCode::SYNCHRONIZATION_STARTED)
                    return;
                EXPECT_NE(event->getCode(), api::EventCode::SYNCHRONIZATION_FAILED);
                EXPECT_EQ(event->getCode(),
                          api::EventCode::SYNCHRONIZATION_SUCCEED);

                auto balance = wait(account->getBalance());
                cout<<" ETH Balance: "<<balance->toLong()<<endl;
                dispatcher->stop();
            });

            auto restoreKey = account->getRestoreKey();
            account->synchronize()->subscribe(dispatcher->getMainExecutionContext(),receiver);

            dispatcher->waitUntilStopped();

            auto opQuery = account->queryOperations()->complete();
            auto ops = wait(std::dynamic_pointer_cast<OperationQuery>(account->queryOperations()->complete())->execute());
            std::cout << "Ops: " << ops.size() << std::endl;
            EXPECT_EQ(ops[0]->isComplete(), true);
        }
    }
}


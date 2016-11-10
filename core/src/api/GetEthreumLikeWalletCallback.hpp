// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ethereum_like_wallet.djinni

#pragma once

#include <memory>

namespace ledger { namespace core { namespace api {

class EthereumLikeWallet;
struct Error;

class GetEthreumLikeWalletCallback {
public:
    virtual ~GetEthreumLikeWalletCallback() {}

    virtual void onSuccess(const std::shared_ptr<EthereumLikeWallet> & wallet, bool isCreated) = 0;

    virtual void onError(const Error & error) = 0;
};

} } }  // namespace ledger::core::api

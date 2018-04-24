//
// Created by El Khalil Bellakrid on 19/04/2018.
//

#include <crypto_wrapper.h>
#include <vector>
#include <cstdint>
#include <string>
#include <iostream>
#include <assert.h>
//#include "../../../../src/utils/hex.h"
#include <hex.h>

const std::string BitcoinPublicKeyHashPrefix = "00";
const std::string BitcoinPrivateKeyPrefix = "80";
const std::string BitcoinExtendedPublicKeyPrefix = "0488B21E";
const std::string BitcoinExtendedPrivateKeyPrefix = "0488ADE4";

std::vector<std::vector<std::string>> fixtures = {
        {BitcoinPublicKeyHashPrefix, "010966776006953D5567439E5E39F86A0D273BEE", "16UwLL9Risc3QfPqBUvKofHmBQ7wMtjvM"},
        {BitcoinPublicKeyHashPrefix, "7b2f2061d66d57ffb9502a091ce236ed4c1ede2d", "1CELa15H4DMzHtHnuz7LCpSFgFWf61Ra6A"},
        {BitcoinPublicKeyHashPrefix, "89C907892A9D4F37B78D5F83F2FD6E008C4F795D", "1DZYQ3xEy8mkc7wToQZvKqeLrSLUMVVK41"},
        {BitcoinPublicKeyHashPrefix, "0000000000000000000000000000000000000000", "1111111111111111111114oLvT2"},
        {BitcoinPublicKeyHashPrefix, "0000000000000000000000000000000000000001", "11111111111111111111BZbvjr"},
        {BitcoinPrivateKeyPrefix, "0C28FCA386C7A227600B2FE50B7CAE11EC86D3BF1FBE471BE89827E19D72AA1D", "5HueCGU8rMjxEXxiPuD5BDku4MkFqeZyd4dZ1jvhTVqvbTLvyTJ"},
        {BitcoinPrivateKeyPrefix, "00000037FC2B523A9101D653ECB504EBB88FCCE6F7E77548A7B31FA734A00000", "5HpHagjigF1P3i1WyFp1uLPEo8gK32CFBRc2ekJU3nytmXnVbYv"},
        {BitcoinPrivateKeyPrefix, "3C80FA4C012E37402C6D43140EC7B111B931C33799C2A07E8172827B12EEA59F", "5JGw52y3UuZSwpZKYkuhmat8TNy1nZ6F6mbrHJaPNMt2pkETUVE"},
        {BitcoinExtendedPublicKeyPrefix, "000000000000000000873dff81c02f525623fd1fe5167eac3a55a049de3d314bb42ee227ffed37d5080339a36013301597daef41fbe593a02cc513d0b55527ec2df1050e2e8ff49c85c2", "xpub661MyMwAqRbcFtXgS5sYJABqqG9YLmC4Q1Rdap9gSE8NqtwybGhePY2gZ29ESFjqJoCu1Rupje8YtGqsefD265TMg7usUDFdp6W1EGMcet8"},
        {BitcoinExtendedPrivateKeyPrefix, "0478412e3afffffffe637807030d55d01f9a0cb3a7839515d796bd07706386a6eddf06cc29a65a0e2900f1c7c871a54a804afe328b4c83a1c33b8e5ff48f5087273f04efa83b247d6a2d", "xprvA1RpRA33e1JQ7ifknakTFpgNXPmW2YvmhqLQYMmrj4xJXXWYpDPS3xz7iAxn8L39njGVyuoseXzU6rcxFLJ8HFsTjSyQbLYnMpCqE2VbFWc"},
};

using namespace std;

static inline std::vector<uint8_t> vectorize(const std::string& str) {
    return std::vector<uint8_t>(str.data(), str.data() + str.size());
}

static inline std::string strigify(const std::vector<uint8_t>& vector) {
    return std::string(vector.begin(), vector.end());
}


static std::vector<uint8_t> computeChecksum(const std::vector<uint8_t> &bytes) {
    auto hash = wrapper::bytesToBytesHash(bytes);
    auto doubleHash = wrapper::bytesToBytesHash(hash);
    //cout<<"doubleHash: "<<ledger::core::hex::toString(doubleHash)<<endl;
    return std::vector<uint8_t>(doubleHash.begin(), doubleHash.begin() + 4);
}

int main() {

    auto blocksize = 16;
    auto IV = std::vector<uint8_t>();
    for (auto i = 0; i < blocksize; i++) {
        IV.push_back((uint8_t)i);
    }
    std::string data = "Hello world!";
    std::vector<uint8_t> encryptKey;
    for (auto i = 0; i < 32; i++) {
        encryptKey.push_back(i << 1);
    }

    //AES
    auto dataVector = vectorize(data);
    auto encryptedData = wrapper::encrypt(IV, encryptKey, dataVector);
    auto decryptedData = wrapper::decrypt(IV, encryptKey, encryptedData);
    assert(dataVector.size() == decryptedData.size());
    for(int i = 0; i < dataVector.size(); i++) {
        assert(dataVector[i] == decryptedData[i]);
    }
    assert(strigify(decryptedData) == data);

    cout<<"=================================="<<endl;
    cout<<"==========AES TEST OK============="<<endl;
    cout<<"=================================="<<endl;

    //SHA256
    int i = 0;
    for (auto& item : fixtures) {
        auto result = computeChecksum(ledger::core::hex::toByteArray(item[0] + item[1]));
    }

    //"2ff100b36c386c65a1afc462ad53e25479bec9498ed00aa5a04de584bc25301b"
    auto hex_result = ledger::core::hex::toString(wrapper::stringToBytesHash("abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmno"));
    cout<<"hex_result = "<<hex_result<<endl;

    cout<<"=================================="<<endl;
    cout<<"==========SHA256 TEST OK============="<<endl;
    cout<<"=================================="<<endl;

    //RIPEMD160
    std::vector<std::vector<std::string>> ripemd_fixtures = {
            {"", "9c1185a5c5e9fc54612808977ee8f548b2258d31"},
            {"a", "0bdc9d2d256b3ee9daae347be6f4dc835a467ffe"},
            {"abc", "8eb208f7e05d987a9b044a8e98c6b087f15a0bfc"},
            {"message digest", 	"5d0689ef49d2fae572b881b123a85ffa21595f36"}
    };
    for (auto& i : ripemd_fixtures) {
        auto result = wrapper::ripemd160_hash(std::vector<uint8_t>(i[0].begin(), i[0].end()));
        cout<<"ripemd result = "<<ledger::core::hex::toString(result)<<endl;
    }
    cout<<"=================================="<<endl;
    cout<<"==========RIPEMD160 TEST OK============="<<endl;
    cout<<"=================================="<<endl;


    //PBKDF2
    std::string password = "My supa strong password!";
    std::string salt = "Random salt";
    std::vector<uint8_t> pbkdf2EncryptKey = wrapper::pbkdf2_derive(vectorize(password), vectorize(salt), 10000, 32);
    auto pbkdf2Encrypted = wrapper::encrypt(IV, pbkdf2EncryptKey, vectorize(data));
    auto pbdf2Decrypted = wrapper::decrypt(IV, pbkdf2EncryptKey, pbkdf2Encrypted);
    assert(pbdf2Decrypted.size() == dataVector.size());
    auto pbdf2DecryptedString = strigify(pbdf2Decrypted);
    assert(pbdf2DecryptedString == data);
    cout<<"=================================="<<endl;
    cout<<"==========PBKDF2 TEST OK============="<<endl;
    cout<<"=================================="<<endl;




}



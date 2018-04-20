//
// Created by El Khalil Bellakrid on 19/04/2018.
//

#ifndef LEDGER_CORE_CRYPTO_WRAPPER_H
#define LEDGER_CORE_CRYPTO_WRAPPER_H

#include <vector>
#include <cstdint>
#include <string>

namespace wrapper {
    std::vector<uint8_t> encrypt(const std::vector<uint8_t> &IV,
                                 const std::vector<uint8_t> &key,
                                 const std::vector<uint8_t> &data);

    std::vector<uint8_t> decrypt(const std::vector<uint8_t> &IV,
                                 const std::vector<uint8_t> &key,
                                 const std::vector<uint8_t> &data);

    std::vector <uint8_t> stringToBytesHash(const std::string &input);
    std::vector<uint8_t> bytesToBytesHash(const std::vector<uint8_t> &bytes);


    std::vector<uint8_t> ripemd160_hash(const std::vector<uint8_t> &data);

    std::vector<uint8_t> pbkdf2_derive(const std::vector<uint8_t> &key,
                                const std::vector<uint8_t> &salt,
                                uint32_t iter,
                                size_t outLength);

    std::vector<uint8_t> sha256(const std::vector<uint8_t>& key,
                                const std::vector<uint8_t>& data);

    std::vector<uint8_t> sha512(const std::vector<uint8_t>& key,
                                const std::vector<uint8_t>& data);
}
#endif //LEDGER_CORE_CRYPTO_WRAPPER_H

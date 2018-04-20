//
// Created by El Khalil Bellakrid on 19/04/2018.
//
#include "crypto_wrapper.h"
#include <iostream>


using namespace std;

extern "C" {

    typedef struct {
        const uint8_t *data;
        size_t length;
    } vector_t;

    //AES
    vector_t encrypt_rust(const vector_t &IV, const vector_t &key, const vector_t &data);
    vector_t decrypt_rust(const vector_t &IV, const vector_t &key, const vector_t &data);

    //SHA256
    vector_t string_to_bytes_hash(const char *input);
    vector_t bytes_to_bytes_hash(const vector_t input);

    //RIPEMD160
    vector_t ripemd160_hash(const vector_t &input);

    //PBKDF2
    vector_t pbkdf2_derive(const vector_t &key, const vector_t &salt, uint32_t iter, size_t outLength);

    //HMAC
    vector_t hmac_sha256(const vector_t& key,
                         const vector_t& data);

    vector_t hmac_sha512(const vector_t& key,
                         const vector_t& data);
}

namespace wrapper {

    //AES
    std::vector <uint8_t> encrypt(const std::vector <uint8_t> &IV,
                                  const std::vector <uint8_t> &key,
                                  const std::vector <uint8_t> &data) {
        vector_t v_iv = {&IV[0], IV.size()};
        vector_t v_key = {&key[0], key.size()};
        vector_t v_data = {&data[0], data.size()};
        auto result = encrypt_rust(v_iv, v_key, v_data);
        return std::vector<uint8_t>((char *) result.data, (char *) result.data + result.length);
    }

    std::vector <uint8_t> decrypt(const std::vector <uint8_t> &IV,
                                  const std::vector <uint8_t> &key,
                                  const std::vector <uint8_t> &data) {

        vector_t v_iv = {&IV[0], IV.size()};
        vector_t v_key = {&key[0], key.size()};
        vector_t v_data = {&data[0], data.size()};
        auto result = decrypt_rust(v_iv, v_key, v_data);
        return std::vector<uint8_t>((char *) result.data, (char *) result.data + result.length);
    }


    //SHA256
    std::vector <uint8_t> stringToBytesHash(const std::string &input) {
        auto v_hash = string_to_bytes_hash(input.c_str());
        return std::vector<uint8_t>((char *)v_hash.data, (char *)v_hash.data + v_hash.length);
    }

    std::vector<uint8_t> bytesToBytesHash(const std::vector<uint8_t> &bytes) {
        vector_t v_bytes = {&bytes[0], bytes.size()};
        auto v_hash = bytes_to_bytes_hash(v_bytes);
        return std::vector<uint8_t>((char *)v_hash.data, (char *)v_hash.data + v_hash.length);
    }

    //RIPEMD160
    std::vector<uint8_t> ripemd160_hash(const std::vector<uint8_t> &data) {
        vector_t v_data = {&data[0], data.size()};
        auto v_hash = ripemd160_hash(v_data);
        return std::vector<uint8_t>((char *)v_hash.data, (char *)v_hash.data + v_hash.length);
    }

    //PBKDF2
    std::vector<uint8_t> pbkdf2_derive(const std::vector<uint8_t> &key,
                                       const std::vector<uint8_t> &salt,
                                       uint32_t iter,
                                       size_t outLength) {
        vector_t v_key = {&key[0], key.size()};
        vector_t v_salt = {&salt[0], salt.size()};

        auto v_result = pbkdf2_derive(v_key, v_salt, iter, outLength);
        return std::vector<uint8_t>((char *)v_result.data, (char *)v_result.data + v_result.length);
    }

    //HMAC
    std::vector<uint8_t> sha256(const std::vector<uint8_t>& key,
                                const std::vector<uint8_t>& data) {
        vector_t v_key = {&key[0], key.size()};
        vector_t v_data = {&data[0], data.size()};
        auto v_result = hmac_sha256(v_key, v_data);
        return std::vector<uint8_t>((char *)v_result.data, (char *)v_result.data + v_result.length);
    }

    std::vector<uint8_t> sha512(const std::vector<uint8_t>& key,
                                const std::vector<uint8_t>& data) {
        vector_t v_key = {&key[0], key.size()};
        vector_t v_data = {&data[0], data.size()};
        auto v_result = hmac_sha512(v_key, v_data);
        return std::vector<uint8_t>((char *)v_result.data, (char *)v_result.data + v_result.length);
    }
}
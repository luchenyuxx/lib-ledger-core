//
// Created by El Khalil Bellakrid on 19/04/2018.
//

#include <crypto_wrapper.h>
#include <vector>
#include <cstdint>
#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

static inline std::vector<uint8_t> vectorize(const std::string& str) {
    return std::vector<uint8_t>(str.data(), str.data() + str.size());
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
        assert(dataVector[i] == dataVector[i]);
    }
    cout<<"=================================="<<endl;
    cout<<"==========AES TEST OK============="<<endl;
    cout<<"=================================="<<endl;

    //SHA256

}



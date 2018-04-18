//
// Created by El Khalil Bellakrid on 18/04/2018.
//
#include "secp256k1_wrapper.h"
#include <iostream>
#include <stdint.h>

extern "C" {
    void rust_secp256k1_test(int32_t);
    secp256k1_context* secp256k1_context_create_rust(unsigned int flags);
}

namespace wrapper {
    secp256k1_context* secp256k1_context_create(unsigned int flags) {
        return secp256k1_context_create_rust(flags);
    }
}

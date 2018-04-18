//
// Created by El Khalil Bellakrid on 18/04/2018.
//

#ifndef LEDGER_CORE_SECP256K1_WRAPPER_H
#define LEDGER_CORE_SECP256K1_WRAPPER_H

#include <iostream>
#include <stdint.h>
#include <include/secp256k1.h>

namespace wrapper {
    secp256k1_context* secp256k1_context_create(unsigned int flags);
}

#endif //LEDGER_CORE_SECP256K1_WRAPPER_H

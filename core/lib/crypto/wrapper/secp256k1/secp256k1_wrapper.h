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

    int secp256k1_ecdsa_signature_serialize_der(const secp256k1_context* ctx,
                                                unsigned char *output,
                                                size_t *outputlen,
                                                const secp256k1_ecdsa_signature* sig);

    int secp256k1_ec_pubkey_parse(const secp256k1_context* ctx,
                                  secp256k1_pubkey* pubkey,
                                  const unsigned char *input,
                                  size_t inputlen);

    int secp256k1_ecdsa_signature_parse_der(const secp256k1_context* ctx,
                                            secp256k1_ecdsa_signature* sig,
                                            const unsigned char *input,
                                            size_t inputlen);

    int secp256k1_ecdsa_verify(const secp256k1_context* ctx,
                               const secp256k1_ecdsa_signature *sig,
                               const unsigned char *msg32,
                               const secp256k1_pubkey *pubkey);

    int secp256k1_ec_pubkey_serialize(const secp256k1_context* ctx,
                                      unsigned char *output,
                                      size_t *outputlen,
                                      const secp256k1_pubkey* pubkey,
                                      unsigned int flags);

    void secp256k1_context_destroy(secp256k1_context* ctx);

    int secp256k1_ec_pubkey_tweak_add(const secp256k1_context* ctx,
                                      secp256k1_pubkey *pubkey,
                                      const unsigned char *tweak);
}

#endif //LEDGER_CORE_SECP256K1_WRAPPER_H

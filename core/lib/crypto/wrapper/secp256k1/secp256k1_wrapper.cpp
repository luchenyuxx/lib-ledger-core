//
// Created by El Khalil Bellakrid on 18/04/2018.
//
#include "secp256k1_wrapper.h"
#include <iostream>
#include <stdint.h>

extern "C" {
    secp256k1_context* secp256k1_context_create_rust(unsigned int flags);

    int secp256k1_ecdsa_signature_serialize_der_rust(const secp256k1_context* ctx,
                                            unsigned char *output,
                                            size_t *outputlen,
                                            const secp256k1_ecdsa_signature* sig);

    int secp256k1_ec_pubkey_parse_rust(const secp256k1_context* ctx,
                                  secp256k1_pubkey* pubkey,
                                  const unsigned char *input,
                                  size_t inputlen);

    int secp256k1_ecdsa_signature_parse_der_rust(const secp256k1_context* ctx,
                                        secp256k1_ecdsa_signature* sig,
                                        const unsigned char *input,
                                        size_t inputlen);

    int secp256k1_ecdsa_verify_rust(const secp256k1_context* ctx,
                               const secp256k1_ecdsa_signature *sig,
                               const unsigned char *msg32,
                               const secp256k1_pubkey *pubkey);

    int secp256k1_ec_pubkey_serialize_rust(const secp256k1_context* ctx,
                                      unsigned char *output,
                                      size_t *outputlen,
                                      const secp256k1_pubkey* pubkey,
                                      unsigned int flags);

    void secp256k1_context_destroy_rust(secp256k1_context* ctx);

    int secp256k1_ec_pubkey_tweak_add_rust(const secp256k1_context* ctx,
                                  secp256k1_pubkey *pubkey,
                                  const unsigned char *tweak);
}

namespace wrapper {

    secp256k1_context* secp256k1_context_create(unsigned int flags) {
        return secp256k1_context_create_rust(flags);
    }

    int secp256k1_ecdsa_signature_serialize_der(const secp256k1_context* ctx,
                                                unsigned char *output,
                                                size_t *outputlen,
                                                const secp256k1_ecdsa_signature* sig) {
        return secp256k1_ecdsa_signature_serialize_der_rust(ctx, output, outputlen, sig);
    }

    int secp256k1_ec_pubkey_parse(const secp256k1_context* ctx,
                                  secp256k1_pubkey* pubkey,
                                  const unsigned char *input,
                                  size_t inputlen) {
        return secp256k1_ec_pubkey_parse_rust(ctx, pubkey, input, inputlen);
    }

    int secp256k1_ecdsa_signature_parse_der(const secp256k1_context* ctx,
                                            secp256k1_ecdsa_signature* sig,
                                            const unsigned char *input,
                                            size_t inputlen) {
        return secp256k1_ecdsa_signature_parse_der_rust(ctx, sig, input, inputlen);
    }

    int secp256k1_ecdsa_verify(const secp256k1_context* ctx,
                               const secp256k1_ecdsa_signature *sig,
                               const unsigned char *msg32,
                               const secp256k1_pubkey *pubkey) {
        return secp256k1_ecdsa_verify_rust(ctx, sig, msg32, pubkey);
    }

    int secp256k1_ec_pubkey_serialize(const secp256k1_context* ctx,
                                      unsigned char *output,
                                      size_t *outputlen,
                                      const secp256k1_pubkey* pubkey,
                                      unsigned int flags) {
        return secp256k1_ec_pubkey_serialize_rust(ctx, output, outputlen, pubkey, flags);
    }

    void secp256k1_context_destroy(secp256k1_context* ctx) {
        return secp256k1_context_destroy_rust(ctx);
    }

    int secp256k1_ec_pubkey_tweak_add(const secp256k1_context* ctx,
                                      secp256k1_pubkey *pubkey,
                                      const unsigned char *tweak) {
        return secp256k1_ec_pubkey_tweak_add_rust(ctx, pubkey, tweak);
    }
}

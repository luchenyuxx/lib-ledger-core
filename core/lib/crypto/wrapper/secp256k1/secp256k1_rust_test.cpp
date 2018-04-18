//#include <iostream>
//#include <stdint.h>
//#include <include/secp256k1.h>
//
//extern "C" void rust_secp256k1_test(int32_t);
//extern "C" secp256k1_context* secp256k1_context_create_rust(unsigned int flags);
//
//int main()
//{
//    rust_secp256k1_test(32);
//    secp256k1_context_create_rust(SECP256K1_CONTEXT_VERIFY | SECP256K1_CONTEXT_SIGN);
//    return 0;
//}

#include <iostream>
#include <stdint.h>
#include <secp256k1_wrapper.h>

int main()
{
    wrapper::secp256k1_context_create(SECP256K1_CONTEXT_VERIFY | SECP256K1_CONTEXT_SIGN);
    return 0;
}
#include <iostream>
#include <stdint.h>
#include <secp256k1_wrapper.h>

int main()
{
    secp256k1_context* context = wrapper::secp256k1_context_create(SECP256K1_CONTEXT_VERIFY | SECP256K1_CONTEXT_SIGN);
    if(context) {
        std::cout<<"Context OK"<<std::endl;
    }
    return 0;
}
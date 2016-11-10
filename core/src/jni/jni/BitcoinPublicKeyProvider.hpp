// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from bitcoin_public_key_provider.djinni

#pragma once

#include "../../api/BitcoinPublicKeyProvider.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class BitcoinPublicKeyProvider final : ::djinni::JniInterface<::ledger::core::api::BitcoinPublicKeyProvider, BitcoinPublicKeyProvider> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::BitcoinPublicKeyProvider>;
    using CppOptType = std::shared_ptr<::ledger::core::api::BitcoinPublicKeyProvider>;
    using JniType = jobject;

    using Boxed = BitcoinPublicKeyProvider;

    ~BitcoinPublicKeyProvider();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<BitcoinPublicKeyProvider>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<BitcoinPublicKeyProvider>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    BitcoinPublicKeyProvider();
    friend ::djinni::JniClass<BitcoinPublicKeyProvider>;
    friend ::djinni::JniInterface<::ledger::core::api::BitcoinPublicKeyProvider, BitcoinPublicKeyProvider>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::ledger::core::api::BitcoinPublicKeyProvider
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();


    private:
        friend ::djinni::JniInterface<::ledger::core::api::BitcoinPublicKeyProvider, ::djinni_generated::BitcoinPublicKeyProvider>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("co/ledger/core/BitcoinPublicKeyProvider") };
};

}  // namespace djinni_generated

// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from wallet_pool.djinni

#pragma once

#include "../../api/WalletPool.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class WalletPool final : ::djinni::JniInterface<::ledger::core::api::WalletPool, WalletPool> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::WalletPool>;
    using CppOptType = std::shared_ptr<::ledger::core::api::WalletPool>;
    using JniType = jobject;

    using Boxed = WalletPool;

    ~WalletPool();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<WalletPool>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<WalletPool>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    WalletPool();
    friend ::djinni::JniClass<WalletPool>;
    friend ::djinni::JniInterface<::ledger::core::api::WalletPool, WalletPool>;

};

}  // namespace djinni_generated

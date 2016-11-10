// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ethereum_like_wallet.djinni

#pragma once

#include "../../api/GetEthreumLikeWalletCallback.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class GetEthreumLikeWalletCallback final : ::djinni::JniInterface<::ledger::core::api::GetEthreumLikeWalletCallback, GetEthreumLikeWalletCallback> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::GetEthreumLikeWalletCallback>;
    using CppOptType = std::shared_ptr<::ledger::core::api::GetEthreumLikeWalletCallback>;
    using JniType = jobject;

    using Boxed = GetEthreumLikeWalletCallback;

    ~GetEthreumLikeWalletCallback();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<GetEthreumLikeWalletCallback>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<GetEthreumLikeWalletCallback>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    GetEthreumLikeWalletCallback();
    friend ::djinni::JniClass<GetEthreumLikeWalletCallback>;
    friend ::djinni::JniInterface<::ledger::core::api::GetEthreumLikeWalletCallback, GetEthreumLikeWalletCallback>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::ledger::core::api::GetEthreumLikeWalletCallback
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        void onSuccess(const std::shared_ptr<::ledger::core::api::EthereumLikeWallet> & wallet, bool isCreated) override;
        void onError(const ::ledger::core::api::Error & error) override;

    private:
        friend ::djinni::JniInterface<::ledger::core::api::GetEthreumLikeWalletCallback, ::djinni_generated::GetEthreumLikeWalletCallback>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("co/ledger/core/GetEthreumLikeWalletCallback") };
    const jmethodID method_onSuccess { ::djinni::jniGetMethodID(clazz.get(), "onSuccess", "(Lco/ledger/core/EthereumLikeWallet;Z)V") };
    const jmethodID method_onError { ::djinni::jniGetMethodID(clazz.get(), "onError", "(Lco/ledger/core/Error;)V") };
};

}  // namespace djinni_generated

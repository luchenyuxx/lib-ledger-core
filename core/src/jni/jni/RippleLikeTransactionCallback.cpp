// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from callback.djinni

#include "RippleLikeTransactionCallback.hpp"  // my header
#include "Error.hpp"
#include "Marshal.hpp"
#include "RippleLikeTransaction.hpp"

namespace djinni_generated {

RippleLikeTransactionCallback::RippleLikeTransactionCallback() : ::djinni::JniInterface<::ledger::core::api::RippleLikeTransactionCallback, RippleLikeTransactionCallback>() {}

RippleLikeTransactionCallback::~RippleLikeTransactionCallback() = default;

RippleLikeTransactionCallback::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

RippleLikeTransactionCallback::JavaProxy::~JavaProxy() = default;

void RippleLikeTransactionCallback::JavaProxy::onCallback(const std::shared_ptr<::ledger::core::api::RippleLikeTransaction> & c_result, const std::experimental::optional<::ledger::core::api::Error> & c_error) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::RippleLikeTransactionCallback>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_onCallback,
                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni_generated::RippleLikeTransaction>::fromCpp(jniEnv, c_result)),
                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni_generated::Error>::fromCpp(jniEnv, c_error)));
    ::djinni::jniExceptionCheck(jniEnv);
}

}  // namespace djinni_generated
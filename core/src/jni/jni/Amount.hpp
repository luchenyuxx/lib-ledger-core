// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from amount.djinni

#pragma once

#include "../../api/Amount.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class Amount final : ::djinni::JniInterface<::ledger::core::api::Amount, Amount> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::Amount>;
    using CppOptType = std::shared_ptr<::ledger::core::api::Amount>;
    using JniType = jobject;

    using Boxed = Amount;

    ~Amount();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<Amount>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<Amount>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    Amount();
    friend ::djinni::JniClass<Amount>;
    friend ::djinni::JniInterface<::ledger::core::api::Amount, Amount>;

};

}  // namespace djinni_generated

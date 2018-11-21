// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ethereum_like_wallet.djinni

#include "EthereumLikeTransactionBuilder.hpp"  // my header
#include "Amount.hpp"
#include "Currency.hpp"
#include "EthereumLikeTransaction.hpp"
#include "EthereumLikeTransactionCallback.hpp"
#include "Marshal.hpp"

namespace djinni_generated {

EthereumLikeTransactionBuilder::EthereumLikeTransactionBuilder() : ::djinni::JniInterface<::ledger::core::api::EthereumLikeTransactionBuilder, EthereumLikeTransactionBuilder>("co/ledger/core/EthereumLikeTransactionBuilder$CppProxy") {}

EthereumLikeTransactionBuilder::~EthereumLikeTransactionBuilder() = default;


CJNIEXPORT void JNICALL Java_co_ledger_core_EthereumLikeTransactionBuilder_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ledger::core::api::EthereumLikeTransactionBuilder>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_co_ledger_core_EthereumLikeTransactionBuilder_00024CppProxy_native_1sendToAddress(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_amount, jstring j_address)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::EthereumLikeTransactionBuilder>(nativeRef);
        auto r = ref->sendToAddress(::djinni_generated::Amount::toCpp(jniEnv, j_amount),
                                    ::djinni::String::toCpp(jniEnv, j_address));
        return ::djinni::release(::djinni_generated::EthereumLikeTransactionBuilder::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_ledger_core_EthereumLikeTransactionBuilder_00024CppProxy_native_1wipeToAddress(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_address)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::EthereumLikeTransactionBuilder>(nativeRef);
        auto r = ref->wipeToAddress(::djinni::String::toCpp(jniEnv, j_address));
        return ::djinni::release(::djinni_generated::EthereumLikeTransactionBuilder::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_ledger_core_EthereumLikeTransactionBuilder_00024CppProxy_native_1setGasPrice(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_gasPrice)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::EthereumLikeTransactionBuilder>(nativeRef);
        auto r = ref->setGasPrice(::djinni_generated::Amount::toCpp(jniEnv, j_gasPrice));
        return ::djinni::release(::djinni_generated::EthereumLikeTransactionBuilder::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_ledger_core_EthereumLikeTransactionBuilder_00024CppProxy_native_1setGasLimit(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_gasLimit)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::EthereumLikeTransactionBuilder>(nativeRef);
        auto r = ref->setGasLimit(::djinni_generated::Amount::toCpp(jniEnv, j_gasLimit));
        return ::djinni::release(::djinni_generated::EthereumLikeTransactionBuilder::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_ledger_core_EthereumLikeTransactionBuilder_00024CppProxy_native_1setInputData(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jbyteArray j_data)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::EthereumLikeTransactionBuilder>(nativeRef);
        auto r = ref->setInputData(::djinni::Binary::toCpp(jniEnv, j_data));
        return ::djinni::release(::djinni_generated::EthereumLikeTransactionBuilder::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_co_ledger_core_EthereumLikeTransactionBuilder_00024CppProxy_native_1build(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_callback)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::EthereumLikeTransactionBuilder>(nativeRef);
        ref->build(::djinni_generated::EthereumLikeTransactionCallback::toCpp(jniEnv, j_callback));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_co_ledger_core_EthereumLikeTransactionBuilder_00024CppProxy_native_1clone(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::EthereumLikeTransactionBuilder>(nativeRef);
        auto r = ref->clone();
        return ::djinni::release(::djinni_generated::EthereumLikeTransactionBuilder::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_co_ledger_core_EthereumLikeTransactionBuilder_00024CppProxy_native_1reset(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::EthereumLikeTransactionBuilder>(nativeRef);
        ref->reset();
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_co_ledger_core_EthereumLikeTransactionBuilder_parseRawUnsignedTransaction(JNIEnv* jniEnv, jobject /*this*/, jobject j_currency, jbyteArray j_rawTransaction)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::ledger::core::api::EthereumLikeTransactionBuilder::parseRawUnsignedTransaction(::djinni_generated::Currency::toCpp(jniEnv, j_currency),
                                                                                                  ::djinni::Binary::toCpp(jniEnv, j_rawTransaction));
        return ::djinni::release(::djinni_generated::EthereumLikeTransaction::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
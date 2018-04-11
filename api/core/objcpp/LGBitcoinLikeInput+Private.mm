// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from bitcoin_like_wallet.djinni

#import "LGBitcoinLikeInput+Private.h"
#import "LGBitcoinLikeInput.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#import "LGAmount+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface LGBitcoinLikeInput ()

- (id)initWithCpp:(const std::shared_ptr<::ledger::core::api::BitcoinLikeInput>&)cppRef;

@end

@implementation LGBitcoinLikeInput {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::ledger::core::api::BitcoinLikeInput>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::ledger::core::api::BitcoinLikeInput>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

- (nullable NSString *)getAddress {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getAddress();
        return ::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nullable LGAmount *)getValue {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getValue();
        return ::djinni::Optional<std::experimental::optional, ::djinni_generated::Amount>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (BOOL)isCoinbase {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->isCoinbase();
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nullable NSString *)getCoinbase {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getCoinbase();
        return ::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nullable NSString *)getPreviousTxHash {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getPreviousTxHash();
        return ::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nullable NSNumber *)getPreviousOutputIndex {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getPreviousOutputIndex();
        return ::djinni::Optional<std::experimental::optional, ::djinni::I32>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto BitcoinLikeInput::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto BitcoinLikeInput::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<LGBitcoinLikeInput>(cpp);
}

}  // namespace djinni_generated

@end
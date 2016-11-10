// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from wallet_pool.djinni

#import "LGWalletPool+Private.h"
#import "LGWalletPool.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#import "LGBitcoinLikeWallet+Private.h"
#import "LGBitcoinPublicKeyProvider+Private.h"
#import "LGCryptoCurrencyDescription+Private.h"
#import "LGEthereumLikeWallet+Private.h"
#import "LGEthereumPublicKeyProvider+Private.h"
#import "LGGetBitcoinLikeWalletCallback+Private.h"
#import "LGGetEthreumLikeWalletCallback+Private.h"
#import "LGLogger+Private.h"
#import "LGWalletCommonInterface+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface LGWalletPool ()

- (id)initWithCpp:(const std::shared_ptr<::ledger::core::api::WalletPool>&)cppRef;

@end

@implementation LGWalletPool {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::ledger::core::api::WalletPool>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::ledger::core::api::WalletPool>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

- (nonnull NSArray<LGWalletCommonInterface *> *)getAllWallets {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getAllWallets();
        return ::djinni::List<::djinni_generated::WalletCommonInterface>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSArray<LGBitcoinLikeWallet *> *)getAllBitcoinLikeWallets {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getAllBitcoinLikeWallets();
        return ::djinni::List<::djinni_generated::BitcoinLikeWallet>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSArray<LGEthereumLikeWallet *> *)getAllEthereumLikeWallets {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getAllEthereumLikeWallets();
        return ::djinni::List<::djinni_generated::EthereumLikeWallet>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)getOrCreateBitcoinLikeWallet:(nullable id<LGBitcoinPublicKeyProvider>)publicKeyProvider
                            currency:(nullable LGCryptoCurrencyDescription *)currency
                            callback:(nullable id<LGGetBitcoinLikeWalletCallback>)callback {
    try {
        _cppRefHandle.get()->getOrCreateBitcoinLikeWallet(::djinni_generated::BitcoinPublicKeyProvider::toCpp(publicKeyProvider),
                                                          ::djinni::Optional<std::experimental::optional, ::djinni_generated::CryptoCurrencyDescription>::toCpp(currency),
                                                          ::djinni_generated::GetBitcoinLikeWalletCallback::toCpp(callback));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)getOrCreateEthereumLikeWallet:(nullable id<LGEthereumPublicKeyProvider>)publicKeyProvider
                             currency:(nullable LGCryptoCurrencyDescription *)currency
                             callback:(nullable id<LGGetEthreumLikeWalletCallback>)callback {
    try {
        _cppRefHandle.get()->getOrCreateEthereumLikeWallet(::djinni_generated::EthereumPublicKeyProvider::toCpp(publicKeyProvider),
                                                           ::djinni::Optional<std::experimental::optional, ::djinni_generated::CryptoCurrencyDescription>::toCpp(currency),
                                                           ::djinni_generated::GetEthreumLikeWalletCallback::toCpp(callback));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSArray<LGCryptoCurrencyDescription *> *)getAllSupportedCryptoCurrencies {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getAllSupportedCryptoCurrencies();
        return ::djinni::List<::djinni_generated::CryptoCurrencyDescription>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nullable LGLogger *)getLogger {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getLogger();
        return ::djinni_generated::Logger::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)close {
    try {
        _cppRefHandle.get()->close();
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto WalletPool::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto WalletPool::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<LGWalletPool>(cpp);
}

}  // namespace djinni_generated

@end

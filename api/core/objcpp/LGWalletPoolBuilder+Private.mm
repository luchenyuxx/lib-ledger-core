// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from wallet_pool.djinni

#import "LGWalletPoolBuilder+Private.h"
#import "LGWalletPoolBuilder.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#import "LGHttpClient+Private.h"
#import "LGLogPrinter+Private.h"
#import "LGPathResolver+Private.h"
#import "LGThreadDispatcher+Private.h"
#import "LGWalletPoolBuildCallback+Private.h"
#import "LGWebSocketClient+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface LGWalletPoolBuilder ()

- (id)initWithCpp:(const std::shared_ptr<::ledger::core::api::WalletPoolBuilder>&)cppRef;

@end

@implementation LGWalletPoolBuilder {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::ledger::core::api::WalletPoolBuilder>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::ledger::core::api::WalletPoolBuilder>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

- (nullable LGWalletPoolBuilder *)setHttpClient:(nullable id<LGHttpClient>)client {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->setHttpClient(::djinni_generated::HttpClient::toCpp(client));
        return ::djinni_generated::WalletPoolBuilder::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nullable LGWalletPoolBuilder *)setWebsocketClient:(nullable id<LGWebSocketClient>)client {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->setWebsocketClient(::djinni_generated::WebSocketClient::toCpp(client));
        return ::djinni_generated::WalletPoolBuilder::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nullable LGWalletPoolBuilder *)setPathResolver:(nullable id<LGPathResolver>)pathResolver {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->setPathResolver(::djinni_generated::PathResolver::toCpp(pathResolver));
        return ::djinni_generated::WalletPoolBuilder::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nullable LGWalletPoolBuilder *)setLogPrinter:(nullable id<LGLogPrinter>)printer {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->setLogPrinter(::djinni_generated::LogPrinter::toCpp(printer));
        return ::djinni_generated::WalletPoolBuilder::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nullable LGWalletPoolBuilder *)setThreadDispatcher:(nullable id<LGThreadDispatcher>)dispatcher {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->setThreadDispatcher(::djinni_generated::ThreadDispatcher::toCpp(dispatcher));
        return ::djinni_generated::WalletPoolBuilder::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nullable LGWalletPoolBuilder *)setName:(nonnull NSString *)name {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->setName(::djinni::String::toCpp(name));
        return ::djinni_generated::WalletPoolBuilder::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)build:(nullable id<LGWalletPoolBuildCallback>)listener {
    try {
        _cppRefHandle.get()->build(::djinni_generated::WalletPoolBuildCallback::toCpp(listener));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nullable LGWalletPoolBuilder *)createInstance {
    try {
        auto objcpp_result_ = ::ledger::core::api::WalletPoolBuilder::createInstance();
        return ::djinni_generated::WalletPoolBuilder::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto WalletPoolBuilder::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto WalletPoolBuilder::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<LGWalletPoolBuilder>(cpp);
}

}  // namespace djinni_generated

@end

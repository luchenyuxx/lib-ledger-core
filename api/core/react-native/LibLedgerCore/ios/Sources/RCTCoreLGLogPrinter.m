// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from logger.djinni

#import "RCTCoreLGLogPrinter.h"


@implementation RCTCoreLGLogPrinter
//Export module
RCT_EXPORT_MODULE(RCTCoreLGLogPrinter)

-(instancetype)init
{
    self = [super init];
    //Init Objc implementation
    if(self)
    {
        self.objcImpl = [[LGLogPrinterImpl alloc] init];
    }
    return self;
}

/**
 *Print different encountered errors
 *@param message, string
 */
RCT_REMAP_METHOD(printError,printError:(nonnull NSString *)message) {

    [self.objcImpl printError:message];
}

/**
 *Print useful information messages
 *@param message, string
 */
RCT_REMAP_METHOD(printInfo,printInfo:(nonnull NSString *)message) {

    [self.objcImpl printInfo:message];
}

/**
 *Print debug messages
 *@param message string
 */
RCT_REMAP_METHOD(printDebug,printDebug:(nonnull NSString *)message) {

    [self.objcImpl printDebug:message];
}

/**
 *Print warning messages
 *@param message, string
 */
RCT_REMAP_METHOD(printWarning,printWarning:(nonnull NSString *)message) {

    [self.objcImpl printWarning:message];
}

/**
 *Print messages from APDU comand interpretation loop
 *@param message, string
 */
RCT_REMAP_METHOD(printApdu,printApdu:(nonnull NSString *)message) {

    [self.objcImpl printApdu:message];
}

/**
 *Print critical errors causing a core dump or error from which recovery is impossible
 *@param message, string
 */
RCT_REMAP_METHOD(printCriticalError,printCriticalError:(nonnull NSString *)message) {

    [self.objcImpl printCriticalError:message];
}

/**
 *Get context in which printer is executed (print)
 *@return ExecutionContext object
 */
RCT_REMAP_METHOD(getContext,getContextWithResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {

    id result = @{@"result" :[self.objcImpl getContext]};
    if(result)
    {
        resolve(result);
    }
    else
    {
        reject(@"impl_call_error", @"Error while calling LGLogPrinterImpl::getContext", nil);
    }
}
@end
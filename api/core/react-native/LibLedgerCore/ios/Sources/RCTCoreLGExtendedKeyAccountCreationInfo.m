// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from wallet.djinni

#import "RCTCoreLGExtendedKeyAccountCreationInfo.h"
#import "LGExtendedKeyAccountCreationInfo.h"

@implementation RCTCoreLGExtendedKeyAccountCreationInfo

//Export module
RCT_EXPORT_MODULE(RCTCoreLGExtendedKeyAccountCreationInfo)

@synthesize bridge = _bridge;
-(instancetype)init
{
    self = [super init];
    //Init Objc implementation
    if(self)
    {
        self.objcImplementations = [[NSMutableDictionary alloc] init];
    }
    return self;
}

+ (BOOL)requiresMainQueueSetup
{
    return NO;
}
RCT_REMAP_METHOD(init, initWithIndex:(int)index
                              owners:(nonnull NSArray<NSString *> *)owners
                         derivations:(nonnull NSArray<NSString *> *)derivations
                        extendedKeys:(nonnull NSArray<NSString *> *)extendedKeys withResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {


    LGExtendedKeyAccountCreationInfo * finalResult = [[LGExtendedKeyAccountCreationInfo alloc] initWithIndex:index owners:owners derivations:derivations extendedKeys:extendedKeys];
    NSString *uuid = [[NSUUID UUID] UUIDString];
    RCTCoreLGExtendedKeyAccountCreationInfo *rctImpl = (RCTCoreLGExtendedKeyAccountCreationInfo *)[self.bridge moduleForName:@"CoreLGExtendedKeyAccountCreationInfo"];
    [rctImpl.objcImplementations setObject:finalResult forKey:uuid];
    NSDictionary *result = @{@"type" : @"CoreLGExtendedKeyAccountCreationInfo", @"uid" : uuid };
    if (result)
    {
        resolve(result);
    }
}

RCT_REMAP_METHOD(getIndex, getIndex:(NSDictionary *)currentInstance withResolver:(RCTPromiseResolveBlock)resolve)
{
    LGExtendedKeyAccountCreationInfo *objcImpl = (LGExtendedKeyAccountCreationInfo *)[self.objcImplementations objectForKey:currentInstance[@"uid"]];
    NSDictionary *result = @{@"value" : @((int)objcImpl.index)};
    resolve(result);
}

RCT_REMAP_METHOD(getOwners, getOwners:(NSDictionary *)currentInstance withResolver:(RCTPromiseResolveBlock)resolve)
{
    LGExtendedKeyAccountCreationInfo *objcImpl = (LGExtendedKeyAccountCreationInfo *)[self.objcImplementations objectForKey:currentInstance[@"uid"]];
    NSDictionary *result = @{@"value" : objcImpl.owners};
    resolve(result);
}

RCT_REMAP_METHOD(getDerivations, getDerivations:(NSDictionary *)currentInstance withResolver:(RCTPromiseResolveBlock)resolve)
{
    LGExtendedKeyAccountCreationInfo *objcImpl = (LGExtendedKeyAccountCreationInfo *)[self.objcImplementations objectForKey:currentInstance[@"uid"]];
    NSDictionary *result = @{@"value" : objcImpl.derivations};
    resolve(result);
}

RCT_REMAP_METHOD(getExtendedKeys, getExtendedKeys:(NSDictionary *)currentInstance withResolver:(RCTPromiseResolveBlock)resolve)
{
    LGExtendedKeyAccountCreationInfo *objcImpl = (LGExtendedKeyAccountCreationInfo *)[self.objcImplementations objectForKey:currentInstance[@"uid"]];
    NSDictionary *result = @{@"value" : objcImpl.extendedKeys};
    resolve(result);
}

@end

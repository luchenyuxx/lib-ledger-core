// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from addresses.djinni

#import "RCTCoreLGBitcoinLikeNetworkParameters.h"
#import "LGBitcoinLikeNetworkParameters.h"

@implementation RCTCoreLGBitcoinLikeNetworkParameters

//Export module
RCT_EXPORT_MODULE(RCTCoreLGBitcoinLikeNetworkParameters)

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
RCT_REMAP_METHOD(init, initWithIdentifier:(nonnull NSString *)Identifier
                             P2PKHVersion:(nonnull NSData *)P2PKHVersion
                              P2SHVersion:(nonnull NSData *)P2SHVersion
                              XPUBVersion:(nonnull NSData *)XPUBVersion
                                FeePolicy:(LGBitcoinLikeFeePolicy)FeePolicy
                               DustAmount:(int)DustAmount
                            MessagePrefix:(nonnull NSString *)MessagePrefix
               UsesTimestampedTransaction:(BOOL)UsesTimestampedTransaction
                           TimestampDelay:(int)TimestampDelay
                                  SigHash:(nonnull NSData *)SigHash
                           AdditionalBIPs:(nonnull NSArray<NSString *> *)AdditionalBIPs withResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {


    LGBitcoinLikeNetworkParameters * finalResult = [[LGBitcoinLikeNetworkParameters alloc] initWithIdentifier:Identifier P2PKHVersion:P2PKHVersion P2SHVersion:P2SHVersion XPUBVersion:XPUBVersion FeePolicy:FeePolicy DustAmount:DustAmount MessagePrefix:MessagePrefix UsesTimestampedTransaction:UsesTimestampedTransaction TimestampDelay:TimestampDelay SigHash:SigHash AdditionalBIPs:AdditionalBIPs];
    NSString *uuid = [[NSUUID UUID] UUIDString];
    RCTCoreLGBitcoinLikeNetworkParameters *rctImpl = (RCTCoreLGBitcoinLikeNetworkParameters *)[self.bridge moduleForName:@"CoreLGBitcoinLikeNetworkParameters"];
    [rctImpl.objcImplementations setObject:finalResult forKey:uuid];
    NSDictionary *result = @{@"type" : @"CoreLGBitcoinLikeNetworkParameters", @"uid" : uuid };
    if (result)
    {
        resolve(result);
    }
}

RCT_REMAP_METHOD(getIdentifier, getIdentifier:(NSDictionary *)currentInstance withResolver:(RCTPromiseResolveBlock)resolve)
{
    LGBitcoinLikeNetworkParameters *objcImpl = (LGBitcoinLikeNetworkParameters *)[self.objcImplementations objectForKey:currentInstance[@"uid"]];
    NSDictionary *result = @{@"value" : objcImpl.Identifier};
    resolve(result);
}

RCT_REMAP_METHOD(getP2PKHVersion, getP2PKHVersion:(NSDictionary *)currentInstance withResolver:(RCTPromiseResolveBlock)resolve)
{
    LGBitcoinLikeNetworkParameters *objcImpl = (LGBitcoinLikeNetworkParameters *)[self.objcImplementations objectForKey:currentInstance[@"uid"]];
    NSDictionary *result = @{@"value" : objcImpl.P2PKHVersion.description};
    resolve(result);
}

RCT_REMAP_METHOD(getP2SHVersion, getP2SHVersion:(NSDictionary *)currentInstance withResolver:(RCTPromiseResolveBlock)resolve)
{
    LGBitcoinLikeNetworkParameters *objcImpl = (LGBitcoinLikeNetworkParameters *)[self.objcImplementations objectForKey:currentInstance[@"uid"]];
    NSDictionary *result = @{@"value" : objcImpl.P2SHVersion.description};
    resolve(result);
}

RCT_REMAP_METHOD(getXPUBVersion, getXPUBVersion:(NSDictionary *)currentInstance withResolver:(RCTPromiseResolveBlock)resolve)
{
    LGBitcoinLikeNetworkParameters *objcImpl = (LGBitcoinLikeNetworkParameters *)[self.objcImplementations objectForKey:currentInstance[@"uid"]];
    NSDictionary *result = @{@"value" : objcImpl.XPUBVersion.description};
    resolve(result);
}

RCT_REMAP_METHOD(getFeePolicy, getFeePolicy:(NSDictionary *)currentInstance withResolver:(RCTPromiseResolveBlock)resolve)
{
    LGBitcoinLikeNetworkParameters *objcImpl = (LGBitcoinLikeNetworkParameters *)[self.objcImplementations objectForKey:currentInstance[@"uid"]];
    NSDictionary *result = @{@"value" : @((int)objcImpl.FeePolicy)};
    resolve(result);
}

RCT_REMAP_METHOD(getDustAmount, getDustAmount:(NSDictionary *)currentInstance withResolver:(RCTPromiseResolveBlock)resolve)
{
    LGBitcoinLikeNetworkParameters *objcImpl = (LGBitcoinLikeNetworkParameters *)[self.objcImplementations objectForKey:currentInstance[@"uid"]];
    NSDictionary *result = @{@"value" : @((int)objcImpl.DustAmount)};
    resolve(result);
}

RCT_REMAP_METHOD(getMessagePrefix, getMessagePrefix:(NSDictionary *)currentInstance withResolver:(RCTPromiseResolveBlock)resolve)
{
    LGBitcoinLikeNetworkParameters *objcImpl = (LGBitcoinLikeNetworkParameters *)[self.objcImplementations objectForKey:currentInstance[@"uid"]];
    NSDictionary *result = @{@"value" : objcImpl.MessagePrefix};
    resolve(result);
}

RCT_REMAP_METHOD(getUsesTimestampedTransaction, getUsesTimestampedTransaction:(NSDictionary *)currentInstance withResolver:(RCTPromiseResolveBlock)resolve)
{
    LGBitcoinLikeNetworkParameters *objcImpl = (LGBitcoinLikeNetworkParameters *)[self.objcImplementations objectForKey:currentInstance[@"uid"]];
    NSDictionary *result = @{@"value" : @(objcImpl.UsesTimestampedTransaction)};
    resolve(result);
}

RCT_REMAP_METHOD(getTimestampDelay, getTimestampDelay:(NSDictionary *)currentInstance withResolver:(RCTPromiseResolveBlock)resolve)
{
    LGBitcoinLikeNetworkParameters *objcImpl = (LGBitcoinLikeNetworkParameters *)[self.objcImplementations objectForKey:currentInstance[@"uid"]];
    NSDictionary *result = @{@"value" : @((int)objcImpl.TimestampDelay)};
    resolve(result);
}

RCT_REMAP_METHOD(getSigHash, getSigHash:(NSDictionary *)currentInstance withResolver:(RCTPromiseResolveBlock)resolve)
{
    LGBitcoinLikeNetworkParameters *objcImpl = (LGBitcoinLikeNetworkParameters *)[self.objcImplementations objectForKey:currentInstance[@"uid"]];
    NSDictionary *result = @{@"value" : objcImpl.SigHash.description};
    resolve(result);
}

RCT_REMAP_METHOD(getAdditionalBIPs, getAdditionalBIPs:(NSDictionary *)currentInstance withResolver:(RCTPromiseResolveBlock)resolve)
{
    LGBitcoinLikeNetworkParameters *objcImpl = (LGBitcoinLikeNetworkParameters *)[self.objcImplementations objectForKey:currentInstance[@"uid"]];
    NSDictionary *result = @{@"value" : objcImpl.AdditionalBIPs};
    resolve(result);
}

@end

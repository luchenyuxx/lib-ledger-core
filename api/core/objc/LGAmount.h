// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from amount.djinni

#import "LGCryptoCurrencyUnit.h"
#import <Foundation/Foundation.h>
@class LGBigInt;
@class LGCryptoCurrencyDescription;


@interface LGAmount : NSObject

- (nullable LGBigInt *)toBigInt;

- (nonnull LGCryptoCurrencyUnit *)getUnit;

- (nullable LGCryptoCurrencyDescription *)getCryptoCurrencyDescription;

- (nonnull NSString *)toString;

@end

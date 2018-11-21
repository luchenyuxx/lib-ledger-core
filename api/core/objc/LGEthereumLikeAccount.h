// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ethereum_like_wallet.djinni

#import <Foundation/Foundation.h>
@class LGERC20LikeAccount;
@class LGEthereumLikeTransaction;
@class LGEthereumLikeTransactionBuilder;
@protocol LGStringCallback;


/**Class representing a Ethereum account */
@interface LGEthereumLikeAccount : NSObject

- (void)broadcastRawTransaction:(nonnull NSData *)transaction
                       callback:(nullable id<LGStringCallback>)callback;

- (void)broadcastTransaction:(nullable LGEthereumLikeTransaction *)transaction
                    callback:(nullable id<LGStringCallback>)callback;

- (nullable LGEthereumLikeTransactionBuilder *)buildTransaction;

- (nonnull NSArray<LGERC20LikeAccount *> *)getERC20Accounts;

@end
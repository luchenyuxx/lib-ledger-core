// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from erc20.djinni

#import "LGOperationType.h"
#import <Foundation/Foundation.h>
@class LGAmount;


/**Class representing a Ethereum transaction */
@interface LGERC20LikeOperation : NSObject

/** Get the hash of the transaction. */
- (nonnull NSString *)getHash;

/** Get the nonce of the transaction : sequence number issued by originating EOA */
- (int32_t)getNonce;

/** Get Gas price (in wei) */
- (nullable LGAmount *)getGasPrice;

/** Get start gas (in wei) : maximum amount of gas the originator is willing to pay */
- (nullable LGAmount *)getGasLimit;

/** Used gas (in wei) : used gas during this transaction */
- (nullable LGAmount *)getUsedGas;

/** Get source ETH address */
- (nonnull NSString *)getSender;

/** Get destination ETH address */
- (nonnull NSString *)getReceiver;

/** Get amount of ether to send */
- (nullable LGAmount *)getValue;

/** Get binary data payload */
- (nonnull NSData *)getData;

/**
 * Get the time when the transaction was issued or the time of the block including
 * this transaction
 */
- (nonnull NSDate *)getTime;

- (LGOperationType)getOperationType;

- (int32_t)getStatus;

@end
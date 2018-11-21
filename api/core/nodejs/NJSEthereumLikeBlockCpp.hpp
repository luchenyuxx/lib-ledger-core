// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ethereum_like_wallet.djinni

#ifndef DJINNI_GENERATED_NJSETHEREUMLIKEBLOCK_HPP
#define DJINNI_GENERATED_NJSETHEREUMLIKEBLOCK_HPP


#include <chrono>
#include <cstdint>
#include <memory>
#include <string>

#include <nan.h>
#include <node.h>
#include "../../../core/src/api/EthereumLikeBlock.hpp"

using namespace v8;
using namespace node;
using namespace std;
using namespace ledger::core::api;

class NJSEthereumLikeBlock: public Nan::ObjectWrap {
public:

    static void Initialize(Local<Object> target);
    virtual ~NJSEthereumLikeBlock() {};
    NJSEthereumLikeBlock(const std::shared_ptr<ledger::core::api::EthereumLikeBlock> &iEthereumLikeBlock):_EthereumLikeBlock(iEthereumLikeBlock){};

    static Handle<Object> wrap(const std::shared_ptr<ledger::core::api::EthereumLikeBlock> &object);
    static Nan::Persistent<ObjectTemplate> EthereumLikeBlock_prototype;
    std::shared_ptr<ledger::core::api::EthereumLikeBlock> getCppImpl(){return _EthereumLikeBlock;};

private:
    /**
     *Hash of block
     *@return string representing hash of this block
     */
    static NAN_METHOD(getHash);

    /**
     *Height of block in blockchain
     *@return 64 bits integer, height of block
     */
    static NAN_METHOD(getHeight);

    /**
     *Timestamp when block was mined
     *@return Date object, date when block was appended to blockchain
     */
    static NAN_METHOD(getTime);

    static NAN_METHOD(New);

    static NAN_METHOD(isNull);
    std::shared_ptr<ledger::core::api::EthereumLikeBlock> _EthereumLikeBlock;
};
#endif //DJINNI_GENERATED_NJSETHEREUMLIKEBLOCK_HPP
// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from erc20.djinni

#include "NJSERC20LikeAccountCpp.hpp"

using namespace v8;
using namespace node;
using namespace std;

NAN_METHOD(NJSERC20LikeAccount::getToken) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSERC20LikeAccount::getToken needs 0 arguments");
    }

    //Check if parameters have correct types

    //Unwrap current object and retrieve its Cpp Implementation
    NJSERC20LikeAccount* obj = Nan::ObjectWrap::Unwrap<NJSERC20LikeAccount>(info.This());
    auto cpp_impl = obj->getCppImpl();
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSERC20LikeAccount::getToken : implementation of ERC20LikeAccount is not valid");
    }

    auto result = cpp_impl->getToken();

    //Wrap result in node object
    auto arg_0 = Nan::New<Object>();
    auto arg_0_1 = Nan::New<String>(result.name).ToLocalChecked();
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("name").ToLocalChecked(), arg_0_1);
    auto arg_0_2 = Nan::New<String>(result.symbol).ToLocalChecked();
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("symbol").ToLocalChecked(), arg_0_2);
    auto arg_0_3 = Nan::New<String>(result.contractAddress).ToLocalChecked();
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("contractAddress").ToLocalChecked(), arg_0_3);
    auto arg_0_4 = Nan::New<Int32>(result.numberOfDecimal);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("numberOfDecimal").ToLocalChecked(), arg_0_4);


    //Return result
    info.GetReturnValue().Set(arg_0);
}
NAN_METHOD(NJSERC20LikeAccount::getAddress) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSERC20LikeAccount::getAddress needs 0 arguments");
    }

    //Check if parameters have correct types

    //Unwrap current object and retrieve its Cpp Implementation
    NJSERC20LikeAccount* obj = Nan::ObjectWrap::Unwrap<NJSERC20LikeAccount>(info.This());
    auto cpp_impl = obj->getCppImpl();
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSERC20LikeAccount::getAddress : implementation of ERC20LikeAccount is not valid");
    }

    auto result = cpp_impl->getAddress();

    //Wrap result in node object
    auto arg_0 = Nan::New<String>(result).ToLocalChecked();

    //Return result
    info.GetReturnValue().Set(arg_0);
}
NAN_METHOD(NJSERC20LikeAccount::getBalance) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSERC20LikeAccount::getBalance needs 0 arguments");
    }

    //Check if parameters have correct types

    //Unwrap current object and retrieve its Cpp Implementation
    NJSERC20LikeAccount* obj = Nan::ObjectWrap::Unwrap<NJSERC20LikeAccount>(info.This());
    auto cpp_impl = obj->getCppImpl();
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSERC20LikeAccount::getBalance : implementation of ERC20LikeAccount is not valid");
    }

    auto result = cpp_impl->getBalance();

    //Wrap result in node object
    auto arg_0_wrap = NJSBigInt::wrap(result);
    auto arg_0 = Nan::ObjectWrap::Unwrap<NJSBigInt>(arg_0_wrap)->handle();


    //Return result
    info.GetReturnValue().Set(arg_0);
}
NAN_METHOD(NJSERC20LikeAccount::getOperations) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSERC20LikeAccount::getOperations needs 0 arguments");
    }

    //Check if parameters have correct types

    //Unwrap current object and retrieve its Cpp Implementation
    NJSERC20LikeAccount* obj = Nan::ObjectWrap::Unwrap<NJSERC20LikeAccount>(info.This());
    auto cpp_impl = obj->getCppImpl();
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSERC20LikeAccount::getOperations : implementation of ERC20LikeAccount is not valid");
    }

    auto result = cpp_impl->getOperations();

    //Wrap result in node object
    Local<Array> arg_0 = Nan::New<Array>();
    for(size_t arg_0_id = 0; arg_0_id < result.size(); arg_0_id++)
    {
        auto arg_0_elem_wrap = NJSERC20LikeOperation::wrap(result[arg_0_id]);
        auto arg_0_elem = Nan::ObjectWrap::Unwrap<NJSERC20LikeOperation>(arg_0_elem_wrap)->handle();

        arg_0->Set((int)arg_0_id,arg_0_elem);
    }


    //Return result
    info.GetReturnValue().Set(arg_0);
}
NAN_METHOD(NJSERC20LikeAccount::getTransferToAddressData) {

    //Check if method called with right number of arguments
    if(info.Length() != 2)
    {
        return Nan::ThrowError("NJSERC20LikeAccount::getTransferToAddressData needs 2 arguments");
    }

    //Check if parameters have correct types
    Local<Object> njs_arg_0 = info[0]->ToObject(Nan::GetCurrentContext()).ToLocalChecked();
    NJSAmount *njs_ptr_arg_0 = static_cast<NJSAmount *>(Nan::GetInternalFieldPointer(njs_arg_0,0));
    if(!njs_ptr_arg_0)
    {
        return Nan::ThrowError("NodeJs Object to NJSAmount failed");
    }
    auto arg_0 = njs_ptr_arg_0->getCppImpl();

    String::Utf8Value string_arg_1(info[1]->ToString());
    auto arg_1 = std::string(*string_arg_1);

    //Unwrap current object and retrieve its Cpp Implementation
    NJSERC20LikeAccount* obj = Nan::ObjectWrap::Unwrap<NJSERC20LikeAccount>(info.This());
    auto cpp_impl = obj->getCppImpl();
    if(!cpp_impl)
    {
        return Nan::ThrowError("NJSERC20LikeAccount::getTransferToAddressData : implementation of ERC20LikeAccount is not valid");
    }

    auto result = cpp_impl->getTransferToAddressData(arg_0,arg_1);

    //Wrap result in node object
    Local<Array> arg_2 = Nan::New<Array>();
    for(size_t arg_2_id = 0; arg_2_id < result.size(); arg_2_id++)
    {
        auto arg_2_elem = Nan::New<Uint32>(result[arg_2_id]);
        arg_2->Set((int)arg_2_id,arg_2_elem);
    }


    //Return result
    info.GetReturnValue().Set(arg_2);
}

NAN_METHOD(NJSERC20LikeAccount::New) {
    //Only new allowed
    if(!info.IsConstructCall())
    {
        return Nan::ThrowError("NJSERC20LikeAccount function can only be called as constructor (use New)");
    }
    NJSERC20LikeAccount *node_instance = new NJSERC20LikeAccount(nullptr);

    if(node_instance)
    {
        //Wrap and return node instance
        node_instance->Wrap(info.This());
        node_instance->Ref();
        info.GetReturnValue().Set(info.This());
    }
}


Nan::Persistent<ObjectTemplate> NJSERC20LikeAccount::ERC20LikeAccount_prototype;

Handle<Object> NJSERC20LikeAccount::wrap(const std::shared_ptr<ledger::core::api::ERC20LikeAccount> &object) {
    Nan::HandleScope scope;
    Local<ObjectTemplate> local_prototype = Nan::New(ERC20LikeAccount_prototype);

    Handle<Object> obj;
    if(!local_prototype.IsEmpty())
    {
        obj = local_prototype->NewInstance();
        NJSERC20LikeAccount *new_obj = new NJSERC20LikeAccount(object);
        if(new_obj)
        {
            new_obj->Wrap(obj);
            new_obj->Ref();
        }
    }
    else
    {
        Nan::ThrowError("NJSERC20LikeAccount::wrap: object template not valid");
    }
    return obj;
}

NAN_METHOD(NJSERC20LikeAccount::isNull) {
    NJSERC20LikeAccount* obj = Nan::ObjectWrap::Unwrap<NJSERC20LikeAccount>(info.This());
    auto cpp_implementation = obj->getCppImpl();
    auto isNull = !cpp_implementation ? true : false;
    return info.GetReturnValue().Set(Nan::New<Boolean>(isNull));
}

void NJSERC20LikeAccount::Initialize(Local<Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> func_template = Nan::New<FunctionTemplate>(NJSERC20LikeAccount::New);
    Local<ObjectTemplate> objectTemplate = func_template->InstanceTemplate();
    objectTemplate->SetInternalFieldCount(1);

    func_template->SetClassName(Nan::New<String>("NJSERC20LikeAccount").ToLocalChecked());

    //SetPrototypeMethod all methods
    Nan::SetPrototypeMethod(func_template,"getToken", getToken);
    Nan::SetPrototypeMethod(func_template,"getAddress", getAddress);
    Nan::SetPrototypeMethod(func_template,"getBalance", getBalance);
    Nan::SetPrototypeMethod(func_template,"getOperations", getOperations);
    Nan::SetPrototypeMethod(func_template,"getTransferToAddressData", getTransferToAddressData);
    //Set object prototype
    ERC20LikeAccount_prototype.Reset(objectTemplate);
    Nan::SetPrototypeMethod(func_template,"isNull", isNull);

    //Add template to target
    target->Set(Nan::New<String>("NJSERC20LikeAccount").ToLocalChecked(), func_template->GetFunction());
}

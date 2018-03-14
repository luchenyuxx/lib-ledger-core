// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from core.djinni

#include "NJSLedgerCoreCpp.hpp"

using namespace v8;
using namespace node;
using namespace std;

NAN_METHOD(NJSLedgerCore::getStringVersion) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSLedgerCore::getStringVersion needs 0 arguments");
    }

    //Check if parameters have correct types

    auto result = LedgerCore::getStringVersion();

    //Wrap result in node object
    auto arg_0 = Nan::New<String>(result).ToLocalChecked();

    //Return result
    info.GetReturnValue().Set(arg_0);
}
NAN_METHOD(NJSLedgerCore::getIntVersion) {

    //Check if method called with right number of arguments
    if(info.Length() != 0)
    {
        return Nan::ThrowError("NJSLedgerCore::getIntVersion needs 0 arguments");
    }

    //Check if parameters have correct types

    auto result = LedgerCore::getIntVersion();

    //Wrap result in node object
    auto arg_0 = Nan::New<Int32>(result);

    //Return result
    info.GetReturnValue().Set(arg_0);
}

NAN_METHOD(NJSLedgerCore::New) {
    //Only new allowed
    if(!info.IsConstructCall())
    {
        return Nan::ThrowError("NJSLedgerCore function can only be called as constructor (use New)");
    }
    NJSLedgerCore *node_instance = new NJSLedgerCore(nullptr);

    if(node_instance)
    {
        //Wrap and return node instance
        node_instance->Wrap(info.This());
        node_instance->Ref();
        info.GetReturnValue().Set(info.This());
    }
}


Nan::Persistent<ObjectTemplate> NJSLedgerCore::LedgerCore_prototype;

Handle<Object> NJSLedgerCore::wrap(const std::shared_ptr<ledger::core::api::LedgerCore> &object) {
    Nan::HandleScope scope;
    Local<ObjectTemplate> local_prototype = Nan::New(LedgerCore_prototype);

    Handle<Object> obj;
    if(!local_prototype.IsEmpty())
    {
        obj = local_prototype->NewInstance();
        NJSLedgerCore *new_obj = new NJSLedgerCore(object);
        if(new_obj)
        {
            new_obj->Wrap(obj);
            new_obj->Ref();
        }
    }
    else
    {
        Nan::ThrowError("NJSLedgerCore::wrap: object template not valid");
    }
    return obj;
}

void NJSLedgerCore::Initialize(Local<Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> func_template = Nan::New<FunctionTemplate>(NJSLedgerCore::New);
    Local<ObjectTemplate> objectTemplate = func_template->InstanceTemplate();
    objectTemplate->SetInternalFieldCount(1);

    func_template->SetClassName(Nan::New<String>("NJSLedgerCore").ToLocalChecked());

    //SetPrototypeMethod all methods
    Nan::SetPrototypeMethod(func_template,"getStringVersion", getStringVersion);
    Nan::SetPrototypeMethod(func_template,"getIntVersion", getIntVersion);
    //Set object prototype
    LedgerCore_prototype.Reset(objectTemplate);

    //Add template to target
    target->Set(Nan::New<String>("NJSLedgerCore").ToLocalChecked(), func_template->GetFunction());
}
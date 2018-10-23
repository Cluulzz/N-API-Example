//#ifndef NATIVE_EXTENSION_GRAB_H
//#define NATIVE_EXTENSION_GRAB_H

#include <node_api.h>
#include <string>
#include <iostream>
#define ENUM_TO_STR(ENUM) std::string(#ENUM)
// Example top-level functions. These functions demonstrate how to return various js types.
// Implementations are in functions.cc
//
//NAN_METHOD(nothing);
//NAN_METHOD(aString);
//NAN_METHOD(aBoolean);
//NAN_METHOD(aNumber);
//NAN_METHOD(anObject);
//NAN_METHOD(anArray);
//NAN_METHOD(callback);
//NAN_METHOD(callbackWithParameter);

// Example with node ObjectWrap
// Based on https://nodejs.org/api/addons.html#addons_wrapping_c_objects but using NAN
napi_value Init(napi_env env, napi_value exports, napi_value module, void* priv);
napi_value calculate(napi_env env, napi_callback_info info);
//#endif

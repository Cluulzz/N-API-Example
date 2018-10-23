#include "include/main.h"
float Q_rsqrt( float number )
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;
    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;                       // evil floating point bit level hacking（对浮点数的邪恶位元hack）
    i  = 0x5f3759df - ( i >> 1 );               // what the fuck?（这他妈的是怎么回事？）
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration （第一次迭代）
//      y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed（第二次迭代，可以删除）
    return 1 / y;
}


void is_ok(napi_env env,napi_status status){
    if(status != napi_ok)
    {
        napi_value result = nullptr;
        const char* str = "error";
        napi_create_string_utf8(env,str,NAPI_AUTO_LENGTH,&result);
        napi_throw(env,result);
    }
}

napi_value calculate(napi_env env, napi_callback_info info){
    napi_status status;

    size_t argc = 1;
    napi_value argv[1];
    status = napi_get_cb_info(env, info, &argc, argv, 0, 0);
    is_ok(env,status);
    double d_arg;
    napi_value arg0 = argv[0];
    status = napi_get_value_double(env,arg0,&d_arg);
    is_ok(env,status);
    float value  = Q_rsqrt((float) d_arg);
    napi_value result = nullptr;
    status = napi_create_double(env,(double) value,&result);
    is_ok(env,status);
    return result;
}

napi_value Init(napi_env env, napi_value exports){
    napi_status status;

    // 用于设置 exports 对象的描述结构体
    napi_property_descriptor desc =
            { "calculate", 0, calculate, 0, 0, 0, napi_default, 0 };

    // 把 "echo" 设置到 exports 去
    status = napi_define_properties(env, exports, 1, &desc);
    if (status != napi_ok) return NULL;
    return exports;
}
NAPI_MODULE(main,Init);
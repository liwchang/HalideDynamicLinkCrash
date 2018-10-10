//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. 
//

#pragma once
#include "SafeHalide.h"
#include "FunctionExternal.h"

#define EXTERNAL_TEST

inline Halide::Func HelloWorld(
    const Halide::Func& input,
    int size)
{
    Halide::Func result("ResultHelloWorld");

#ifdef EXTERNAL_TEST
    std::vector<Halide::ExternFuncArgument> args(2);
    args[0] = input;
    args[1] = size;
    result.define_extern("ExternalHelloWorld", args, Halide::Float(32), 1);
    result.bound_extent(result.args()[0], size);
 
#else
    Halide::Var x;
    result(x) = input(x) + 1.0f;
	result.bound_extent(x, size);
#endif
    result.compute_root();
    return result;
}

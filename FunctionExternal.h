//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. 
//

#pragma once
#include "SafeHalide.h"

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

extern "C" DLLEXPORT int ExternalHelloWorld(halide_buffer_t * input, int size, halide_buffer_t * output);



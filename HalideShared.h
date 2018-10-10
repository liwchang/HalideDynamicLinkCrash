//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. 
//

#pragma once
#include "SafeHalide.h"
#include "InterfaceExternal.h"

class HalideShared
{

public:
    HalideShared() {};

    DLLEXPORT void Run() {

        int size = 1024;
        Halide::Pipeline pipeline;
        Halide::ImageParam input(Halide::type_of<float>(), 1);

        auto func = HelloWorld(input, size);
        pipeline = Halide::Pipeline({ func });
        pipeline.compile_jit();


        Halide::Buffer<float> inBuffer(size);
        Halide::Buffer<float> outBuffer(size);

        for (int i = 0; i < size; i++)
            inBuffer.data()[i] = (float)i;
        input.set(inBuffer);

        printf("Before realization\n");
        pipeline.realize(outBuffer);
    }

};

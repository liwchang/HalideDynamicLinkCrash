//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. 
//
#include "FunctionExternal.h"

int ExternalHelloWorld(halide_buffer_t * input, int size, halide_buffer_t * output) {
    printf("hello world\n");
    int minIdx = output->dim[0].min;
    int extent = output->dim[0].extent;
    // Handle out of bound access cases
    if (input->host == nullptr)
    {
        if (input->is_bounds_query()) {
            input->dim[0].min = 0;
            input->dim[0].extent = size;
        }
        return 0;
    }

    float* in = (float*)input->host;
    float* out = (float*)output->host;

    for (int i = 0; i < extent; ++i)
    {
        out[i] = in[i]+1.0f;
    }

    return 1;
}

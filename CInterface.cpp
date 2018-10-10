//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. 
//
#include "CInterface.h"
#include "HalideShared.h"

void C_Run()
{
    printf("C_Run\n");
    HalideShared* test = new HalideShared();
    test->Run();
}
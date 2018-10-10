//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. 
//

#include <stdio.h>
#include <assert.h> 
#include "CInterface.h"
#include <dlfcn.h>

typedef decltype(&C_Run) CRunFunction;

int main()
{
    void * dllHandle;
    printf("Load object\n");
    dllHandle = dlopen("halideShared.so", RTLD_LAZY);
    if (!dllHandle)
    {
        printf("dlopen Failed: %s\n", dlerror());
    }

    printf("Load function\n");
    CRunFunction functionPtr = (CRunFunction) dlsym(dllHandle, "C_Run");
    assert(functionPtr != nullptr);

    printf("Run Function\n");
    functionPtr();
	return 0;
}




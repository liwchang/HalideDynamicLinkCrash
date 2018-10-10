//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. 
//

#ifdef _WIN32
#define C_INFERENCE_API __declspec(dllexport)
#else
#define C_INFERENCE_API
#endif

#include <cstddef>
#include <string>

#ifdef __cplusplus
extern "C"
{
#endif

C_INFERENCE_API void C_Run();

#ifdef __cplusplus
}
#endif
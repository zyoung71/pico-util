#pragma once

#ifdef __cplusplus
#define restrict __restrict

extern "C" {
#endif

#ifdef DEBUG
#define LOG(...) printf(...)
#else
#define LOG(...)
#endif

#ifdef __cplusplus
}
#endif
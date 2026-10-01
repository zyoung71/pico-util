#pragma once

#ifdef __cplusplus
#define restrict __restrict

#if __cplusplus >= 202002L
// c++20 features
#else
// c++<20 workarounds
#define consteval constexpr
#endif

#if __cplusplus >= 201703L
#define NODISCARD [[nodiscard]]
#else
#define NODISCARD
#endif

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
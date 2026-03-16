#pragma once

#include <cstddef>

template<typename Return, typename... Args>
using Function = Return (*)(Args...);

template<typename Return, class Class, typename... Args>
using MemberFunction = Return (Class::*)(Args...);

template<typename T, size_t N>
struct _MultiPtrIntermediate
{
    using type = typename _MultiPtrIntermediate<T, N - 1>::type*;
};

template<typename T>
struct _MultiPtrIntermediate<T, 0>
{
    using type = T;
};

template<typename T, size_t N>
using MultiPtr = typename _MultiPtrIntermediate<T, N>::type;
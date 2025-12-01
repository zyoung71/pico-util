#pragma once

#include <cstddef>

template<typename T>
struct ArrayAccessor
{
    T* data;
    size_t length;
};
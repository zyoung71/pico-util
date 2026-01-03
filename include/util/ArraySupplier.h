#pragma once

#include <array>
#include <cstddef>

template<typename T, size_t arr_size>
class ArraySupplier
{
protected:
    std::array<T, arr_size> array;

public:
    inline T& operator[](size_t index)
    {
        index = index >= arr_size ? arr_size - 1 : index;
        return array[index];
    }
    inline const T& operator[](size_t index) const
    {
        index = index >= arr_size ? arr_size - 1 : index;
        return array[index];
    }
};
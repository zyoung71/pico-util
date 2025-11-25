#pragma once

#include <memory>

template<typename T>
struct UniqueArray
{
    std::unique_ptr<T[]> array;
    size_t length;
    inline constexpr T& operator[](size_t get) const
    {
        return array[get];
    }
};
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

template<typename T, size_t l>
inline constexpr UniqueArray<T> make_unique_array(T (arr)[l])
{
    return UniqueArray<T>{
        std::make_unique<T[]>(arr),
        len
    };
}

template<typename T>
inline constexpr UniqueArray<T> make_unique_array(std::unique_ptr<T[]>& arr, size_t len)
{
    return UniqueArray<T>{
        std::move(arr),
        len
    };
}
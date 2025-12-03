#pragma once

#include <memory>

template<typename T>
struct UniqueArray
{
    std::unique_ptr<T[]> array;
    size_t length;

    inline constexpr const T& operator[](size_t get) const
    {
        return array[get];
    }
    inline constexpr T& operator[](size_t get)
    {
        return array[get];
    }

    inline constexpr UniqueArray() : array(nullptr), length(0) {}
    inline constexpr UniqueArray(nullptr_t) : UniqueArray() {}
    inline constexpr UniqueArray(UniqueArray&& mov) : array(std::move(mov.array)), length(mov.length) {}
};

template<typename T, size_t len>
inline constexpr UniqueArray<T> make_unique_array(T (arr)[len])
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

template<typename T>
inline constexpr UniqueArray<T> make_unique_array_empty(size_t len)
{   
    return UniqueArray<T>{
        std::make_unique<T[]>(len),
        len
    };
}
#pragma once

#include <cstddef>

/**
 * Similar to ArrayView, but without the accessors.
 * Ideal for throwing large sets of data into one compact
 * viewer to be used elsewhere such as read and write HALs.
 */
template<typename T>
struct BufferView
{
    const T* buffer;
    size_t length;

    inline constexpr size_t Size() const
    {
        return length;
    }
};

template<typename T>
struct BufferView2D
{
    const T* buffer;
    size_t rows, cols;
};

template<typename T>
struct BufferView3D
{
    const T* buffer;
    size_t rows, cols, depth;
};

template<typename T, size_t l>
inline constexpr BufferView<T> make_buffer_view(const T (&buffer)[l])
{
    return BufferView<T>{
        &buffer[0],
        l
    };
}

template<typename T>
inline constexpr BufferView<T> make_buffer_view(const T* buffer, size_t len)
{
    return BufferView<T>{
        buffer,
        len
    };
}

template<typename T, size_t r, size_t c>
inline constexpr BufferView2D<T> make_buffer_view(const T (&buffer)[r][c])
{
    return BufferView2D<T>{
        &buffer[0][0],
        r, c
    };
}

template<typename T>
inline constexpr BufferView2D<T> make_buffer_view(const T* buffer, size_t r, size_t c)
{
    return BufferView2D<T>{
        buffer, 
        r, c
    };
}

template<typename T, size_t r, size_t c, size_t d>
inline constexpr BufferView3D<T> make_buffer_view(const T (&buffer)[r][c][d])
{
    return BufferView3D<T>{
        &buffer[0][0][0],
        r, c, d
    };
}

template<typename T>
inline constexpr BufferView3D<T> make_buffer_view(const T* buffer, size_t r, size_t c, size_t d)
{
    return BufferView3D<T>{
        buffer,
        r, c, d
    };
}
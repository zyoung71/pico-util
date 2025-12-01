#pragma once

#include <cstddef>
/**
 * WIP
 */
class StringLite
{
private:
    char* buffer;
    size_t str_size;
    size_t buff_size;

public:
    StringLite(const char* str);
    explicit StringLite(size_t size);
    StringLite(const StringLite& copy);
    StringLite(StringLite&& move);
    StringLite& operator=(const char* str);
    StringLite& operator=(const StringLite& other);

    void Resize(size_t new_size);
    StringLite& operator+=(const char* str);
    StringLite& operator+=(const StringLite& other);

    StringLite operator+(char c) const;
    StringLite operator+(const char* str) const;
    StringLite operator+(const StringLite& other) const;

    inline size_t Length() const
    {
        return str_size;
    }

    inline const char* Raw() const
    {
        return buffer;
    }

    inline char operator[](size_t index) const
    {
        index = index >= str_size ? str_size - 1 : index;
        return buffer[index];
    }

    inline char& operator[](size_t index)
    {
        index = index >= str_size ? str_size - 1 : index;
        return buffer[index];
    }

    ~StringLite();

};

StringLite operator+(char c, const StringLite& self);
StringLite operator+(const char* str, const StringLite& self);
StringLite operator+(const StringLite& other, const StringLite& self);
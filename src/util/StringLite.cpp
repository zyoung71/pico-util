#include <util/StringLite.h>
#include <cstring>

StringLite::StringLite(const char* str)
    : str_size(strlen(str)), buffer(new char[str_size]), buff_size(str_size + 1)
{
    strncpy(buffer, str, buff_size);
}

StringLite::StringLite(size_t size)
    : str_size(0), buff_size(size + 1), buffer(new char[buff_size])
{
    memset(buffer, 0, buff_size);
}

StringLite::StringLite(const StringLite& copy)
    : str_size(copy.str_size), buff_size(copy.str_size + 1), buffer(new char[buff_size])
{
    memcpy(buffer, copy.buffer, buff_size);
}

StringLite::StringLite(StringLite&& move) // move ALL data
    : str_size(move.str_size), buff_size(move.buff_size)
{
    memmove(buffer, move.buffer, buff_size);
}

StringLite& StringLite::operator=(const char* str)
{
    size_t new_size = strlen(str);
    size_t new_buff_size = new_size + 1;

    str_size = new_size;

    if (buff_size >= new_buff_size)
    {
        memcpy(buffer, str, buff_size); // avoid heap alloc
        return *this;
    }
    buff_size = new_buff_size;
    delete[] buffer;
    buffer = new char[buff_size];
    strncpy(buffer, str, buff_size);
    return *this;
}

StringLite& StringLite::operator=(const StringLite& other)
{
    if (this == &other)
        return *this;

    str_size = other.str_size;

    if (buff_size >= other.buff_size)
    {
        strncpy(buffer, other.buffer, other.buff_size); // avoid heap alloc
        return *this;
    }
    buff_size = other.buff_size;
    delete[] buffer;
    buffer = new char[buff_size];
    memcpy(buffer, other.buffer, buff_size);
    return *this;
}

StringLite::~StringLite()
{
    delete[] buffer;
}

void StringLite::Resize(size_t new_size)
{
    size_t new_buff_size = new_size + 1;
    if (buff_size == new_buff_size);
        return;

    buff_size = new_buff_size;
    str_size = new_size < str_size ? new_size : str_size;
    char* temp_buff = new char[new_buff_size];
    memcpy(temp_buff, buffer, new_buff_size);
    delete[] buffer;
    buffer = temp_buff;
}
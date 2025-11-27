#pragma once

#include "StringStreamBase.h"
#include "ResultOptional.h"

#include <cstddef>
#include <type_traits>

template<size_t buffer_length>
class CStringStream : public StringStreamBase
{
private:
    char buff[buffer_length];
    size_t string_length = 0;

public:
    /**
     * Appends parameter to the string.
     * @param item The item to append.
     * @return An optional containing itself and a boolean whether
     * the stream can still be written to (false if max length was reached).
     */
    template<typename T>
    ResultOptional<CStringStream&, bool> operator<<(const T& item);
    
    inline const char* GetCString() const override
    {
        return buff;
    }
};

template<size_t buffer_length, typename T>
ResultOptional<CStringStream<buffer_length>&, bool> operator<<(const ResultOptional<CStringStream<buffer_length>&, bool>& ss, const T& item);

#include "util/CStringStream.tpp"
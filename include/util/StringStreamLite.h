#pragma once

#include "StringStreamBase.h"

#include <string>

/**
 * Creates a string very similar to how std::stringstream works...
 * but won't inflate the binary size more than Venezuelan currency. 
 */
class StringStreamLite : public StringStreamBase
{
private:
    std::string current_stream;

public:
    template<typename T>
    StringStreamLite& operator<<(const T& item);

    inline const std::string& GetString() const
    {
        return current_stream;
    }

    inline const char* GetCString() const override
    {
        return current_stream.c_str();
    }
};

#include "util/StringStreamLite.tpp"
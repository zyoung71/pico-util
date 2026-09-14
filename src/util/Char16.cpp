#include <util/Char16.h>

size_t strlen16(const char16_t* strarg)
{
    const char16_t* str = strarg;
    for (; *str; ++str)
        ; // empty
    return str - strarg;
}
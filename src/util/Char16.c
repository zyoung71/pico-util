#include <string.h>
#include <util/Char16.h>

size_t strlen16(const char16_t* strarg)
{
    const char16_t* str = strarg;
    for (; *str; ++str)
        ; // empty
    return str - strarg;
}

char16_t* strcpy16(char16_t* restrict dest, const char16_t* restrict src)
{
    char16_t* begin = dest;
    while ((*dest++ = *src++))
        ;
    return begin;
}
char16_t* strncpy16(char16_t* restrict dest, const char16_t* restrict src, size_t n)
{
    if (n == 0)
        return dest;

    size_t len = 0;
    while (len < n - 1 && src[len] != u'\0')
    {
        len++;
    }

    memcpy(dest, src, len * sizeof(char16_t));
    dest[len] = u'\0';

    return dest;
}
size_t strlcpy16(char16_t* restrict dest, const char16_t* restrict src, size_t n)
{
    if (n == 0)
        return 0;

    const char16_t* end = src;
    while (*end)
        ++end;

    size_t src_len = end - src;
    size_t cpy_len = src_len >= n ? (n - 1) : src_len;
    
    if (cpy_len > 0)
        memcpy(dest, src, cpy_len * sizeof(char16_t));

    dest[cpy_len] = u'\0';

    return src_len;
}
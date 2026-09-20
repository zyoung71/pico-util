#include <util/Chars.h>
#include <string.h>

char32_t utf8_decode(const char* restrict text, size_t* restrict bytes_used)
{
    const uint8_t* str = (const uint8_t*)text;
    
    if (str[0] < 0x80)
    {
        // ascii
        *bytes_used = 1;
        return str[0];
    }

    uint32_t codepoint;
    
    if ((str[0] & 0xE0) == 0xC0)
    {
        // 2 bytes
        codepoint = ((uint32_t)(str[0] & 0x1F) << 6) | (uint32_t)(str[1] & 0x3F);

        *bytes_used = 2;
        return (char32_t)codepoint;
    }

    if ((str[0] & 0xF0) == 0xE0)
    {
        // 3 bytes
        codepoint = ((uint32_t)(str[0] & 0x0F) << 12) | ((uint32_t)(str[1] & 0x3F) << 6) | (uint32_t)(str[2] & 0x3F);
        
        *bytes_used = 3;
        return (char32_t)codepoint;
    }

    if ((str[0] & 0xF8) == 0xF0)
    {
        // 4 bytes
        codepoint = ((uint32_t)(str[0] & 0x07) << 18) | ((uint32_t)(str[1] & 0x3F) << 12) | ((uint32_t)(str[2] & 0x3F) << 6) | (uint32_t)(str[3] & 0x3F);
        
        *bytes_used = 4;
        return (char32_t)codepoint;
    }

    // unknown
    *bytes_used = 1;
    return 0xFFFD;
}

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
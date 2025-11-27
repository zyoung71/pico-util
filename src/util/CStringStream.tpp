#include <util/CStringStream.h>

#include <cstring>

template<size_t buffer_length>
template<typename T>
ResultOptional<CStringStream<buffer_length>&, bool> CStringStream<buffer_length>::operator<<(const T& item)
{
    int result;
    if constexpr (std::is_same_v<std::remove_const_t<T>, char*>)
        result = snprintf(buff + string_length, buffer_length - string_length, "%s", item);
    else if constexpr (std::is_same_v<T, char>)
        result = snprintf(buff + string_length, buffer_length - string_length, "%c", item);
    else if constexpr (std::is_same_v<T, uint64_t>)
        result = snprintf(buff + string_length, buffer_length - string_length, "%llu", item);
    else if constexpr (std::is_unsigned_v<T>)
        result = snprintf(buff + string_length, buffer_length - string_length, "%u", item);
    else if constexpr (std::is_integral_v<T>)
        result = snprintf(buff + string_length, buffer_length - string_length, "%d", item);
    else if constexpr (std::is_floating_point_v<T>)
        result = snprintf(buff + string_length, buffer_length - string_length, "%f", item);
    else
        result = snprintf(buff + string_length, buffer_length - string_length, "%s", item);

    string_length = strlen(buff);
    if (string_length >= buffer_length - 1)
    {
        return ResultOptional<CStringStream&, bool>(*this, false);
    }
    return ResultOptional<CStringStream&, bool>(*this, true);
}

template<size_t buffer_length, typename T>
ResultOptional<CStringStream<buffer_length>&, bool> operator<<(const ResultOptional<CStringStream<buffer_length>&, bool>& ss, const T& item)
{
    return ss.main << item;
}
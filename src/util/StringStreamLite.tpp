#include <util/StringStreamLite.h>

template<typename T>
StringStreamLite& StringStreamLite::operator<<(const T& item)
{
    if constexpr (std::is_integral_v<T> || 
        std::is_floating_point_v<T> ||
        std::is_pointer_v<T> ||
        std::is_unsigned_v<T>
    )
        current_stream += std::to_string(item);
    else
        current_stream += item;

    return *this;
}
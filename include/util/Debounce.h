#pragma once

#include <pico/time.h>

class Debounce
{
private:
    absolute_time_t begin;
    const absolute_time_t pause_us;
public:
    inline Debounce(uint32_t pause_ms)
        : pause_us(pause_ms * 1000ULL), begin(to_us_since_boot(get_absolute_time())) {}

    inline bool Allow()
    {
        absolute_time_t now = to_us_since_boot(get_absolute_time());
        if (now - begin >= pause_us)
        {
            begin = now;
            return true;
        }
        return false;
    }

};
#pragma once

#include <pico/time.h>

struct TimeHandler
{
    const absolute_time_t created_us;
    absolute_time_t then_us;
    absolute_time_t now_us;
    absolute_time_t delta_us;

    inline TimeHandler()
        : created_us(to_us_since_boot(get_absolute_time())), then_us(0), now_us(0), delta_us(0) {}

    // Returns the delta time in microseconds
    absolute_time_t Update();

    inline uint32_t GetDeltaTimeMilliseconds() const
    {
        return delta_us / 1000;
    }

    inline float GetDeltaTimeSeconds() const
    {
        return (float)delta_us * 1e-6f;
    }

};
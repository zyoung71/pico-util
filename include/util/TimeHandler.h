#pragma once

#include <pico/time.h>

struct TimeHandler
{
private:
    absolute_time_t created_us;

public:
    absolute_time_t now_us;
    absolute_time_t delta_us;

    inline TimeHandler()
        : created_us(to_us_since_boot(get_absolute_time())), now_us(0), delta_us(0) {}

    inline TimeHandler& operator=(const TimeHandler& other)
    {
        created_us = other.created_us;
        now_us = other.now_us;
        delta_us = other.delta_us;
        return *this;
    }

    // Returns the delta time in microseconds
    absolute_time_t Update();

    inline absolute_time_t GetGlobalTimeWhenCreated() const
    {
        return created_us;
    }
    inline uint32_t GetDeltaTimeMilliseconds() const
    {
        return delta_us / 1000;
    }
    inline float GetDeltaTimeSeconds() const
    {
        return (float)delta_us * 1e-6f;
    }

};
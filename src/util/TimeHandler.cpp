#include <util/TimeHandler.h>

absolute_time_t TimeHandler::Update()
{
    static absolute_time_t then_us = 0;
    now_us = to_us_since_boot(get_absolute_time());
    delta_us = now_us - then_us;
    then_us = now_us;
    return delta_us;
}
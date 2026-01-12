#include <util/TimeHandler.h>

absolute_time_t TimeHandler::Update()
{
    now_us = to_us_since_boot(get_absolute_time());
    delta_us = now_us - then_us;
    then_us = now_us;
    return delta_us;
}
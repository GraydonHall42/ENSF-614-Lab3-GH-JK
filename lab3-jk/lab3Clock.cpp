//  lab3Clock.cpp
// ENSF 614 Fall 2021 LAB 3 - EXERCISE C

#include "lab3Clock.h"

Clock::Clock(int h, int min, int sec)
{
    if (sec < 0 || sec > 59 || min < 0 || min > 59 || h < 0 || h > 23)
    {
        second = 0;
        minute = 0;
        hour = 0;
    }
    else
    {
        second = sec;
        minute = min;
        hour = h;
    }
}

Clock::Clock(int sec)
{
    if (sec < 0)
    {
        sec_to_hms(0);
    }
    else
    {
        sec_to_hms(sec);
    }
}

int Clock::get_second() const
{
    return second;
}

int Clock::get_minute() const
{
    return minute;
}

int Clock::get_hour() const
{
    return hour;
}

void Clock::set_second(int arg)
{
    if (arg > 59 || arg < 0)
    {
        return;
    }
    else
    {
        second = arg;
    }
}

void Clock::set_minute(int arg)
{
    if (arg > 59 || arg < 0)
    {
        return;
    }
    else
    {
        minute = arg;
    }
}

void Clock::set_hour(int arg)
{
    if (arg > 23 || arg < 0)
    {
        return;
    }
    else
    {
        hour = arg;
    }
}

void Clock::increment()
{
    sec_to_hms(hms_to_sec() + 1);
}

void Clock::decrement()
{
    sec_to_hms(hms_to_sec() - 1);
}

void Clock::add_seconds(int arg)
{
    sec_to_hms(hms_to_sec() + arg);
}

int Clock::hms_to_sec()
{
    return second + (minute * 60) + (hour * 3600);
}

void Clock::sec_to_hms(int arg)
{
    while (arg < -86399)
    {
        arg = arg + 86400;
    }
    while (arg > 86399)
    {
        arg = arg - 86400;
    }
    if (arg < 0)
    {
        arg = 86400 + arg;
    }

    set_second(arg % 60);
    set_minute(arg / 60 % 60);
    set_hour(arg / 60 / 60);
}
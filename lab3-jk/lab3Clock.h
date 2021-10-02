// lab3Clock.h
// ENSF 614 Fall 2021 LAB 3 - EXERCISE C

#ifndef lab3_exe_C_Clock
#define lab3_exe_C_Clock
/* The following class definition represnets Complex Numbers and contains two
 * private data members called realM (the real part of a complex number),
 * and imagM (the imaginary part of a complex number).
 */

class Clock
{
public:
    Clock(int h, int min, int sec);

    Clock(int sec = 0);

    int get_second() const;

    int get_minute() const;

    int get_hour() const;

    void set_second(int arg);

    void set_minute(int arg);

    void set_hour(int arg);

    void increment();

    void decrement();

    void add_seconds(int arg);

private:
    int second;
    int minute;
    int hour;

    int hms_to_sec();

    void sec_to_hms(int arg);
};

#endif
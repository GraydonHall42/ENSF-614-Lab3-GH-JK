#ifndef lab3_exe_C_Clock
#define lab3_exe_C_Clock
/* This class definition represents a clock that shows hours, 
* Minutes, and Seconds.
*/

class Clock{
    public:
        Clock();
        // PROMISES: initializes the values of hours, minutes, and seconds, all to 0

        Clock(int seconds); 
        //PROMISES: receives integer argument in seconds, uses it to set clock time in 
        // hours, minutes, and seconds

        Clock(int hour, int minute, int second);  
        // PROMIESES: initializes hours, minutes, and seconds for clock based on user provided arguments

        int get_hour () const;
        // PROMISES: return hour value for clock

        int get_minute () const;
        // PROMISES: return minute value for clock

        int get_second () const;
        // PROMISES: return second value for clock

        void set_hour (int arg);
        // PROMISES: set a new value for hour with the value of arg

        void set_minute (int arg);
        // PROMISES: set a new value for minute with the value of arg

        void set_second (int arg);
        // PROMISES: set a new value for second with the value of arg

        void incremenet ();
        // PROMISES: increments the value of the clock’s time by one second. 

        void decrement ();
        // PROMISES: decrements the value of the clock’s time by one second. 

        void add_seconds (int second);
        // PROMISES: adds the value of given seconds to the value of the current time
        // REQUIRES: a positive integer argument in seconds


        
    private:
        int hour; // hours on the clock
        int minute;  // minutes on the clock
        int second;  // seconds on the clock

        int hms_to_sec(); 
        // PROMISES: returns the total value of data members in a Clock object, 
        // in seconds. 

        void sec_to_hms(int n);
        // PROMISES:  receives an argument n in seconds, and sets the values 
        // for the Clock data members, second, minute, and hour, based on this argument. 
        

        
}; 

#endif
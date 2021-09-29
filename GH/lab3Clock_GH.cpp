// from  lab3exe_C.cpp
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;
using std::setfill;


#include "lab3Clock_GH.h"

void print(const Clock& t);


// Start GH Code
Clock::Clock(){
    hour=0;
    minute=0;
    second=0;
}

Clock::Clock(int seconds)
{   
    // set values for hour minute second based on seconds argument
    sec_to_hms(seconds);
} 


Clock::Clock(int hours, int minutes, int seconds)
{
    if(hours < 0 || hours > 23 || minutes < 0 
    || minutes > 59 || seconds < 0 || seconds > 59){
        hour=0;
        minute=0;
        second=0;
    }
    else {
        hour = hours;
        minute = minutes;
        second = seconds;
    }
}

int Clock::get_hour () const {
    return hour;
}
        
int Clock::get_minute () const {
    return minute;
}


int Clock::get_second () const {
    return second;
}

void Clock::set_hour (int arg){
    if(arg>=0 && arg <=23){
        hour=arg;
    }
}

void Clock::set_minute (int arg){
    if(arg>=0 && arg <=59){
        minute=arg;
    }
}

void Clock::set_second (int arg){
    if(arg>=0 && arg <=59){
        second=arg;
    }
}

void Clock::increment (){
    if(second==59){
        if(minute==59){
            if(hour==23){
                hour=0;
                minute=0;
                second=0;
            }else{
                hour++;
                minute=0;
                second=0;
            }
        }else{
            minute++;
            second=0;
        }

    } else{
        second++;
    }
}

void Clock::decrement (){
    if(second==0){
        if(minute==0){
            if(hour==0){
                hour=23;
                minute=59;
                second=59;
            }else{
                hour--;
                minute=59;
                second=59;
            }
        }else{
            minute--;
            second=59;
        }

    } else{
        second--;
    }
}

// maybe find more efficient way to do this later
void Clock::add_seconds(int seconds){
    if(seconds>0){
        for (int i = 0; i < seconds; i++) {
            increment();
        }
    }
}

int Clock::hms_to_sec(){
    int total_seconds;
    total_seconds = hour*3600+minute*60+second;
}

void Clock::sec_to_hms(int n){

    if(n<0){
        n=0;
    }

    int full_hours = n/3600;
    int remaining_secs = n - full_hours*3600;

    while(full_hours>23){
        full_hours = full_hours - 24;
    }

    int full_minutes = remaining_secs/60;
    remaining_secs = remaining_secs - full_minutes*60;
    
    hour = full_hours;
    minute = full_minutes;
    second = remaining_secs;



    
}





// ******************************* from lab3exe_C.cpp
int main(void) {
    
    Clock t1;
    cout << "Object t1 is created. Expected time is: 00:00:00\n";
    print(t1);
    
    for(int i = 0; i < 86400; i++)
        t1.increment();
    
    cout << "Object t1 incremented by 86400 seconds. Expected time is: 00:00:00\n";
    print(t1);
    
    Clock t2(86405);
    cout << "Object t2 is created. Expected time is: 00:00:05\n";
    print(t2);
    
    for(int i = 0; i < 6; i++)
        t2.decrement();
    
    cout << "Object t2 decremented by 6 seconds. Expected time is: 23:59:59\n";
    print(t2);
    

    t1.set_hour(21);
    cout << "After setting t1's hour to 21. Expected time is: 21:00:00\n";
    print(t1);
    
    t1.set_hour(60);
    cout << "Setting t1's hour to 60 (invalid value). Expected time is: 21:00:00\n";
    print(t1);

    t2.set_minute(20);
    cout << "Setting t2's minute to 20. Expected time is: 23:20:59\n";
    print(t2);
    
    t2.set_second(50);
    cout << "Setting t2's second to 50. Expected time is 23:20:50\n";
    print(t2);
    
    t2.add_seconds(2350);
    cout << "Adding 2350 seconds to t2. Expected time is: 00:00:00\n";
    print(t2);

    t2.add_seconds(72000);
    cout << "Adding 72000 seconds to t2. Expected time is: 20:00:00\n";
    print(t2);
    
    
    t2.add_seconds(216000);
    cout << "Adding 216000 seconds to t2. Expected time is: 08:00:00\n";
    print(t2);
    
    Clock t3(0, 0, 0);
    cout << "Object t3 is created. Expected time is: 00:00:00\n";
    print(t3);
    
    t3.increment();
    cout << "Adding 1 second to clock t3. Expected time is: 00:00:01\n";
    print(t3);

    t3.decrement();
    cout << "After calling decrement for t3. Expected time is: 00:00:00\n";
    print(t3);
    
    for(int i = 0; i < 86400; i++)
        t3.increment();
    
    cout << "After incrementing t3 by 86400 seconds. Expected time is: 00:00:00\n";
    print(t3);
    
    for(int i = 0; i < 86401; i++)
        t3.decrement();
    
    cout << "After decrementing t3 by 86401 seconds. Expected time is: 23:59:59\n";
    print(t3);

    for(int i = 0; i < 864010; i++)
        t3.decrement();
    
    cout << "After decrementing t3 by 864010 seconds. Expected time is: 23:59:49\n";
    print(t3);
    
    // Oject t4 is created with invalid value of hour (i.e. 25), and valid values
    // for other members, minute and second respectively.
    Clock t4(25, 0, 0);
    cout << "t4 is created with invalid value (25 for hour). Expected to show: 00:00:00\n";
    print(t4);
    
    // Oject t5 is created with invalid value of minute (i.e. -8), and valid values
    // for other member, hour and second.
    Clock t5(23, -8, 59);
    cout << "t5 is created with invalid value (-8 for minute). Expected to show: 00:00:00\n";
    print(t5);

    // Oject t6 is created with invalid value of second (i.e. 61), and valid values
    // for other members.
    Clock t6(23, 59, 61);
    cout << "t6 is created with invalid value (61 for second). Expected to show: 00:00:00\n";
    print(t6);
    
    Clock t7(-10);
    cout << "t7 is created with invalid value (negative value). Expected to show: 00:00:00\n";
    print(t7);
    
    return 0;
}


void print(const Clock& t)
{
    cout << setw(2) << setfill('0') << t.get_hour() << ":"
    << setw(2) << t.get_minute() << ":" << setw(2) << t.get_second() << endl;
}


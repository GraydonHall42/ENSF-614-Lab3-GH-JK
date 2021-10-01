/*
* File Name: lab3Clock.cpp
* Lab # and Assignment #: Lab 3 Exercise C
* Lab section: 1
* Completed by: Graydon Hall and Jared Kraus
* Submission Date: 2021-10-04
*/
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;
using std::setfill;


#include "lab3Clock.h"

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


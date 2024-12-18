#include <string>
#include <iostream>
#include "Time.h"
using namespace std;

//constructors
Time::Time(){
    hour=0;
    minute=0;
    second=0;
}
Time::Time(int h, int m, double s)
{
  hour = h; minute = m; second = s;
}

Time::Time(int h, int m, int s)
{
  hour = h; minute = m; second = (double)s;
  
}
Time::Time(double secs)
{
    hour = int(secs / 3600.0);
    secs -= hour * 3600.0;
    minute = int(secs / 60.0);
    secs -= minute * 60;
    second = secs;
}
Time::Time(int h, int m){
    hour =h;
    minute =m;
    second =0;
}

void Time::print() const
{
    cout << hour << ":" << minute << ":" << second << endl;
}


void Time::increment(double secs)
{
    int mhour = (int)secs/3600;
   int mminute = (int)secs/60;
   
   hour += mhour;
   minute += mminute;
   
   secs-=(mhour*3600+mminute*60);
   second+=secs;
   
}

void Time::fix(){
    while(second>60){
        minute+=1;
        second-=60;
    }
    while(minute>60){
        hour+=1;
        second-=60;
    }
}

std::string Time::to_string() const {
    string s = std::to_string(hour)+":";
    if(minute<10){
        s+="0";
    }
    
    s+=std::to_string(minute)+":";
    if(second<10){
        s+="0";
    }
     s+=std::to_string((int)second);
     return s;
}

double Time::convert_to_seconds() const
{
    return (hour * 60 + minute) * 60 + second;
}

bool Time::after(const Time &t2) const
{
    if (hour > t2.hour) return true;
    if (hour < t2.hour) return false;

    if (minute > t2.minute) return true;
    if (minute < t2.minute) return false;

    return (second > t2.second);
}

Time Time::add(const Time &t2) const
{
    return Time(convert_to_seconds() + t2.convert_to_seconds());
}


Time Time::operator+(const Time &other) {
    Time plus(hour+other.hour, minute + other.minute, second+other.second);
    plus.fix();
    return plus;
}

std::ostream& operator<<(std::ostream& out, Time t) {
    out << t.to_string();
    return out;
}

std::string Time::am_pm() const {
    if(hour<=12){
        return to_string() +" AM";
    }
    else{
        int n = hour-12;
        Time t(n,minute,second);
        return t.to_string()+" PM";
    }
}
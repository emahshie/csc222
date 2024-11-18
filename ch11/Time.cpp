#include <iostream>
#include "Time.h"
using namespace std;


Time::Time(int h, int m, double s)
{
  hour = h; minute = m; second = s;
}

void Time::print() const
{
    cout << hour << ":" << minute << ":" << second << endl;
}

void Time::increment(double secs)
{
    second += secs;

    while (second >= 60.0) {
        second -= 60.0;
        minute += 1;
    }
    while (minute >= 60) {
        minute -= 60;
        hour += 1;
    }
}
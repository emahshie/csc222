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
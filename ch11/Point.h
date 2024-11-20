#include <iostream>
#include <string>
using namespace std;

struct Point 
{
    double x, y;

    Point();
    Point(double,double);

    Point operator+(const Point &);

    string to_string();

};
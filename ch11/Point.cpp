#include <iostream>
#include <string>
#include "Point.h"
using namespace std;

Point::Point(){
    x=0;
    y=0;
}

Point::Point(double one, double two){
    x=one;
    y=two;
}

Point Point::operator+(const Point &other) {
    return Point(x + other.x, y + other.y);
}

string Point::to_string() {
    string s = "(";
    return s;
}
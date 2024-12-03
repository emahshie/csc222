#include <string>
#include <iostream>
#include "Date.h"
using namespace std;

Date::Date(int d, int m, int y){
    day = d;
    month = m;
    year = y;
}
std::string Date::to_string() const {
    string s = std::to_string(month) + "/" + std::to_string(day)+"/"+std::to_string(year);
    return s;

}
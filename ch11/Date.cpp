#include <string>
#include <iostream>
#include "Date.h"
using namespace std;

Date::Date(int m, int d, int y){
    day = d;
    month = m;
    year = y;
}
std::string Date::to_string() const {
    string s = std::to_string(month) + "/" + std::to_string(day)+"/"+std::to_string(year);
    return s;

}

std::string Date::to_words() const{
    string s = "The date is ";
    switch(month){
        case 1:
            s+= "January";
            break;
        case 2:
            s+= "February";
            break;
        case 3:
            s+= "March";
            break;
        case 4:
            s+= "April";
            break;
        case 5:
            s+= "May";
            break;
        case 6:
            s+= "June";
            break;
        case 7:
            s+= "July";
            break;
        case 8:
            s+= "August";
            break;
        case 9:
            s+= "September";
            break;
        case 10:
            s+= "October";
            break;
        case 11:
            s+= "November";
            break;
        case 12:
            s+= "December";
            break;
    }
    s+= " "+std::to_string(day) + ", "+std::to_string(year);
    return s;
}

std::string Date::season() const{
    if(month == 1 ||month== 2 || month==12){
        return "Winter";
    }
    else if(month == 3 ||month== 4 || month==5){
        return "Spring";
    }
    else if(month == 6 ||month==7 || month==8){
        return "Summer";
    }
    else{
        return "Fall";
    }
}
#include <string>
#include <iostream>
#include "Date.h"
using namespace std;


Date::Date(){
    day = 1;
    month = 1;
    year = 2000;
}

Date::Date(int m){
    day = 1;
    month = m;
    year = 2000;
}

Date::Date(int m, int d){
    day = d;
    month = m;
    year = 2000;
}

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
    s+= " "+std::to_string(day);
    if(day>10 && day<20){
        s+="th";
    }
    else if(day%10==1){
        s+="st";
    }
    else if(day%10==2){
        s+="nd";
    }
    else if(day%10==3){
        s+="rd";
    }
    else{
        s+="th";
    }

    s+= ", "+std::to_string(year);
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

bool Date::after(const Date &d2) const
{
    if (year > d2.year) return true;
    if (year < d2.year) return false;

    if (month > d2.month) return true;
    if (month < d2.month) return false;

    return (day > d2.day);
}

int Date::days_since_2000() const{
    //must give a date after 2000
    if(year<2000){
        return 0;
    }
    int total = day + ((year-2000)*365) + ((year-2000)/4);
    for(int i = 1;i<month;i++){
        switch(i){
        case 1:
            total+= 31;
            break;
        case 2:
            total+=28;
            break;
        case 3:
            total+= 31;
            break;
        case 4:
            total+=30;
            break;
        case 5:
            total+= 31;
            break;
        case 6:
            total+=30;
            break;
        case 7:
            total+= 31;
            break;
        case 8:
            total+= 31;
            break;
        case 9:
            total+=30;
            break;
        case 10:
            total+= 31;
            break;
        case 11:
            total+=30;
            break;
        case 12:
            total+= 31;
            break;
    }
    }
    return total;


}

int Date::days_between(const Date &d2) const {
    //must give two dates after 2000
    if(after(d2)){
        return days_since_2000()- d2.days_since_2000();
    }
    else{
        return d2.days_since_2000()-days_since_2000();
    }

}
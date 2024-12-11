#include <iostream>
#include "Fraction.h"
#include <string>
using namespace std;
Fraction::Fraction()
{
  numerator = 0;
  denominator = 1;
}
Fraction::Fraction(int n, int d)
{
    numerator = n;
    denominator = d;
}

Fraction::Fraction(std::string s){
    int j=0;
    for(int i=0;i<s.length();i++){
        char n = s[i];
        if(n=='/'){
            j = i;
            break;
        }
    }
    if (j==0){
        numerator = stoi(s);
        denominator = 1;
    }
    else{
    numerator = stoi(s.substr(0,j));
    denominator = stoi(s.substr(j+1));
    }
}

Fraction::Fraction(int n){
    numerator = n;
    denominator = 1;
}

void Fraction::print() const {
    cout<<numerator<<"/"<<denominator;
}

std::string Fraction::to_string() const{
    if(denominator==0){
        return "Can't divide by 0";
    }
    if(numerator==0){
        return "0";
    }
    if(denominator==1){
        return std::to_string(numerator);
    }
    return std::to_string(numerator)+"/"+std::to_string(denominator);
}


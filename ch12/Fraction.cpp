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
    int t = gcd(n,d);
    numerator = n/t;
    denominator = d/t;
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
int gcd(int numerator,int denominator){
    int small = min(numerator, denominator);
    while(small > 1){
        if (numerator % small == 0 && denominator % small == 0)
            {
            return small;
            }
        small--;
    }
    return 1;
}

bool Fraction::operator==(const Fraction& c2) const
{
    if (numerator == c2.numerator && denominator == c2.denominator) return true;
    return false;
}

bool Fraction::operator!=(const Fraction& c2) const
{
    if (numerator == c2.numerator && denominator == c2.denominator) return false;
    return true;
}



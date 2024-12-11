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

bool Fraction::operator>(const Fraction& c2) const
{
    double n = (double)numerator;
    double d = (double)denominator;
    double n2 = (double)c2.numerator;
    double d2 = (double)c2.denominator;
    if (n/d > n2/d2) {
        return true;
    }
    return false;
}

bool Fraction::operator<(const Fraction& c2) const
{
    double n = (double)numerator;
    double d = (double)denominator;
    double n2 = (double)c2.numerator;
    double d2 = (double)c2.denominator;
    if (n/d < n2/d2) {
        return true;
    }
    return false;
}

bool Fraction::operator>=(const Fraction& c2) const
{
    if ((numerator == c2.numerator) && (denominator == c2.denominator)) return true;
    double n = (double)numerator;
    double d = (double)denominator;
    double n2 = (double)c2.numerator;
    double d2 = (double)c2.denominator;
    if (n/d > n2/d2) {
        return true;
    }
    return false;
}

bool Fraction::operator<=(const Fraction& c2) const
{
    if ((numerator == c2.numerator) && (denominator == c2.denominator)) return true;
    double n = (double)numerator;
    double d = (double)denominator;
    double n2 = (double)c2.numerator;
    double d2 = (double)c2.denominator;
    if (n/d < n2/d2) {
        return true;
    }
    return false;
}

Fraction Fraction::operator*(Fraction f2) const{
    int y = denominator * f2.denominator;
    int x = numerator * f2.numerator;
    
    return Fraction(x,y);
}
Fraction Fraction::operator/(Fraction f2) const{
    int y = denominator * f2.numerator;
    int x = numerator * f2.denominator;
    
    return Fraction(x,y);
}
Fraction Fraction::operator-(Fraction f2) const{
    int n1 = numerator;
    int d1 = denominator;
    int n2 = f2.numerator;
    int d2 = f2.denominator;
    n1 *= f2.denominator;
    d1 *= f2.denominator;
    n2 *= denominator;
    d2 *= denominator;
    return Fraction((n1-n2),(d1));
}
Fraction Fraction::operator+(Fraction f2) const{
    int n1 = numerator;
    int d1 = denominator;
    int n2 = f2.numerator;
    int d2 = f2.denominator;
    n1 *= f2.denominator;
    d1 *= f2.denominator;
    n2 *= denominator;
    d2 *= denominator;
    return Fraction((n1+n2),(d1));
    return 1;
}
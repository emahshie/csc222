#include <iostream>
#include <string>
#include "BigInt.h"
using namespace std;

BigInt::BigInt()
{
    negative = false;
    digits = "0";
}

BigInt::BigInt(int i)
{
    negative = (i >= 0) ? false : true;
    digits = (i >= 0) ? std::to_string(i) : std::to_string(-i);
}

BigInt::BigInt(string n)
{
    negative = (n.front() == '-') ? true: false;
    digits = (n.front() == '-') ? n.substr(1, n.size() - 1) : n;
}

string BigInt::to_string() const
{
    return (!negative) ? digits : "-" + digits;
}

bool BigInt::operator == (const BigInt &b) const{
    if(digits == b.digits && negative==b.negative) return true;
    return false;
}

bool BigInt::operator>(const BigInt& b) const{
    if(!negative && b.negative){
        return  true;
    }else if(negative && !b.negative){
        return false;
    }
    if(!negative){
    if(digits.length() > b.digits.length()){
        return true;
        }else if(digits.length() < b.digits.length()){
            return false;
        }
    }else if(negative){
        if(digits.length() < b.digits.length()){
            return true;
        }else if(digits.length() > b.digits.length()){
            return false;
        }
    }
    if(!negative){
        for(int i = 0; i < digits.length(); i++){
            if(digits[i] > b.digits[i]){
                return true;
            }else if(digits[i] < b.digits[i]){
                return false;
            }
        }
    }
    if(negative){
        for(int i = 0; i < digits.length(); i++){
            if(digits[i] < b.digits[i]){
                return true;
            }else if(digits[i] > b.digits[i]){
                return false;
            }
        }
    }
}

bool BigInt::operator < (const BigInt &b) const{
    return false;
}
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
    if(!negative && b.negative){
        return  false;
    }else if(negative && !b.negative){
        return true;
    }
    if(!negative){
    if(digits.length() > b.digits.length()){
        return false;
        }else if(digits.length() < b.digits.length()){
            return true;
        }
    }else if(negative){
        if(digits.length() < b.digits.length()){
            return false;
        }else if(digits.length() > b.digits.length()){
            return true;
        }
    }
    if(!negative){
        for(int i = 0; i < digits.length(); i++){
            if(digits[i] > b.digits[i]){
                return false;
            }else if(digits[i] < b.digits[i]){
                return true;
            }
        }
    }
    if(negative){
        for(int i = 0; i < digits.length(); i++){
            if(digits[i] < b.digits[i]){
                return false;
            }else if(digits[i] > b.digits[i]){
                return true;
            }
        }
    }
}

bool BigInt::operator >= (const BigInt& b) const{
    if(digits == b.digits && negative==b.negative) return true;
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
    return false;
}

bool BigInt::operator <= (const BigInt &b) const {
    if(digits == b.digits && negative==b.negative) return true;
    if(!negative && b.negative){
        return  false;
    }else if(negative && !b.negative){
        return true;
    }
    if(!negative){
    if(digits.length() > b.digits.length()){
        return false;
        }else if(digits.length() < b.digits.length()){
            return true;
        }
    }else if(negative){
        if(digits.length() < b.digits.length()){
            return false;
        }else if(digits.length() > b.digits.length()){
            return true;
        }
    }
    if(!negative){
        for(int i = 0; i < digits.length(); i++){
            if(digits[i] > b.digits[i]){
                return false;
            }else if(digits[i] < b.digits[i]){
                return true;
            }
        }
    }
    if(negative){
        for(int i = 0; i < digits.length(); i++){
            if(digits[i] < b.digits[i]){
                return false;
            }else if(digits[i] > b.digits[i]){
                return true;
            }
        }
    }
}

bool BigInt::operator != (const BigInt &b) const {
    if(digits == b.digits && negative==b.negative) return false;
    return true;
}


BigInt BigInt::operator+(const BigInt& b) const {
    
    std::string result = "";
    int extra = 0;

    
    int i = digits.size() - 1;
    int j = b.digits.size() - 1;

    while (i >= 0 || j >= 0 || extra > 0) {
        int digit1 = (i >= 0) ? digits[i] - '0' : 0;
        int digit2 = (j >= 0) ? b.digits[j] - '0' : 0;

        int sum = digit1 + digit2 + extra;
        extra = sum / 10;            
        result += (sum % 10) + '0';  

        i--;
        j--;
    }

    
    std::reverse(result.begin(), result.end());
    return BigInt(result);
}

BigInt BigInt::operator - (const BigInt &b) const {
    BigInt result;
    return result;
}

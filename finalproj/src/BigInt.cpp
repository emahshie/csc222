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
    if(negative ^ b.negative){
        if(negative){
            BigInt n(digits);
            return(b-n);
        } 
        else {
            BigInt n(b.digits);
            return(*this-n);
        }
    }
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
    if(negative && b.negative){
        result.insert(0,"-");
    }
    return BigInt(result);
}

BigInt BigInt::operator-(const BigInt& b) const {
   if(b>*this && !negative && !b.negative){
    BigInt n = (b-*this);
    n.negative = true;
    return n;
   }

   if(!negative && b.negative){
    BigInt n = b;
    n.negative = false;
    return(*this+n);
   }

   if(negative && !b.negative){
    BigInt n = *this;
    n.negative = false;
    n = n + b;
    n.negative = true;
    return n;
   }

    std::string result = "";
    int borrow = 0;

    int i = digits.size() - 1;
    int j = b.digits.size() - 1;

    while (i >= 0 || j >= 0) {
        int digit1 = (i >= 0) ? digits[i] - '0' : 0; 
        int digit2 = (j >= 0) ? b.digits[j] - '0' : 0; 

        digit1 -= borrow; 

        if (digit1 < digit2) {
            digit1 += 10; 
            borrow = 1;   
        } else {
            borrow = 0;
        }

        result += (digit1 - digit2) + '0'; 
        i--;
        j--;
    }
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    std::reverse(result.begin(), result.end());

    return BigInt(result);
}



BigInt BigInt::operator*(const BigInt& b) const {
     
    std::string result(digits.size() + b.digits.size(), '0');

    
    for (int i = digits.size() - 1; i >= 0; --i) {
        int carry = 0;
        for (int j = b.digits.size() - 1; j >= 0; --j) {
            int product = (digits[i] - '0') * (b.digits[j] - '0') + (result[i + j + 1] - '0') + carry;
            result[i + j + 1] = (product % 10) + '0';
            carry = product / 10;
        }
        result[i] += carry; 
    }

    int start = result.find_first_not_of('0');
    if (start == std::string::npos) {
        result = "0"; 
    } else {
        result = result.substr(start);
    }

    
    BigInt final_result(result);

    if(negative ^ b.negative) final_result.negative = true;

    return final_result;
}

BigInt BigInt::operator/(const BigInt& b) const {
    if(b.digits>digits)return BigInt("0");
    if(b.digits==digits){
        if(negative ^ b.negative)return BigInt("-1");
        return BigInt("1");
    }
    if(b.digits=="1"){
        if(b.negative ^ negative){
            return BigInt('-'+digits);
        }
        return BigInt(digits);
    }
    
    std::string res;
    BigInt div(digits[0]);
    BigInt den(b.digits);
    int count;

    for(int i=1;i<digits.size();i++){
        if(div < den){
            res += '0';
        }
        else{
            
            res += stoi(div.digits)/stoi(den.digits);
        }
        BigInt div(div.digits + digits[i]);

    }
    
    
    BigInt result(res);
    if(negative ^ b.negative)result.negative = true;
    return result;
}
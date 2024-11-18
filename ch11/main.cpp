#include <iostream>
#include "Time.h"
using namespace std;

int main(){
    Time current_time = {9, 14, 30.0};
current_time.increment(500.0);
current_time.print();
cout<<current_time.convert_to_seconds();
    return 0;

}
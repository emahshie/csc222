#include <string>
#include <vector>
#include <iostream>
using namespace std;

string render_num_vector(const vector<int>& nums) {
    string s = "";
    for(int i=0;i<nums.size();i++){
        s.append(std::to_string(nums.at(i)));
        
        if(i<nums.size()-1){
            s.append(" ");
    }
    }
return s;
}

int num_vector_sum(const vector<int>& nums){
	int total = 0;
	for(int i =0;i<nums.size();i++){
		total += nums.at(i);
}
return total;
}

int num_vector_product(const vector<int>& nums){
        int product = 0;

return product;
}

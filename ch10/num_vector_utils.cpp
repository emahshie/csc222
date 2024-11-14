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
	product += nums.at(0);
	for(int i =1;i<nums.size();i++){
		product *= nums.at(i);
}
return product;
}

vector<int> only_evens(const vector<int>& nums){
	vector<int> even={};
	for(int i=0;i<nums.size();i++){
	if(nums[i]%2==0){
        even.push_back(nums[i]);

     }
    }
return even;
}

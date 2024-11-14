#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include <vector>
#include "num_vector_utils.h"
using namespace std;

TEST_CASE("Test 1") {
    vector<int> nums = {1, 3, 7};
    string numstr = render_num_vector(nums);
    string expected = "1 3 7";
    CHECK(numstr == expected);
}

TEST_CASE("Test 2"){
vector<int> nums = {1,2,3,4,5,5};
string numstr = render_num_vector(nums);
string expected = "1 2 3 4 5 5";
CHECK(numstr == expected);
}

TEST_CASE("Test 3"){
vector<int> nums = {};
string numstr = render_num_vector(nums);
string expected = "";
CHECK(numstr == expected);

}

TEST_CASE("Testing num_vector_sum") {
    vector<int> nums = {1, 3, 7};
    CHECK(11 == num_vector_sum(nums));
vector<int> nums2 = {1,-4,-3,2};
CHECK(-4 == num_vector_sum(nums2));
vector<int> nums3 = {};
CHECK(0 == num_vector_sum(nums3));
}

TEST_CASE("Testing num_vector_product") {
    vector<int> nums = {2, 3, 7};
    CHECK(42 == num_vector_product(nums));
vector<int> nums2 = {2, 3, 7,0};
CHECK(0 == num_vector_product(nums2));
vector<int> nums3 = {-2,-3,-7};
CHECK(-42 == num_vector_product(nums3));
}

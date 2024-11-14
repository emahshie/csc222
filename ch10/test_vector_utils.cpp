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
}

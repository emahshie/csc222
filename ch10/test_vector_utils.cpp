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

TEST_CASE("Testing only_evens") {
    vector<int> nums = {1, 2, 3, 4, 6, 7, 8, 11, 12, 14, 27, 22};
    vector<int> evens = only_evens(nums);
    string expected = "2 4 6 8 12 14 22";
    CHECK(render_num_vector(evens) == expected);

vector<int> nums2 = {1,1,1,3,3};
    vector<int> evens2 = only_evens(nums2);
    string expected2 = "";
    CHECK(render_num_vector(evens2) == expected2);
}

TEST_CASE("Testing only_odds") {
    vector<int> nums = {1, 2, 3, 4, 6, 7, 8, 11, 12, 14, 27, 22};
    vector<int> odds = only_odds(nums);
    string expected = "1 3 7 11 27";
    CHECK(render_num_vector(odds) == expected);

	vector<int> nums2 = {0,2,4,6,8};
    vector<int> odd2 = only_odds(nums2);
    string expected2 = "";
    CHECK(render_num_vector(odd2) == expected2);
}

TEST_CASE("Testing nums_between function") {
    vector<int> nums = {11, 2, 13, 4, 10, 26, 7, 88, 19, 20, 14, 5, 32};
    vector<int> nums2 = nums_between(nums, 10, 20);
    string expected = "11 13 10 19 20 14";
    CHECK(render_num_vector(nums2) == expected);
}

TEST_CASE("Testing mean function") {
    vector<int> nums = {2,4,6};
    CHECK(4==mean(nums));
    vector<int> nums2 = {-8,2,1,3};
    CHECK(-0.5==mean(nums2));
}

TEST_CASE("Testing median function"){
    vector<int> nums = {1,2,3,4,5};
    CHECK(3==median(nums));
    vector<int> nums2 = {-2,-4,-1,-3};
    CHECK(-2.5==median(nums2));
}
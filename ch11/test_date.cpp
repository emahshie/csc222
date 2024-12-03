#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Date.h"
using namespace std;

TEST_CASE("Test can create and render Date") {
    Date d(2,2,2002);
    CHECK(d.to_string() == "2/2/2002");
}

TEST_CASE("Test can write date in word form"){
    Date d(1,3,1992);
    CHECK(d.to_words() == "The date is January 3, 1992");
}
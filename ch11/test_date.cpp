#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Date.h"
using namespace std;

TEST_CASE("Test can create and render Date") {
    Date d(2,2,2002);
    CHECK(d.to_string() == "2/2/2002");
}
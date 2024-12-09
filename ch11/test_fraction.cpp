#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include <vector>
#include "Fraction.h"
using namespace std;

TEST_CASE("print"){
    Fraction f(0,0);
    Fraction h(3,1);
    Fraction g(3,2);
    CHECK(f.to_string()=="Can't divide by 0");
    CHECK(h.to_string()=="3");
    CHECK(g.to_string()=="3/2");
}
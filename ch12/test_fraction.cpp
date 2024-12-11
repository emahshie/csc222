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

TEST_CASE("Test can create Fractions using two constructors") {
    Fraction f1;
    CHECK(f1.numerator == 0);
    CHECK(f1.denominator == 1);
    Fraction f2(3, 4);
    CHECK(f2.numerator == 3);
    CHECK(f2.denominator == 4);
}

TEST_CASE("Test can render a Fraction as a string") {
    Fraction f1(17, 25);
    CHECK(f1.to_string() == "17/25");
    Fraction f2(-7, 11);
    CHECK(f2.to_string() == "-7/11");
}
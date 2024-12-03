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

TEST_CASE("Can print season"){
    Date w(1,1,1);
    CHECK(w.season()=="Winter");
    Date sp(4,4,4);
    CHECK(sp.season()=="Spring");
    Date su(8,8,8);
    CHECK(su.season()=="Summer");
    Date f(10,10,10);
    CHECK(f.season()=="Fall");
}
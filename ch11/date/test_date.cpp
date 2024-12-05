#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Date.h"
using namespace std;

TEST_CASE("Test can create and render Date") {
    Date d(2,2,2002);
    CHECK(d.to_string() == "2/2/2002");
    Date a;
    CHECK(a.to_string() == "1/1/2000");
    Date b(3);
    CHECK(b.to_string() == "3/1/2000");
    Date c(3,4);
    CHECK(c.to_string() == "3/4/2000");
}

TEST_CASE("Test can write date in word form"){
    Date d(1,3,1992);
    CHECK(d.to_words() == "The date is January 3rd, 1992");
    Date a(1,2,1000);
    CHECK(a.to_words()=="The date is January 2nd, 1000");
    Date b(1,25,1000);
    CHECK(b.to_words()=="The date is January 25th, 1000");
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

TEST_CASE("Can compare two dates"){
    Date a(2,20,2024);
    Date b(2,21,2024);
    Date c(2,20,2024);
    CHECK(b.after(a));
    CHECK(!a.after(c));
    
}

TEST_CASE("Can convert to days since year 2000"){
    Date d(6,15,2022);
    CHECK(d.days_since_2000() == 8201);
    Date s(1,1,1900);
    CHECK(!s.days_since_2000());
}

TEST_CASE("Can find the difference between two dates after 2000"){
    Date d(2,2,2001);
    Date s(2,3,2001);
    CHECK(d.days_between(s)==1);

    Date e(2,2,2001);
    Date f(11,9,2000);
    CHECK(e.days_between(f)==85);

}
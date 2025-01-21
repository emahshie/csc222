#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "BigInt.h"
using namespace std;

TEST_CASE("Test can create and render BigInts") {
    BigInt bi;
    CHECK(bi.to_string() == "0");
    BigInt bi2(42);
    CHECK(bi2.to_string() == "42");
    BigInt bi3(-42);
    CHECK(bi3.to_string() == "-42");
    BigInt bi4("123456789012345678901234567890");
    CHECK(bi4.to_string() == "123456789012345678901234567890");
    BigInt bi5("-923456789012345678901234567890");
    CHECK(bi5.to_string() == "-923456789012345678901234567890");
}

TEST_CASE("Test can compare BigInts for equality") {
    BigInt i1("12345");
    BigInt i2("54321");
    BigInt i3("123456");
    BigInt i4("-654321");
    BigInt i5("54321");
    BigInt i6("-54321");
    CHECK((i2 == i5) == true);
    CHECK((i1 == i2) == false);
    CHECK((i1 == i3) == false);
    CHECK((i2 == i6) == false);
}

TEST_CASE("Test can compare BigInts for greater than") {
    BigInt i1("12345");
    BigInt i2("54321");
    BigInt i3("123456");
    BigInt i4("-654321");
    BigInt i5("54321");
    BigInt i6("-54321");
    CHECK((i2 > i5) == false);
    CHECK((i2 > i1) == true);
    CHECK((i4 > i1) == false);
    CHECK((i6 > i4) == true);
}

TEST_CASE("Test can compare BigInts for less than") {
    BigInt i1("12345");
    BigInt i2("54321");
    BigInt i3("123456");
    BigInt i4("-654321");
    BigInt i5("54321");
    BigInt i6("-54321");
    CHECK((i2 < i5) == false);
    CHECK((i2 < i1) == false);
    CHECK((i4 < i1) == true);
    CHECK((i6 < i4) == false);
}

TEST_CASE("Test can compare BigInts for greater than or equal to") {
    BigInt i1("12345");
    BigInt i2("54321");
    BigInt i3("123456");
    BigInt i4("-654321");
    BigInt i5("54321");
    BigInt i6("-54321");
    CHECK((i2 >= i5) == true);
    CHECK((i2 >= i1) == true);
    CHECK((i4 >= i1) == false);
    CHECK((i6 >= i4) == true);
}

TEST_CASE("Test can compare BigInts for less than or equal to") {
    BigInt i1("12345");
    BigInt i2("54321");
    BigInt i3("123456");
    BigInt i4("-654321");
    BigInt i5("54321");
    BigInt i6("-54321");
    CHECK((i2 <= i5) == true);
    CHECK((i2 <= i1) == false);
    CHECK((i4 <= i1) == true);
    CHECK((i6 <= i4) == false);
}

TEST_CASE("Test can compare BigInts for inequality") {
    BigInt i1("12345");
    BigInt i2("54321");
    BigInt i3("123456");
    BigInt i4("-654321");
    BigInt i5("54321");
    BigInt i6("-54321");
    CHECK((i2 != i5) == false);
    CHECK((i1 != i2) == true);
    CHECK((i1 != i3) == true);
    CHECK((i2 != i6) == true);
}

TEST_CASE("Test can add positive BigInts") {
    BigInt i1("123");
    BigInt i2("321");
    BigInt i3("43210");
    BigInt i4("9999");
    BigInt i5("1");
    CHECK((i1 + i2).to_string() == "444");
    CHECK((i1 + i3).to_string() == "43333");
}

TEST_CASE("Test can subtract positive BigInts") {
    BigInt i1("123");
    BigInt i2("321");
    BigInt i3("43210");
    BigInt i4("9999");
    BigInt i5("1");
    CHECK((i2 - i1).to_string() == "198");
    CHECK((i4 - i5).to_string() == "9998");
    CHECK((i5 - i4).to_string() == "-9998");
}

TEST_CASE("Test can add two negative BigInts"){
    BigInt i1("-20");
    BigInt i2("-400");
    CHECK((i1+i2).to_string() == "-420");
}

TEST_CASE("Test can add one negative one positive BigInts"){
    BigInt i1("20");
    BigInt i2("-400");
    CHECK((i1+i2).to_string() == "-380");
}

TEST_CASE("Test can add BigInts") {
    BigInt i1("123");
    BigInt i2("321");
    BigInt i3("43210");
    BigInt i4("9999");
    BigInt i5("99999");
    BigInt i6("999999999");
    BigInt i7("109");
    BigInt i8("9");
    CHECK((i1 + i2).to_string() == "444");
    CHECK((i3 + i4).to_string() == "53209");
    CHECK((i5 + i6).to_string() == "1000099998");
    CHECK((i7 + i8).to_string() == "118");
}

TEST_CASE("Test can add negitive BigInts") {
    BigInt i1("-123");
    BigInt i2("321");
    BigInt i3("43210");
    BigInt i4("-9999");
    BigInt i5("99999");
    BigInt i6("-999999999");
    BigInt i7("-109");
    BigInt i8("21");
    CHECK((i1 + i2).to_string() == "198");
    CHECK((i3 + i4).to_string() == "33211");
    CHECK((i5 + i6).to_string() == "-999900000");
    CHECK((i8 + i7).to_string() == "-88");
}

TEST_CASE("Test can subtract BigInts") {
    BigInt i1("123");
    BigInt i2("321");
    BigInt i3("43210");
    BigInt i4("9999");
    BigInt i5("99999");
    BigInt i6("999999999");
    BigInt i7("109");
    BigInt i8("9");
    CHECK((i2 - i1).to_string() == "198");
    CHECK((i3 - i4).to_string() == "33211");
    CHECK((i5 - i6).to_string() == "-999900000");
    CHECK((i7 - i8).to_string() == "100");
}
TEST_CASE("Test can subtract negitive BigInts") {
    BigInt i1("-123");
    BigInt i2("321");
    BigInt i3("-43210");
    BigInt i4("9999");
    BigInt i5("99999");
    BigInt i6("-999999999");
    BigInt i7("109");
    BigInt i8("9");
    CHECK((i2 - i1).to_string() == "444");
    CHECK((i3 - i4).to_string() == "-53209");
    CHECK((i5 - i6).to_string() == "1000099998");
    CHECK((i7 - i8).to_string() == "100");
}

TEST_CASE("Test can multiply BigInts") {
    BigInt i1("264");
    BigInt i2("32");
    BigInt i3("-9");
    BigInt i4("10");
    BigInt i5("-123456");
    BigInt i6("-6789");
    BigInt i7("3");
    BigInt i8("3");
    BigInt i9("0");
    CHECK((i2 * i1).to_string() == "8448");
    CHECK((i3 * i4).to_string() == "-90");
    CHECK((i5 * i6).to_string() == "838142784");
    CHECK((i7 * i8).to_string() == "9");
    CHECK((i9 * i1).to_string() == "0");
}

TEST_CASE("Test can divide BigInts") {
    BigInt i1("9");
    BigInt i2("9");
    BigInt i3("9");
    BigInt i4("10");
    BigInt i5("1999");
    BigInt i6("199");
    BigInt i7("3");
    BigInt i8("3");
    CHECK((i2 / i1).to_string() == "1");
    CHECK((i3 / i4).to_string() == "0");
    CHECK((i5 / i6).to_string() == "10");
    CHECK((i7 / i8).to_string() == "1");
}
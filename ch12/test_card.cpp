#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <iostream>
#include <string>
#include "Card2.h"
using namespace std;

TEST_CASE("Test can create Cards") {
    Card c1;
    CHECK(c1.suit == 0);
    CHECK(c1.rank == 0);
    Card c2(HEARTS, FOUR);
    CHECK(c2.suit == 3);
    CHECK(c2.rank == 4);
}

TEST_CASE("Test can render Cards") {
    Card c3(HEARTS, QUEEN);
    CHECK(c3.to_string() == "Queen of Hearts");
    Card c4(DIAMONDS, TEN);
    CHECK(c4.to_string() == "10 of Diamonds");
    Card c5;
    CHECK(c5.to_string() == "Joker");
}

TEST_CASE("Can compare cards") {
    Card c1(DIAMONDS,TWO);
    Card c2(DIAMONDS,TWO);
    Card c3(CLUBS,ACE);
    Card c4(CLUBS,THREE);
    CHECK(c1==c2);
    CHECK(!(c2==c3));
    CHECK(c1>c4);
    CHECK(c4>c3);

}

TEST_CASE("less than"){
    Card c1(CLUBS,ACE);
    Card c2(DIAMONDS,TWO);
    CHECK(c1<c2);
    CHECK(!(c2<c1));
}

TEST_CASE("greater than or equal to"){
    Card c1(CLUBS,ACE);
    Card c2(CLUBS,ACE);
    Card c3(DIAMONDS,TWO);
    CHECK(c1>=c2);
    CHECK(c3>=c1);
}

TEST_CASE("greater than or equal to"){
    Card c1(CLUBS,ACE);
    Card c2(CLUBS,ACE);
    Card c3(DIAMONDS,TWO);
    CHECK(c1<=c2);
    CHECK(c1<=c3);
}

TEST_CASE("build deck"){
    vector<Card> deck;
    deck = build_deck();
    CHECK(deck[32].to_string() == "7 of Hearts");
}
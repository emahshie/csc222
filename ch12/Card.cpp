#include <string>
#include <iostream>
#include "Card.h"
using namespace std;


Card::Card() {
    suit = 0; rank = 0;
}

Card::Card(int s, int r) {
    suit = s; rank = r;
}

std::string Card::to_string() const
{
    vector<string> suit_strings = {"None", "Clubs", "Diamonds",
                                   "Hearts", "Spades"};
    vector<string> rank_strings = {"Joker", "2", "3", "4", "5", "6", "7",
                                   "8", "9", "10", "Jack", "Queen", "King",
                                   "Ace"};

    if (rank == 0) return rank_strings[rank];
    return rank_strings[rank] + " of " + suit_strings[suit];
}

bool Card::operator==(const Card& c2) const
{
    return (rank == c2.rank && suit == c2.suit);
}

bool Card::operator>(const Card& c2) const
{
    // first check the suits
    if (suit > c2.suit) return true;
    if (suit < c2.suit) return false;

    // if suits are equal, check ranks
    if (rank > c2.rank) return true;
    if (rank < c2.rank) return false;
    // this last statement can be omitted without changing the
    // behavior of the function, but making it arguably less readable

    // if ranks are equal too, 1st card is not greater than the 2nd
    return false;
}

void print_deck(const vector<Card>& deck)
{
    for (int i = 0; i < deck.size(); i++) {
        cout << deck[i].to_string() << endl;
    }
}

int find_card(const Card& card, const vector<Card>& deck)
{
    for (int i = 0; i < deck.size(); i++) {
        if (deck[i].equals(card)) return i;
    }
    return -1;
}

int bin_search(const Card& card, const vector<Card>& deck, int l, int h) {
    int m = (l + h) / 2;

    if (deck[m].equals(card)) return mid;

    if (deck[m].is_greater(card))
        return bin_search(card, deck, l, m-1)
    else
        return bin_search(card, deck, m+1, h);
}
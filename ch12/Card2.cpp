#include <string>
#include <iostream>
#include "Card2.h"
#include <vector>
using namespace std;

Card::Card() {
    suit = NONE; rank = JOKER;
}

Card::Card(Suit s, Rank r) {
    suit = s; rank = r;
}

std::string Card::to_string() const
{
    vector<string> suit_strings = {"None", "Clubs", "Diamonds", "Hearts", "Spades"};
    vector<string> rank_strings = {"Joker", "", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

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

bool Card::operator<(const Card& c2) const
{
    if (suit < c2.suit) return true;
    if (suit > c2.suit) return false;

    if (rank < c2.rank) return true;
    if (rank > c2.rank) return false;

    return false;
}
bool Card::operator>=(const Card& c2) const
{
    // first check the suits
    if (suit > c2.suit) return true;
    if (suit < c2.suit) return false;

    // if suits are equal, check ranks
    if (rank > c2.rank) return true;
    if (rank < c2.rank) return false;
    // this last statement can be omitted without changing the
    // behavior of the function, but making it arguably less readable

    // if ranks are equal too
    return true;
}
bool Card::operator<=(const Card& c2) const
{
    if (suit < c2.suit) return true;
    if (suit > c2.suit) return false;

    if (rank < c2.rank) return true;
    if (rank > c2.rank) return false;

    return true;
}

std::vector<Card> build_deck()
{
    vector<Card> deck(52);
    int i = 0;
    for (Suit suit = CLUBS; suit <= SPADES; suit = Suit(suit+1)) {
        for (Rank rank = TWO; rank <= ACE; rank = Rank(rank+1)) {
            deck[i].suit = suit;
            deck[i].rank = rank;
            i++;
        }
    }
    return deck;
}

Deck::Deck(int size)
{
    vector<Card> temp(size);
    cards = temp;
}

Deck::Deck()
{
    vector<Card> temp(52);
    cards = temp;
    int i = 0;
    for (Suit suit = CLUBS; suit <= SPADES; suit = Suit(suit+1)) {
        for (Rank rank = TWO; rank <= ACE; rank = Rank(rank+1)) {
            cards[i].suit = suit;
            cards[i].rank = rank;
            i++;
        }
    }
}

void Deck::print() const
{
    for (int i = 0; i < cards.size(); i++) {
        cout << cards[i].to_string() << endl;
    }
}

int Card::find(const Deck& deck) const
{
    for (int i = 0; i < deck.cards.size(); i++) {
        if (deck.cards[i]==(*this)) return i;
    }
    return -1;
}

void Deck::swap_cards(int first, int second){
    Card temp = cards[first];
    cards[first] = cards[second];
    cards[second] = temp;
}

Card Deck::remove_card(){
    Card c = cards[cards.size()-1];
    cards.pop_back();
    return c;
}

void Deck::add_card(Card c){
    cards.push_back(c);
}

void Deck::shuffle()
{
    for (int i = 0; i < cards.size(); i++) {
        int rand_card = random_between(0, cards.size() - 1);
        swap_cards(i, rand_card);
    }
}

int random_between(int s, int f){
    return (rand()%(f-s+1))+s;
}

void swap_cards(Card &c1, Card &c2){
    Card temp = c1;
    c1 = c2;
    c2 = temp;
}

Deck Deck::subdeck(int low, int high){
    Deck subdeck(high-low+1);
    for (int i =0;i<high-low;i++){
        subdeck.cards[i]=cards[i+low];
    }
    return subdeck;
}
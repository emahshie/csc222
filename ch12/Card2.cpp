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

void Deck::add_cards(Deck d){
    for(int i=0;i<d.cards.size();i++){
        add_card(d.cards[i]);
    }
}

void Deck::merge(int left, int mid, int right) {
    //temps to hold two halves
    std::vector<Card> leftCards(cards.begin()+left, cards.begin()+mid+1);
    std::vector<Card> rightCards(cards.begin()+mid+1, cards.begin()+right+1);

    int i = 0, j = 0, k = left;
    
    //merge back into originial deck
    while (i < leftCards.size() && j < rightCards.size()) {
        if (leftCards[i] <= rightCards[j]) {
            cards[k++] = leftCards[i++];
        } else {
            cards[k++] = rightCards[j++];
        }
    }

    //copy remaining elements
    while (i < leftCards.size()) {
        cards[k++] = leftCards[i++];
    }
    while (j < rightCards.size()) {
        cards[k++] = rightCards[j++];
    }
}

Deck Deck::merge_sort(){
    Deck temp = *this;
    temp.merge_sort(0, cards.size()-1);
    return temp;
}

void Deck::merge_sort(int left, int right) {
    //base case
    if (left >= right) {
        return;
    }

    //recursively sort both halves
    int mid = left + (right - left) / 2;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    
    //merge sorted halves
    merge(left, mid, right);

}
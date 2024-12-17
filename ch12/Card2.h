enum Suit {NONE, CLUBS, DIAMONDS, HEARTS, SPADES};
enum Rank {JOKER, TWO=2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
           NINE, TEN, JACK, QUEEN, KING, ACE};

struct Deck;

struct Card
{
    Rank rank;
    Suit suit;

    Card();
    Card(Suit s, Rank r);

    std::string to_string() const;
    bool operator==(const Card&) const;
    bool operator>(const Card&) const;
    bool operator<(const Card&) const;
    bool operator>=(const Card&) const;
    bool operator<=(const Card&) const;

    int find(const Deck&) const;

};
struct Deck {
    std::vector<Card> cards;

    Deck(int n);
    Deck();

    void print() const;
    void swap_cards(int first, int second);
};

std::vector<Card> build_deck();
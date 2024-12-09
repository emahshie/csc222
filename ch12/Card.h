struct Card
{
    int suit, rank;

    Card();
    Card(int s, int r);

    std::string::to_string() const;
    void print_deck(const vector<Card>&);
    int find_card(const Card&, const vector<Card>&);
    int bin_search(const Card&, const vector<Card>&, int, int);

};
bool Card::operator==(const Card&) const;
bool Card::operator>(const Card&) const;


struct Card
{
    int suit, rank;

    Card();
    Card(int s, int r);

    std::string to_string() const;
    bool operator==(const Card&) const;
    bool operator>(const Card&) const;
    bool operator<(const Card&) const;
    bool operator>=(const Card&) const;
    bool operator<=(const Card&) const;
};
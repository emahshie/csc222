

struct Date{
    int day, month, year;
    
    Date(int, int, int);

    std::string to_string() const;
    std::string to_words() const;
};


struct Date{
    int day, month, year;
    
    //constructors
    Date();
    Date(int);
    Date(int,int);
    Date(int, int, int);

    std::string to_string() const;
    std::string to_words() const;
    std::string season() const;
    bool after(const Date&) const;
    int days_since_2000() const;
};
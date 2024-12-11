struct Fraction{
    int numerator;
    int denominator;
    //constructors
    Fraction();
    Fraction(int, int);
    Fraction(std::string);
    //functions
    void print () const;
    std::string to_string() const;
};
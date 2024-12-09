struct Fraction{
    int numerator;
    int denominator;
    //constructors
    Fraction();
    Fraction(int, int);
    //functions
    void print () const;
    std::string to_string() const;
};
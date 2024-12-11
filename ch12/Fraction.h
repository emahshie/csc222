struct Fraction{
    int numerator;
    int denominator;
    //constructors
    Fraction();
    Fraction(int, int);
    Fraction(std::string);
    Fraction(int);
    //functions
    void print () const;
    std::string to_string() const;

    bool operator==(const Fraction&) const;
    bool operator!=(const Fraction&) const;
    bool operator>(const Fraction&) const;
    bool operator<(const Fraction&) const;
    bool operator>=(const Fraction&) const;
    bool operator<=(const Fraction&) const;

    Fraction operator*(Fraction) const;
    Fraction operator/(Fraction) const;
    Fraction operator-(Fraction) const;
    Fraction operator+(Fraction) const;
};
int gcd(int, int);
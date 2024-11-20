struct Time {
    // instance variables
    int hour, minute;
    double second;

    // constructors
    Time(int, int, double);
    Time(double);
    Time(int, int, int);
    Time();
    Time(int,int);

    // modifiers
    void increment(double);
    void fix(Time);

    // functions
    void print() const;
    bool after(const Time&) const;
    Time add(const Time&) const;
    double convert_to_seconds() const;
    std::string to_string() const;
    Time operator+(const Time &);

};
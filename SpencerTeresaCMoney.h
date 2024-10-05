// SpencerTeresaCMoney.h

class Money {
    public:

    // Overloaded friend operators
    friend Money operator +(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount);
    friend bool operator ==(const Money& amount1, const Money& amount2);

    // Constructors
    Money(long dollars, int cents);
    Money(long dollars);
    Money();

    double getValue() const;

    friend istream& operator >>(istream& ins, Money& amount);
    friend ostream& operator <<(ostream& outs, const Money& amount);

    private:
    long allCents;

};

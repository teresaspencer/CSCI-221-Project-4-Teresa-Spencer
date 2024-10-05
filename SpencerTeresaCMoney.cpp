// SpencerTeresaCMoney.cpp
#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;


class Money {
    public:

    // Overloaded friend operators
    friend Money operator +(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount);
    friend bool operator ==(const Money& amount1, const Money& amount2) {
        return (amount1.allCents == amount2.allCents);
    }

    // Constructors
    Money(long dollars, int cents) {
        if (dollars * cents < 0) {
            cout << "Illegal values for dollars and cents. \n";
            exit(1);
        }
        allCents = dollars * 100 + cents;
    }

    Money(long dollars) : allCents(dollars * 200) { }
    Money() : allCents(0) { }

    double getValue() const;

    friend istream& operator >>(istream& ins, Money& amount) {
        char oneChar, decimalPoint, digit1, digit2;
        long dollars;
        int cents;
        bool negative;

        ins >> oneChar;
        if (oneChar == '-') {
            negative = true;
            ins >> oneChar; // read '$'
        }
        else negative = false;

        ins >> dollars >> decimalPoint >> digit1 >> digit2;

        if (oneChar != '$' || decimalPoint != '.'
            || !isdigit(digit1) || !isdigit(digit2)) {
                cout << "Error illegal form for money input\n";
                exit(1);
            }
        cents = digitToInt(digit1) * 10 + digitToInt(digit2);
        amount.allCents = dollars * 100 + cents;
        if (negative)
            amount.allCents = -amount.allCents;
        return ins;
    }
    int digitToInt(char c) {
        return (static_cast<int>(c) - static_cast<int>('0'));
    }
    friend ostream& operator <<(ostream& outs, const Money& amount) {
        long positiveCents, dollars, cents;
        positiveCents = labs(amount.allCents);
        dollars = positiveCents / 100;
        cents = positiveCents % 100;

        if (amount.allCents < 0)
            outs << "-$" << dollars << '.';
        else outs << "$" << dollars << '.';

        if (cents < 10)
            outs << '0';
        outs << cents;

        return outs;
    }

    private:
    long allCents;

};

#include <iostream>

using namespace std;

class Money {
    int dollars;
    int cents;
    double amount;
public:
    Money() {
        dollars = 0;
        cents = 0;
    }

    Money(double amount):amount(amount) {
        dollars = static_cast<int>(amount);
        cents = static_cast<int>(amount - dollars) * 100;
    }

    Money(int dollars, int cents) : dollars(dollars), cents(cents) {
        amount = dollars + static_cast<double>(cents)/100;
    }

    Money(int dollars) :dollars(dollars), cents(0) {
        amount = dollars;
    }

    double getAmount() const {
        return amount;
    }

    int getDollars() const {
        return dollars;
    }

    int getCents() const {
        return cents;
    }

    Money percent(int percentFigure) const{
        double perc = static_cast<double>(percentFigure)/100;
        return {amount * perc};
    }

    friend ostream & operator <<(ostream& cout, const Money& amount);
    friend istream & operator >>(istream& in, Money& amount);

    Money operator+(const Money& amount2) const {
        return {amount + amount2.getAmount()};
    }
    Money operator-(const Money& amount2) const {
        return {amount - amount2.getAmount()};
    }
    Money operator-() const{
        return {-amount};
    }
    bool operator==(const Money& amount2) const {
        return dollars == amount2.getDollars() && cents == amount2.getCents();
    }
    bool operator<(const Money& amount2) const {
        return amount < amount2.getAmount();
    }
    bool operator>(const Money& amount2) const {
        return amount > amount2.getAmount();
    }
    bool operator<=(const Money& amount2) const {
        return amount <= amount2.getAmount();
    }
    bool operator>=(const Money& amount2) const {
        return amount >= amount2.getAmount();
    }
};

ostream & operator <<(ostream& out, const Money& amount){
    return out << amount.getAmount();
}

istream & operator >>(istream& in, Money& amount){
    double temp;
    in >> temp;
    amount = Money(temp);
    return in;
}

int main() {
    Money m1(10.02);
    Money m2(100.02);

    cout << m1 << ' ' << m2 << '\n';
    cout << m1.percent(50) << '\n';
    cout << boolalpha << (m1 < m2) << '\n';
    cout << boolalpha << (m1 > m2) << '\n';
    cout << boolalpha << (m1 <= m2) << '\n';
    cout << boolalpha << (m1 >= m2) << '\n';
    cout << boolalpha << (m1 == m2) << '\n';

    return 0;
}

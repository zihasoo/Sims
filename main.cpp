#include <exception>
#include <iostream>

class NegativeDeposit : public std::exception {
public:
    const char *what() const noexcept override {
        return "값이 0또는 음수가 될 수 없습니다.";
    }
};

class InsufficientFunds : public std::exception {
public:
    const char *what() const noexcept override {
        return "자금이 불충분합니다.";
    }
};


class Account {
private:
    double balance;
public:
    Account() {
        balance = 0;
    }

    Account(double initialDeposit) {
        balance = initialDeposit;
    }

    double getBalance() const {
        return balance;
    }

    // returns new balance or -1 if error
    double deposit(double amount) {
        if (amount <= 0)
            throw NegativeDeposit();

        balance += amount;
        return balance;
    }

    // returns new balance or -1 if invalid amount
    double withdraw(double amount) {
        if ((amount > balance) || (amount < 0))
            throw InsufficientFunds();

        balance -= amount;
        return balance;
    }
};

int main(){
    auto a = Account{10};
    try {
        a.deposit(-10);
    }
    catch (NegativeDeposit& e) {
        std::cout << "NegativeDeposit Exception: " << e.what() << '\n';
    }

    try {
        a.withdraw(100);
    }
    catch (InsufficientFunds& e) {
        std::cout << "InsufficientFunds Exception: " << e.what() << '\n';
    }
}
/*Imagine you are developing a banking application in C++, and you have a class BankAccount that 
represents individual bank accounts. Within this class, you need to implement a method withdraw for
 withdrawing money from an account. The withdraw method should be defined outside the class using 
 the scope resolution operator ::. This method should access the account balance (a member variable)
  and deduct the withdrawal amount, ensuring that the balance is not negative.*/

#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initial_balance) {
        balance = initial_balance;
    }

    void display_balance() {
        cout << "Current balance: " << balance << endl;
    }
    void withdraw(double amount);
};

// Definition of the withdraw method outside the class using ::
void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrawn: " << amount << endl;
    } else {
        cout << "Invalid withdrawal amount or insufficient balance" << endl;
    }
}

int main() {
    BankAccount account(1000.0);
    account.display_balance();

    // Withdraw money from the account using the defined method
    account.withdraw(500.0);
    account.display_balance();

    account.withdraw(700.0); // Attempting to withdraw more than the balance

    return 0;
}

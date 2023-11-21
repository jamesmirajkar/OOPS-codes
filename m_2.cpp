/*Suppose you are building a banking application, and you need to calculate the compound interest 
on a savings account for a user. The user enters the principal amount, interest rate, and the 
number of years, and your program needs to calculate the amount they will have in their account 
after a specified number of years. You want to create a utility class that can perform this 
compound interest calculation.*/

#include <iostream>
#include <cmath>

class BankingUtility {
public:
    static double calculateCompoundInterest(double principal, double rate, int years) {
        if (principal < 0 || rate < 0 || years < 0) {
            std::cout << "Invalid input values. Please provide non-negative values." << std::endl;
            return 0.0;
        }
        
        double amount = principal * pow(1 + (rate / 100), years);
        return amount;
    }
};

int main() {
    double principal, rate;
    int years;

    std::cout << "Enter the principal amount: ";
    std::cin >> principal;

    std::cout << "Enter the annual interest rate (in percentage): ";
    std::cin >> rate;

    std::cout << "Enter the number of years: ";
    std::cin >> years;

    double result = BankingUtility::calculateCompoundInterest(principal, rate, years);

    if (result > 0) {
        std::cout << "After " << years << " years, you will have: Rs" << result << std::endl;
    }

    return 0;
}

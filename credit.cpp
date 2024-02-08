// credit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const double fixedCredit = 10;
const double creditPerc = 0.01;
const double maxPenaltyPerc = 0.20;
const double midPenaltyPerc = 0.10;
const double lowPenaltyPerc = 0.05;
const double midPenaltyLow = 0.20;
const double midPenaltyHigh = 0.50;

int main()
{
    double balance, payment, credit = 0, penalty = 0;
    cout << "Enter current balance: ";
    cin >> balance;
    cout << "Enter current payment amount: ";
    cin >> payment;

    if (balance - payment <= 0) {
        credit = balance * creditPerc;
        if (credit > 10)
            credit = 10;
    }
    else if (payment / balance >= midPenaltyHigh) {
        penalty = (balance - payment) * lowPenaltyPerc;
    }

    else if (payment / balance < midPenaltyLow) {
        penalty = (balance - payment) * maxPenaltyPerc;
    }

    else
        penalty = (balance - payment) * midPenaltyPerc;

    if (penalty > 0) {
        cout << "you have penalty of $" << penalty << endl;
        cout << "remaining balanace $" << balance - payment + penalty;
    }

    else
        cout << "credit of $" << credit << endl;
}

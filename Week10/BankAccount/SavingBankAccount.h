#pragma once
#include "BankAccount.h"
class SavingBankAccount : public BankAccount {
private:
    double interestRate;
public:
    SavingBankAccount() = default;
    SavingBankAccount(int ID, double balance, double interestRate);

    double getinterestRate() const;

    void setInterestRate(double interestRate);

    void calculateInterest();
};
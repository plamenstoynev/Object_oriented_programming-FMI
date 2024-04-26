#pragma once
#include "BankAccount.h"
class LoanAccount : public BankAccount{
private:
    double interest;
public:
    LoanAccount() = default;
    LoanAccount(int ID, double balance);

    void accrueInterest();
};
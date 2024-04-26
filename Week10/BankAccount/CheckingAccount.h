#pragma once
#include "BankAccount.h"
class CheckingAccount : public BankAccount {
public:
    CheckingAccount() = default;
    CheckingAccount(int ID, double balance);

    void withdraw(double amount);
};
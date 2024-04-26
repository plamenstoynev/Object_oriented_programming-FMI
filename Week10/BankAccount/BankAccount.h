#pragma once
#include <iostream>
#include <exception>
class BankAccount {
private:
    int ID = 0;
protected:
    double balance;
public:
    BankAccount() = default;
    BankAccount(int ID, double balance);

    int getID() const;
    double getBalance() const;

    void setID(int ID);
    void setBalance(double balance);

    void deposit(double amount);
    void withdraw(double amount);
};
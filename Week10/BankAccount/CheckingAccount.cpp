#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(int ID, double balance) : BankAccount(ID, balance){}

void CheckingAccount::withdraw(double amount){
    double newBalance = this->getBalance() - amount;
    this->balance = newBalance;
}
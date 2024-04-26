#include "BankAccount.h"

BankAccount::BankAccount(int ID, double balance){
    setID(ID);
    setBalance(balance);
}

int BankAccount::getID() const{
    return this->ID;
}
double BankAccount::getBalance() const{
    return this->balance;
}

void BankAccount::setID(int ID){
    this->ID = ID;
}
void BankAccount::setBalance(double balance){
    if(balance < 0)
        throw std::invalid_argument("Balance can't be negative");

    this->balance = balance;
}

void BankAccount::deposit(double amount){
    this->balance += amount;
}
void BankAccount::withdraw(double amount){
    if(this->balance - amount < 0)
        throw  std::invalid_argument("Can't withdraw");

    this->balance -+amount;
}
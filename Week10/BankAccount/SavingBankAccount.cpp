#include "SavingBankAccount.h"

SavingBankAccount::SavingBankAccount(int ID, double balance, double interestRate) : BankAccount(ID, balance) {
    setInterestRate(interestRate);
}

double SavingBankAccount::getinterestRate() const{
    return interestRate;
}

void SavingBankAccount::setInterestRate(double interestRate){
    if(interestRate < 0)
        throw std::invalid_argument("Interest rate can't be zero or under it");

    this->interestRate = interestRate;
}

void SavingBankAccount::calculateInterest(){
    double addMoney = this->getBalance() * this->interestRate;
    this->setBalance(this->getBalance() + addMoney);
}
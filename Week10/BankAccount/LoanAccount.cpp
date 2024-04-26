#include "LoanAccount.h"
LoanAccount::LoanAccount(int ID, double balance) : BankAccount(ID, balance){}

void LoanAccount::accrueInterest(){
    double balanceAfterLoan = this->balance * (this->interest/365) * 12;
    this->balance = balanceAfterLoan;
}
#include <iostream>
#include "BankAccount.h"

int main(){
    BankAccount account1(1, 1000);
    BankAccount account2(2, 2000);
    BankAccount account3(3, 3000);

    account1.deposit(100);
    account2.withdraw(200);
    account3.deposit(300);

    std::cout << "Account 1 balance: " << account1.getBalance() << std::endl;
    std::cout << "Account 2 balance: " << account2.getBalance() << std::endl;
    std::cout << "Account 3 balance: " << account3.getBalance() << std::endl;

    return 0;
}
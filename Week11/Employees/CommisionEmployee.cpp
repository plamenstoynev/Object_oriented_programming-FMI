#include "CommisionEmployee.h"

CommisionEmployee::CommisionEmployee(const MyString& name, double salary, double commision) : Employee(name, salary){
    this->commision = commision;
}

double CommisionEmployee::calculateSalary() const{
    return this->getSalary() + this->getSalary() * this->commision;
}
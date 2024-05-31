#include "HourlyEmployee.h"

HourlyEmployee::HourlyEmployee(const MyString& name, double salary, unsigned overtime) : Employee(name, salary){
    this->overtime = overtime;
}
double HourlyEmployee::calculateSalary() const {
    return 40 * 4 * this->getSalary() + this->getSalary() * 0.5 * this->overtime;
}
#include "Employee.h"


Employee::Employee(const MyString& name, double salary){
    this->name = name;
    this->salary = salary;
}

MyString Employee::getName() const{
    return this->name;
}
double Employee::getSalary() const {
    return this->salary;
}

std::ostream& operator<<(std::ostream& os, const Employee& employee){
    return os << "name: "<< employee.getName() << " salary: " << employee.getSalary() << std::endl;
}
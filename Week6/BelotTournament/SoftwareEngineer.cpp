#include "SoftwareEngineer.h"

SoftwareEngineer::SoftwareEngineer(const char* name, unsigned salary) {
    setName(name);
    setSalary(salary);
}

SoftwareEngineer::SoftwareEngineer(const SoftwareEngineer &other) {
    copyFrom(other);
}

SoftwareEngineer& SoftwareEngineer::operator=(const SoftwareEngineer &other) {
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

const char* SoftwareEngineer::getName() {
    return this->name;
}

unsigned SoftwareEngineer::getSalary() {
    return this->salary;
}

void SoftwareEngineer::setName(const char *name) {
    if(!name || name != this->name){
        unsigned lengthName = strlen(name);
        this->name = new char[lengthName + 1];
        strcpy(this->name, name);
    }
    else
        return;
}

void SoftwareEngineer::setSalary(unsigned salary) {
    if(salary < 0)
        return;
    else
        this->salary = salary;
}

SoftwareEngineer::~SoftwareEngineer() {
    free();
}

void SoftwareEngineer::copyFrom(const SoftwareEngineer &other) {
    unsigned lengthName = strlen(other.name);
    this->name = new char [lengthName + 1];
    strcpy(this->name, name);

    this->salary = other.salary;
}

void SoftwareEngineer::free() {
    delete[] this->name;
    this->name = nullptr;

    this->salary = 0;
}
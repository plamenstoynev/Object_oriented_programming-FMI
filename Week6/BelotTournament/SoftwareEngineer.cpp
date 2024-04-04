#include "SoftwareEngineer.h"

SoftwareEngineer::SoftwareEngineer(const char* name, double salary) {
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

double SoftwareEngineer::getSalary() {
    return this->salary;
}

void SoftwareEngineer::setName(const char *name) {
    if(!name || name != this->name){
        unsigned lengthName = stelen(name);
        this->name = new char[lengthName];
        strcpy(this->name, name);
    }
    else
        return;
}

void SoftwareEngineer::setSalary(double salary) {
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
    this->name = new char [lengthName];
    strcpy(this->name, name);

    this->salary = salary;
}

void SoftwareEngineer::free() {
    delete[] name;
    name = nullptr;

    salary = 0;
}
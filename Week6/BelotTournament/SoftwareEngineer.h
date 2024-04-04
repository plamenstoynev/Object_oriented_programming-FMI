#pragma once
#include <cstring>

class SoftwareEngineer {
private:
    char* name = nullptr;
    double salary = 0;

public:
    SoftwareEngineer() = default;
    SoftwareEngineer(const char* name, double salary);
    SoftwareEngineer(const SoftwareEngineer& other);
    SoftwareEngineer& operator=(const SoftwareEngineer& other);

    const char* getName();
    double getSalary();

    void setName(const char* name);
    void setSalary(double salary);

    ~SoftwareEngineer();

private:
    void copyFrom(const SoftwareEngineer& other);
    void free();
};
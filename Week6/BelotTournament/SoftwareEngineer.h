#pragma once
#include <cstring>

class SoftwareEngineer {
private:
    char* name = nullptr;
    unsigned salary = 0;

public:
    SoftwareEngineer() = default;
    SoftwareEngineer(const char* name, unsigned salary);
    SoftwareEngineer(const SoftwareEngineer& other);
    SoftwareEngineer& operator=(const SoftwareEngineer& other);

    const char* getName();
    unsigned getSalary();

    void setName(const char* name);
    void setSalary(unsigned salary);

    ~SoftwareEngineer();

private:
    void copyFrom(const SoftwareEngineer& other);
    void free();
};
#pragma once
#include <cstring>
#include <iostream>

constexpr unsigned lengthName = 33;

class File {
protected:
    char name[lengthName];
public:
    File(const char* name);
    virtual ~File() = default;
    const char* getName() const;
    virtual void printContent() const = 0;
};
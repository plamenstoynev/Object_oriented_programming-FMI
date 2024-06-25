#pragma once
#include <iostream>

constexpr size_t size = 26;

class BooleanInterpretation {
private:
    bool values[size]{false};
public:
    void set(char ch, bool value);
    bool operator()(char ch) const;
    size_t getTrueCount() const;
    void excludeValuesByMask(unsigned mask);
};
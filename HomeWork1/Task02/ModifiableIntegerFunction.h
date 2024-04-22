#pragma once
#include <cstdint>
#include <ostream>

struct numSaver{
    int num;
    bool isAvailable = true;
};

constexpr unsigned sizeOfNums = INT16_MAX;

class ModifiableIntegerFunction {
private:
    numSaver nums[sizeOfNums];
public:
    ModifiableIntegerFunction() = default;
    ModifiableIntegerFunction(int16_t(*function)(int16_t num));
    ModifiableIntegerFunction& operator+(const ModifiableIntegerFunction& other);
    ModifiableIntegerFunction& operator-(const ModifiableIntegerFunction& other);
    ModifiableIntegerFunction& operator^(int16_t num);

    bool isInjection() const;
    bool isSurjection() const;
    bool isBijection() const;
    bool isReverse() const;

    int16_t getValue(int16_t num) const;
    bool getAvailable(int16_t num) const;
    const numSaver* getNumSaver() const;

    void setValue(int16_t num, int16_t value);
    void setAvailable(int16_t num, bool available);
    void setNumSaver(const numSaver* nums);

    friend void readFromBinaryFile(std::istream& is, ModifiableIntegerFunction& set);
    friend void readFromBinaryFile(const char* FILE_NAME, ModifiableIntegerFunction& set);

private:
};

bool operator==(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
bool operator>(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
bool operator>=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
bool operator<(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
bool operator<=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);

void saveToBinaryFile(std::ostream& os, const ModifiableIntegerFunction& set);
void saveToBinaryFile(const char* FILE_NAME, const ModifiableIntegerFunction& set);


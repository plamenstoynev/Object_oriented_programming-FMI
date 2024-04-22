#pragma once
#include <cstdint>
#include <exception>
#include <cmath>
#include <fstream>

constexpr unsigned sizeOfBucket = sizeof(uint8_t) * 8;

class MultiSet {
private:
    uint8_t* buckets = nullptr;
    unsigned n = 0;
    unsigned k = 0;
    unsigned lengthOfBucket = 0;
public:
    MultiSet() = default;
    MultiSet(unsigned k , unsigned n);
    MultiSet(const MultiSet& other);
    MultiSet& operator=(const MultiSet& other);

    void addNum(unsigned num);
    unsigned timesInMultiSet(unsigned num) const;

    friend MultiSet cross(const MultiSet& lhs, const MultiSet& rhs);
    friend MultiSet minus(const MultiSet& lhs, const MultiSet& rhs);

    void printNums() const;
    void printBinary() const;

    bool checkNum(unsigned num) const;

    friend void saveToBinaryFile(std::ostream& os, const MultiSet& set);
    friend void saveToBinaryFile(const char* FILE_NAME, const MultiSet& set);
    friend void readFromBinaryFile(std::istream& is, MultiSet& set);
    friend void readFromBinaryFile(const char* FILE_NAME, MultiSet& set);

    void resize();

    ~MultiSet();
private:
    void copyFrom(const MultiSet& other);
    void free();

    void makeZeros(unsigned num);
    void printBinary(uint8_t num) const;
};

#pragma once
#include <cstdint>
#include <iostream>

constexpr unsigned MAX_NUMS = 1023;
constexpr unsigned MAX_NUMS_COUNT = MAX_NUMS + 1;
constexpr unsigned BUCKET_SIZE = sizeof(uint8_t);
constexpr unsigned BUCKET_COUNT = MAX_NUMS / BUCKET_SIZE;

class BitSet {
private:
    uint8_t buckets[BUCKET_COUNT] {0};

public:
    void addNUmber(unsigned num);
    void removeNUmber(unsigned num);
    bool contains(unsigned num) const;
    void print() const;

    friend BitSet& combine(const BitSet& lhs, const BitSet& rhs);
    friend BitSet& cross(const BitSet& lhs, const BitSet& rhs);
};
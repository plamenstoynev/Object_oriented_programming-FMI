#include "BitSet.h"

void BitSet::addNUmber(unsigned int num) {
    unsigned bucketIndex = num / BUCKET_SIZE;
    unsigned bitIndex = num % BUCKET_SIZE;
    unsigned mask = 1 << bitIndex;

    this->buckets[bucketIndex] |= mask;
}

void BitSet::removeNUmber(unsigned int num) {
    unsigned bucketIndex = num / BUCKET_SIZE;
    unsigned bitIndex = num % BUCKET_SIZE;
    unsigned mask = 1 << bitIndex;

    this->buckets[bucketIndex] &= ~mask;
}

bool BitSet::contains(unsigned int num) const {
    unsigned bucketIndex = num / BUCKET_SIZE;
    unsigned bitIndex = num % BUCKET_SIZE;
    unsigned mask = 1 << bitIndex;

    return (this->buckets[bucketIndex] & mask) != 0;
}

void BitSet::print() const{
    std::cout << "{";
    for(unsigned i = 0; i < MAX_NUMS_COUNT; i++){
        if(contains(i))
            std::cout << i << " ";
    }
    std::cout << "}" << std::endl;
}

BitSet& combine(const BitSet& lhs, const BitSet& rhs){
    BitSet result;
    for(unsigned i = 0; i < MAX_NUMS_COUNT; i++)
        result.buckets[i] = lhs.buckets[i]  | rhs.buckets[i];

    return result;
}

BitSet& cross(const BitSet& lhs, const BitSet& rhs){
    BitSet result;
    for(unsigned i = 0; i < MAX_NUMS_COUNT; i++)
        result.buckets[i] = lhs.buckets[i]  & rhs.buckets[i];

    return result;
}
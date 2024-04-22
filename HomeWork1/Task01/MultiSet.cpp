#include <iostream>
#include "MultiSet.h"

MultiSet::MultiSet(unsigned k , unsigned n){
    if(k < 1 || k > 8 || n < 0)
        throw std::invalid_argument("Invalid arguments");
    this->k = k;
    this->n = n;
    this->lengthOfBucket = ((k * (n + 1)) / sizeOfBucket) + 1;
    this->buckets = new uint8_t[this->lengthOfBucket];
    for(unsigned i = 0; i < this->lengthOfBucket; i++)
        this->buckets[i] = 0;
}
MultiSet::MultiSet(const MultiSet& other){
    copyFrom(other);
}
MultiSet& MultiSet::operator=(const MultiSet& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

void MultiSet::addNum(unsigned num) {
    unsigned bucketIndex = (num * this->k) / sizeOfBucket;
    unsigned bitIndex = (num * this->k) % sizeOfBucket;

    unsigned mask = 1 << bitIndex;

    if (!checkNum(num))
        this->buckets[bucketIndex] |= mask;
    else {
        unsigned times = timesInMultiSet(num);
        times++;
        if(times > std::pow(2, this->k) - 1)
            throw std::invalid_argument("Can't add more times");

        unsigned helperK = this->k;
        makeZeros(num);
        while(helperK != 0){
            if(times % 2 == 1){
                this->buckets[bucketIndex] |= mask;
            }
            mask = mask << 1;
            bitIndex++;
            if(bitIndex == sizeOfBucket){
                bucketIndex++;
                bitIndex = 0;
            }
            helperK--;
            times = times >> 1;
        }
    }
}
unsigned MultiSet::timesInMultiSet(unsigned num) const{
    unsigned bucketIndex = (num * this->k) / sizeOfBucket;
    unsigned bitIndex = 1 << ((num * this->k) % sizeOfBucket);
    unsigned helper = 0;
    unsigned result = 0;
    while(helper != this->k){
        if (bitIndex == 0){
            bucketIndex++;
            bitIndex = 1 << 0;
        }
        if((this->buckets[bucketIndex] & bitIndex) != 0){
            result += std::pow(2, helper);
        }
        bitIndex = bitIndex << 1;
        helper++;
    }
    return result;
}

MultiSet cross(const MultiSet& lhs, const MultiSet& rhs) {
    unsigned count = 0;
    if (lhs.k > rhs.k) {
        if (lhs.n > rhs.n) {
            MultiSet result(lhs.k, lhs.n);
            for (unsigned i = 0; i < rhs.n; i++) {
                if (lhs.checkNum(i) && rhs.checkNum(i)) {
                    count =  lhs.timesInMultiSet(i) < rhs.timesInMultiSet(i) ? lhs.timesInMultiSet(i) : rhs.timesInMultiSet(i);
                    if (count != 0) {
                        for (unsigned j = 0; j < count; j++) {
                            result.addNum(i);
                        }
                    }
                }
            }
            return result;
        } else {
            MultiSet result(lhs.k, rhs.n);
            for (unsigned i = 0; i < rhs.n; i++) {
                if (lhs.checkNum(i) && rhs.checkNum(i)) {
                    count =  lhs.timesInMultiSet(i) < rhs.timesInMultiSet(i) ? lhs.timesInMultiSet(i) : rhs.timesInMultiSet(i);
                    if (count != 0) {
                        for (unsigned j = 0; j < count; j++) {
                            result.addNum(i);
                        }
                    }
                }
            }
            return result;
            }
        }
        else {
        if (lhs.n > rhs.n) {
            MultiSet result(rhs.k, lhs.n);
            for (unsigned i = 0; i < rhs.n; i++) {
                if (lhs.checkNum(i) && rhs.checkNum(i)) {
                    count =  lhs.timesInMultiSet(i) < rhs.timesInMultiSet(i) ? lhs.timesInMultiSet(i) : rhs.timesInMultiSet(i);
                    if (count != 0) {
                        for (unsigned j = 0; j < count; j++) {
                            result.addNum(i);
                        }
                    }
                }
            }
            return result;
        } else {
            MultiSet result(rhs.k, rhs.n);
            for (unsigned i = 0; i < rhs.n; i++) {
                if (lhs.checkNum(i) && rhs.checkNum(i)) {
                    count =  lhs.timesInMultiSet(i) < rhs.timesInMultiSet(i) ? lhs.timesInMultiSet(i) : rhs.timesInMultiSet(i);
                    if (count != 0) {
                        for (unsigned j = 0; j < count; j++) {
                            result.addNum(i);
                        }
                    }
                }
            }
            return result;
        }
    }
}

MultiSet minus(const MultiSet& lhs, const MultiSet& rhs){
    unsigned count = 0;
    if (lhs.k > rhs.k) {
        if (lhs.n > rhs.n) {
            MultiSet result(lhs.k, lhs.n);
            for (unsigned i = 0; i < rhs.n; i++) {
                if (lhs.checkNum(i) && !rhs.checkNum(i)) {
                    count =  lhs.timesInMultiSet(i);
                    if (count != 0) {
                        for (unsigned j = 0; j < count; j++) {
                            result.addNum(i);
                        }
                    }
                }
            }
            return result;
        } else {
            MultiSet result(lhs.k, rhs.n);
            for (unsigned i = 0; i < rhs.n; i++) {
                if (lhs.checkNum(i) && !rhs.checkNum(i)) {
                    count =  lhs.timesInMultiSet(i);
                    if (count != 0) {
                        for (unsigned j = 0; j < count; j++) {
                            result.addNum(i);
                        }
                    }
                }
            }
            return result;;
        }
    }
    else {
        if (lhs.n > rhs.n) {
            MultiSet result(rhs.k, lhs.n);
            for (unsigned i = 0; i < rhs.n; i++) {
                if (lhs.checkNum(i) && !rhs.checkNum(i)) {
                    count =  lhs.timesInMultiSet(i);
                    if (count != 0) {
                        for (unsigned j = 0; j < count; j++) {
                            result.addNum(i);
                        }
                    }
                }
            }
            return result;
        } else {
            MultiSet result(rhs.k, rhs.n);
            for (unsigned i = 0; i < rhs.n; i++) {
                if (lhs.checkNum(i) && !rhs.checkNum(i)) {
                    count =  lhs.timesInMultiSet(i);
                    if (count != 0) {
                        for (unsigned j = 0; j < count; j++) {
                            result.addNum(i);
                        }
                    }
                }
            }
            return result;
        }
    }
}

void MultiSet::printNums() const{
    for(unsigned i = 0; i < this->n; i++){
        if(checkNum(i))
            std::cout << i << " ";
    }
}

void MultiSet::printBinary(uint8_t num) const{
    for (int i = 7; i >= 0; --i) {
        std::cout << ((num >> i) & 1);
    }
    std::cout << std::endl;
}

void MultiSet::printBinary() const{
    for(unsigned i = 0; i < this->lengthOfBucket; i++)
        printBinary(this->buckets[i]);
}

bool MultiSet::checkNum(unsigned num) const {
    return timesInMultiSet(num) != 0;
}


void saveToBinaryFile(std::ostream& os, const MultiSet& set){
    os.write((const char *) &set.n, sizeof(set.n));
    os.write((const char *) &set.k, sizeof(set.k));
    os.write((const char *) &set.lengthOfBucket, sizeof(set.lengthOfBucket));
    os.write((const char *) set.buckets, sizeof(uint8_t) * set.lengthOfBucket);
}
void saveToBinaryFile(const char* FILE_NAME, const MultiSet& set){
    std::ofstream file(FILE_NAME, std::ios::binary);
    if(!file.is_open())
        throw std::invalid_argument("File not opened");

    saveToBinaryFile(file, set);
}

void readFromBinaryFile(std::istream& is, MultiSet& set) {
    is.read((char *) &set.n, sizeof(set.n));
    is.read((char *) &set.k, sizeof(set.k));
    is.read((char *) &set.lengthOfBucket, sizeof(set.lengthOfBucket));
    set.buckets = new uint8_t[set.lengthOfBucket];
    is.read((char *) set.buckets, sizeof(uint8_t) * set.lengthOfBucket);
}

void readFromBinaryFile(const char* FILE_NAME, MultiSet& set){
    std::ifstream file(FILE_NAME, std::ios::binary);
    if(!file.is_open())
        throw std::invalid_argument("File not opened");

    readFromBinaryFile(file, set);
}

void MultiSet::resize() {
    for (unsigned i = 0; i < this->n; i++) {
        if (checkNum(i)) {
            unsigned count = timesInMultiSet(i);
            unsigned newCount = std::pow(2, this->k) - 1 - count;
            makeZeros(i);
            while (newCount != 0) {
                addNum(i);
                newCount--;
            }
        }
    }
}

MultiSet::~MultiSet(){
    free();
}

void MultiSet::copyFrom(const MultiSet& other){
    this->k = other.k;
    this->n = other.n;
    this->lengthOfBucket = other.lengthOfBucket;
    this->buckets = new uint8_t[this->lengthOfBucket];

    for(unsigned i = 0; i < this->lengthOfBucket; i++)
        this->buckets[i] = other.buckets[i];
}

void MultiSet::free(){
    delete[] this->buckets;
    this->buckets = nullptr;

    this->n = 0;
    this->k = 0;
    this->lengthOfBucket = 0;
}

void MultiSet::makeZeros(unsigned int num) {
    unsigned bucketIndex = (num * this->k) / sizeOfBucket;
    unsigned bitIndex = 1 << (num * this->k) % sizeOfBucket;
    unsigned helper = 0;
    unsigned mask;
    while(helper != this->k){
        if(bitIndex == 0){
            bucketIndex++;
            bitIndex = 1 << 0;
        }
        this->buckets[bucketIndex] &= ~bitIndex;
        bitIndex = bitIndex << 1;
        helper++;
    }
}
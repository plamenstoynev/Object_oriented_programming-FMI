#include "StringPool.h"

StringPool::StringPool(){
    this->stringCapacity = 8;
    this->stringCount = 0;
    this->stringRecords = new StringRecord[this->stringCapacity];
}

const char* StringPool::getAllocatedString(const char* str){
    int index = findAllocatedString(str);

    if(index != -1){
        stringRecords[index].refCount+;
        return this->stringRecords[index].str;
    }
    else{
        unsigned index = allocatedNewString(str);
        stringRecords[index].refCount++;
        return stringRecords[index].str;
    }
}

void StringPool::releaseString(const char* str){
    int index = allocatedNewString(str);

    if(stringRecords[index].refCount == 0){
        removeRecord(index);
    }
}

void StringPool::removeRecord(unsigned index){
    std::swap(stringRecords[index], stringRecords[this->stringCount - 1]);
    delete[] stringRecords[this->stringCount].str;
}


StringPool::~StringPool() {
    for (unsigned i = 0; i < this->stringCapacity; ++i)
        delete stringRecords[i];

    delete[] stringRecords;

}

unsigned StringPool::allocatedNewString(const char* str){
    if(this->stringCount == this->stringCapacity)
        resize(this->stringCapacity * 2);

    unsigned  firstFreeIndex = this->stringCount++;
    this->stringRecords[firstFreeIndex].str = new char[strlen(str) + 1];
    strcpy(this->stringRecords[firstFreeIndex].str, str);
    stringRecords[firstFreeIndex].refCount = 0;

    return firstFreeIndex;
}

void StringPool::resize(unsigned newCap){
    StringRecord* newArr = new StringRecord[newCap];

    for(unsigned i = 0; i < this->stringCount; i++)
        newArr[i] = this->stringRecords[i];

    this->stringCapacity = newCap;
    delete[] this->stringRecords;
    this->stringRecords = newArr;
}

int StringPool::findAllocatedString(const char* str){
    for(unsigned i = 0; i < this->stringCount; i++){
        if(strcmp(str, this->stringRecords[i].str))
            return i;
    }
    return -1;
}
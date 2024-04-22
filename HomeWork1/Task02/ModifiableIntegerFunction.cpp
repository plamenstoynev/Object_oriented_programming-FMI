#include <fstream>
#include "ModifiableIntegerFunction.h"

ModifiableIntegerFunction::ModifiableIntegerFunction(int16_t(*function)(int16_t num)){
    for(unsigned i = 0; i < sizeOfNums; i++)
        this->nums[i].num = function(i);
}
ModifiableIntegerFunction& ModifiableIntegerFunction::operator+(const ModifiableIntegerFunction& other){
    for(unsigned i = 0; i < sizeOfNums; i++){
        if(this->nums[i].isAvailable && other.nums[i].isAvailable)
            this->nums[i].num += other.nums[i].num;
    }
    return *this;
}
ModifiableIntegerFunction& ModifiableIntegerFunction::operator-(const ModifiableIntegerFunction& other){
    for(unsigned i = 0; i < sizeOfNums; i++){
        if(this->nums[i].isAvailable && other.nums[i].isAvailable)
            this->nums[i].num -= other.nums[i].num;
    }
    return *this;
}
ModifiableIntegerFunction& ModifiableIntegerFunction::operator^(int16_t num){
for(unsigned i = 0; i < sizeOfNums; i++){
        if(this->nums[i].isAvailable)
            this->nums[i].num = this->nums[i].num ^ num;
    }
    return *this;
}

int16_t ModifiableIntegerFunction::getValue(int16_t num) const{
    return this->nums[num].num;
}
bool ModifiableIntegerFunction::getAvailable(int16_t num) const{
    return this->nums[num].isAvailable;
}
const numSaver* ModifiableIntegerFunction::getNumSaver() const{
    return this->nums;
}

bool ModifiableIntegerFunction::isInjection() const{
    for(unsigned i = 0; i < sizeOfNums; i++){
        if(this->nums[i].isAvailable){
            for(unsigned j = i + 1; j < sizeOfNums; j++){
                if(this->nums[j].isAvailable && this->nums[i].num == this->nums[j].num)
                    return false;
            }
        }
    }
}
bool ModifiableIntegerFunction::isSurjection() const{
    for(unsigned i = 0; i < sizeOfNums; i++){
        if(this->nums[i].isAvailable){
            bool isFound = false;
            for(unsigned j = 0; j < sizeOfNums; j++){
                if(this->nums[j].isAvailable && this->nums[i].num == this->nums[j].num){
                    isFound = true;
                    break;
                }
            }
            if(!isFound)
                return false;
        }
    }
}
bool ModifiableIntegerFunction::isBijection() const{
    return this->isInjection() && this->isSurjection();
}
bool ModifiableIntegerFunction::isReverse() const {
    for(unsigned i = 0; i < sizeOfNums; i++){
        if(this->nums[i].isAvailable){
            for(unsigned j = 0; j < sizeOfNums; j++){
                if(this->nums[j].isAvailable && this->nums[i].num == this->nums[j].num && i != j)
                    return false;
            }
        }
    }
}
void ModifiableIntegerFunction::setValue(int16_t num, int16_t value){
    this->nums[num].num = value;
}
void ModifiableIntegerFunction::setAvailable(int16_t num,bool available){
    this->nums[num].isAvailable = available;
}
void ModifiableIntegerFunction::setNumSaver(const numSaver* nums){
    for(unsigned i = 0; i < sizeOfNums; i++)
        this->nums[i] = nums[i];
}

bool operator==(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs){
    for(unsigned i = 0; i < sizeOfNums; i++){
        if (lhs.getAvailable(i) && rhs.getAvailable(i) && lhs.getAvailable(i) < rhs.getAvailable(i))
            return false;
    }
    return true;
}
bool operator>(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs){
    for(unsigned i = 0; i < sizeOfNums; i++) {
        if (lhs.getAvailable(i) && rhs.getAvailable(i) && lhs.getValue(i) <= rhs.getValue(i))
            return false;
    }
    return true;
}
bool operator>=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs){
    return lhs > rhs || lhs == rhs;
}
bool operator<(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs){
    for(unsigned i = 0; i < sizeOfNums; i++) {
        if (lhs.getAvailable(i) && rhs.getAvailable(i) && lhs.getValue(i) >= rhs.getValue(i))
            return false;
    }
    return true;
}
bool operator<=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs){
    return lhs < rhs || lhs == rhs;
}

void saveToBinaryFile(std::ofstream& os, const ModifiableIntegerFunction& set){
    os.write((const char*)set.getNumSaver(), sizeof(numSaver) * sizeOfNums);
}
void saveToBinaryFile(const char* FILE_NAME, const ModifiableIntegerFunction& set){
    std::ofstream file(FILE_NAME, std::ios::binary);
    if(!file.is_open())
        throw std::invalid_argument("File cannot be opened!");

    saveToBinaryFile(file, set);
}

void readFromBinaryFile(std::ifstream& is, ModifiableIntegerFunction& set){
    numSaver* nums = new numSaver[sizeOfNums];
    is.read((char*)nums, sizeof(numSaver) * sizeOfNums);
    set.setNumSaver(nums);
    delete[] nums;

}

void readFromBinaryFile(const char* FILE_NAME, ModifiableIntegerFunction& set) {
    std::ifstream file(FILE_NAME, std::ios::binary);
    if (!file.is_open())
        throw std::invalid_argument("File cannot be opened!");

    readFromBinaryFile(file, set);
}
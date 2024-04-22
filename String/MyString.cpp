#include "MyString.h"

static unsigned roundToPowerOfTwo(unsigned v)//this function is not made by me
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

static unsigned dataToAllocByStringLen(unsigned stringLength)//this function is not made by me
{
    return std::max(roundToPowerOfTwo(stringLength + 1), 16u);
}

MyString::MyString(const char* str){
    this->size = std::strlen(str);
    this->capacity = dataToAllocByStringLen(this->size);

    this->str = new char[this->capacity];
    std::strcpy(this->str, str);
}

MyString::MyString(const MyString& other){
    copyFrom(other);
}

MyString::MyString(MyString &&other) {
    moveFrom(std::move(other));
}

MyString& MyString::operator=(const MyString& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

MyString& MyString::operator=(MyString &&other) {
    if(this != &other){
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

size_t MyString::getSize() const{
    return this->size - 1;
}

size_t MyString::getCapacity() const{
    return this->capacity;
}

const char* MyString::c_str() const{
    return this->str;
}

MyString& MyString::operator+=(const MyString& other){
    if(getSize() + other.getSize() >= getCapacity())
        resize(dataToAllocByStringLen(getSize() + other.getSize()));

    std::strncat(this->str, other.str, other.getSize());
    this->size = getSize() + other.getSize();

    return *this;
}

char& MyString::operator[](size_t index){
    return this->str[index];
}

const char& MyString::operator[](size_t index) const{
    return this->str[index];
}

std::ostream& operator<<(std::ostream& os, const MyString& str){
    return os << str.str;
}

std::istream& operator>>(std::istream & is, MyString& str){
    char buffer[1024];
    is >> buffer;
    size_t buffLength = std::strlen(buffer);

    if(buffLength > str.size)
        str.resize(dataToAllocByStringLen(buffLength));

    strcpy(str.str, buffer);
    str.size = buffLength;

    return is;
}

MyString::~MyString(){
    free();
}

void MyString::resize(unsigned int newAllocatedDataSize) {
    char* newStr = new char[newAllocatedDataSize + 1];
    std::strcpy(newStr, this->str);
    delete[] this->str;
    this->str = newStr;

    this->size = newAllocatedDataSize;
}

void MyString::copyFrom(const MyString &other) {
    this->size = other.size;
    this->capacity = other.capacity;

    this->str = new char[other.size];
    strcpy(this->str, other.str);
}

void MyString::moveFrom(MyString &&other) {
    this->str = other.str;
    other.str = nullptr;

    this->size = other.size;
    other.size = 0;

    this->capacity = other.capacity;
    other.capacity = 0;
}

void MyString::free() {
    delete[] str;
    str = nullptr;

    size = 0;
    capacity = 0;
}

bool operator==(const MyString& lhs, const MyString& rhs){
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const MyString& lhs, const MyString& rhs){
    return !(lhs == rhs);
}

bool operator<(const MyString& lhs, const MyString& rhs){
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs){
    return lhs < rhs || lhs == rhs;
}

bool operator>(const MyString& lhs, const MyString& rhs){
    return !(lhs < rhs);
}

bool operator>=(const MyString& lhs, const MyString& rhs){
    return (lhs <= rhs);
}
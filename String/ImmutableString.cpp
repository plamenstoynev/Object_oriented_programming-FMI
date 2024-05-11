#include "ImmutableString.h"

ImmutableString::ImmutableString(const char* str){
    this->data = this->pool.getAllocatedString(str);
}
ImmutableString::ImmutableString(const ImmutableString& other){
    copyFrom(other);
}

size_t ImmutableString::getLength() const{
    return this->length;
}
char ImmutableString::operator[](size_t index) const{
    return this->data[index];
}
const char* ImmutableString::c_str() const{
    return this->data;
}

ImmutableString::~ImmutableString(){
    free();
}

void ImmutableString::copyFrom(const ImmutableString& other){
    this->data = pool.getAllocatedString(other.data);
}
void ImmutableString::free(){
    this->pool.releaseString(this->data);
    this->data = nullptr;
}

ImmutableString::ImmutableString(size_t capacity){

}

std::ostream& operator<<(std::ostream& os, const ImmutableString& str){
    return os << str.c_str();
}

bool operator<(const ImmutableString& lhs, const ImmutableString& rhs){
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}
bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs){
    return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs){
    return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
bool operator>(const ImmutableString& lhs, const ImmutableString& rhs){
    return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator==(const ImmutableString& lhs, const ImmutableString& rhs){
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs){
    return !(lhs == rhs);
}
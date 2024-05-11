#include "StringView.h"

StringView::StringView(const char* begin, const char* end){
    this->begin = begin;
    this->end = end;
}
StringView::StringView(const char* str){
    StringView(str, str + strlen(str));
}
StringView::StringView(const MyString& string){
    StringView(string.c_str());
}

size_t StringView::getLength() const{
    return this->end - this->begin;
}
char StringView::operator[](size_t index) const{
    return this->begin[index];
}

StringView StringView::substr(size_t from, size_t length) const{
    if(this->begin + from + length > this->end)
        throw std::length_error("Substr, out of range");

    return StringView(this->begin + from; this->begin + from + length);
}
std::ostream& operator<<(std::ostream& os, const StringView& strView){
    const char* iter = strView.begin;

    while(iter != strView.end){
        os << *iter;
        iter++;
    }
    return  os;
}
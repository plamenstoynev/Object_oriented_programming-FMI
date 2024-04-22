#pragma once
#include <iostream>
#include <cstring>
class MyString {
private:
    char* str = nullptr;
    size_t capacity = 0;
    size_t size = 0;

public:
    MyString() = default;
    MyString(const char* str);
    MyString(const MyString& other);
    MyString(MyString&& other);
    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other);

    size_t getSize() const;
    size_t getCapacity() const;

    const char* c_str() const;

    MyString& operator+=(const MyString& other);

    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream & is, MyString& str);

    ~MyString();

private:
    void resize(unsigned newAllocatedDataSize);

    void copyFrom(const MyString& other);
    void moveFrom(MyString&& other);
    void free();
};

bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
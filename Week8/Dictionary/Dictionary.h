#pragma once
#include "C:\Users\plame\CLionProjects\OOP_Pract\String\MyString.h"
class Dictionary {
private:
    MyString* words;
    MyString* description;
    size_t size;
    size_t capacity;
public:
    Dictionary() = default;
    Dictionary(MyString* words, MyString* description, size_t sizeOfWords);
    Dictionary(const Dictionary& other);
    Dictionary& operator=(const Dictionary& other);
    Dictionary& operator+=(const Dictionary& word);

    void add(const MyString& word);
    void remove(const MyString& word);

    MyString operator()(const MyString& word);

    friend void resize(const Dictionary& dictionary);

    ~Dictionary();
private:
    void copyFrom(const Dictionary& other);
    void free();

    bool checkWord(const MyString& word);
};
Dictionary& operator+(const Dictionary& lhs, const Dictionary& rhs);
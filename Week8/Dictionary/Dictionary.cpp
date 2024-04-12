#include "Dictionary.h"

Dictionary::Dictionary(MyString* words, MyString* description, size_t sizeOfWords){

}

Dictionary::Dictionary(const Dictionary& other){

}

Dictionary& Dictionary::operator=(const Dictionary& other){

}

Dictionary& Dictionary::operator+=(const Dictionary& word){

}

void Dictionary::add(const MyString& word){

}

void Dictionary::remove(const MyString& word){

}

MyString Dictionary::operator()(const MyString& word){

}

Dictionary::~Dictionary(){

}

void Dictionary::copyFrom(const Dictionary& other){

}

void Dictionary::free(){
    delete[] this->words;
    delete[] this->description;

    this->words = nullptr;
    this->description = nullptr;
}

bool Dictionary::checkWord(const MyString& word){

}

Dictionary& operator+(const Dictionary& lhs, const Dictionary& rhs){

}

void resize(const Dictionary& dictionary){
    if(dictionary.capacity)
}
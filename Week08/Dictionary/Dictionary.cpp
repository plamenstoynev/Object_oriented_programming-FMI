#include "Dictionary.h"

Dictionary::Dictionary(MyString* words, MyString* description, size_t sizeOfWords){
    for(unsigned i = 0; i < sizeOfWords; i++){
        this->words[i] = words[i];
        this->description[i] = description[i];
    }
    this->size = sizeOfWords;
}

Dictionary::Dictionary(const Dictionary& other){
    copyFrom(other);
}

Dictionary& Dictionary::operator=(const Dictionary& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

Dictionary& Dictionary::operator+=(const Dictionary& word){

}

void Dictionary::add(const MyString& word){
    if(this->capacity > this->size){
        resize(*this);
    }
    this->words[capacity] = word;

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

void resize(Dictionary& dictionary){
    dictionary.size *= 2;
}
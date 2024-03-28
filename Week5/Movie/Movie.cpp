#include "Movie.h"

Movie::Movie(const char* name, const char* producer,const Time& duration, uint8_t genre){
    setName(name);
    setProducer(producer);
    setDuration(duration);
    setGenre(genre);
}

const char* Movie::getName() const{
    return this->name;
}

const char* Movie::getProducer() const{
    return this->Producer;
}

Time Movie::getTime() const{
    return this->duration;
}

void Movie::setName(const char* name){
    if(isValidName(name))
        strcpy(this->name, name);
    else
        std::cout << "The name is not valid" << std::endl;
}

void Movie::setProducer(const char* Producer){
    strcpy(this->Producer, Producer);
}

void Movie::setDuration(const Time& duration){
    this->duration = duration;
}

void Movie::setGenre(uint8_t genre) {
    this->genre = genre;
}

bool Movie::checkGenre(Genre genre){
    return(this->genre & genre) != 0;
}

void Movie::addGenre(Genre genre){
    this->genre |= genre;
}

void Movie::removeGenre(Genre genre){
    this->genre &= ~genre;
}
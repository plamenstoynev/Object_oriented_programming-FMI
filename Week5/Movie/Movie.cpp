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
    strcpy(this->name, name);
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

bool Movie::checkGenre(Genre genre) const{
    return(this->genre & genre) != 0;
}

void Movie::addGenre(Genre genre){
    this->genre |= genre;
}

void Movie::removeGenre(Genre genre){
    this->genre &= ~genre;
}

void Movie::printGenres() const {
    for(unsigned i = startGenre(); i < endGenre(); i = iterateGenre((Genre)i)) {
        if (checkGenre((Genre) i)) {
            getGenre((Genre) i);
            std::cout << "/";
        }
    }
}
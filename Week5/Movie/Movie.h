#pragma once
#include <cstring>
#include "helper.h"
#include "Time.h"

class Movie {
private:
    char name[100];
    char Producer[200];
    Time duration;
    uint8_t genre;

public:
    Movie() = default;
    Movie(const char* name, const char* producer,const Time& duration, uint8_t genre);

    const char* getName() const;
    const char* getProducer() const;
    Time getTime() const;

    void setName(const char* name);
    void setProducer(const char* Producer);
    void setDuration(const Time& duration);
    void setGenre(uint8_t genre);


    bool checkGenre(Genre genre);
    void addGenre(Genre genre);
    void removeGenre(Genre genre);
};
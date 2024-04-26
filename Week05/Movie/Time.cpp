#include "Time.h"

Time::Time(unsigned seconds){
    this->hours = seconds / 3600;
    this->minutes = (seconds % 3600) / 60;
    this->seconds = seconds % 60;
}

Time::Time(unsigned hours, unsigned minutes, unsigned seconds){
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

unsigned Time::getSeconds() const{
    return this->seconds;
}

unsigned Time::getMinutes() const{
    return this->minutes;
}

unsigned Time::getHours() const{
    return this->hours;
}


void Time::setSeconds(unsigned minutes){
    this->seconds = seconds;
}

void Time::setMinutes(unsigned minutes){
    this->minutes = minutes;
}

void Time::setHour(unsigned hours){
    this->hours = hours;
}
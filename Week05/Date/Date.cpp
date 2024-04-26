#include <iostream>
#include "Date.h"

Date::Date(unsigned day, unsigned month, unsigned year){
    setYear(year);
    setMonth(month);
    setDay(day);
}

bool Date::isLeapYear() const{
    if (year <= 1916)
        return year % 4 == 0;
    else
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void Date::validateDate(){
    isDateValid =  !((month == 0 || month > 12) ||
                     (day == 0 || day > MAX_DAYS[month - 1]) ||
                     (year == 0) ||
                     (year == 1916 && month == 4 && day < 14));
}

unsigned Date::getDay() const{
    return this->day;
}

unsigned Date::getMonth() const{
    return this->month;
}

unsigned Date::getYear() const{
    return this->year;
}

void Date::setDay(unsigned day){
    if(day < this->MAX_DAYS[this->month])
        this->day = day;
    else
        return;
}

void Date::setMonth(unsigned month){
    if(month >=1 && month <= 12)
        this->month = month;
    else
        return;
}

void Date::setYear(unsigned year){
    this->year = year;
}

void Date::print() const{
    std::cout << "DD/MM/YYYY: " << this->day << "/" << this->month << "/" << this->year << std::endl;
}

void Date::goToNextDay(){
    this->day++;
    if(this->day > this->MAX_DAYS[this->month]){
        this->day = 1;
        this->month++;
        if(this->month> 12)
            this->month = 1;
    }
}
int Date::getDayOfWeek() {
    if(!good()) return -1;
    if (!isModified)
        return this->dayOfWeek;

    Date d(1,1,1);
    int day = 5; //0 for monday, 6 for sunday (We know that 1.1.1 is saturday)

    while (compareBulgarianDates(d, *this) != 0)  //very simple (but dumb) algorithm
    {
        d.goToNextDay();
        day++;
        day %= 7;
    }
    this->dayOfWeek = day + 1; //1 for monday, 7 fo sunday
    this->isModified = false;
    return dayOfWeek;
}

bool Date::good() const{
    return this->isDateValid;
}

void Date::clear(){
    this->isDateValid = true;
    this->day = this->month = this->year = 1;
}

int compareBulgarianDates(const Date& lhs, const Date& rhs) {
    if (lhs.getYear() < rhs.getYear()) {
        return -1;
    } else if (lhs.getYear() > rhs.getYear()) {
        return 1;
    } else { // years are equal, compare months
        if (lhs.getMonth() < rhs.getMonth()) {
            return -1;
        } else if (lhs.getMonth() > rhs.getMonth()) {
            return 1;
        } else { // months are equal, compare days
            if (lhs.getDay() < rhs.getDay()) {
                return -1;
            } else if (lhs.getDay() > rhs.getDay()) {
                return 1;
            } else {
                return 0; // All are equal
            }
        }
    }
}
#ifndef OOP_PRACT_DATE_H
#define OOP_PRACT_DATE_H
#pragma once

class Date{
private:
    unsigned MAX_DAYS[12]  {31,28,31,30,31, 30, 31, 31, 30, 31, 30, 31};

    unsigned day;
    unsigned month;
    unsigned year;

    bool isLeapYear() const;
    void validateDate();

    bool isDateValid = true;
    bool isModified = true;
    int dayOfWeek = -1;

public:
    Date() = default;
    Date(unsigned day, unsigned month, unsigned year);
    unsigned getDay() const;
    unsigned getMonth() const;
    unsigned getYear() const;

    void setDay(unsigned day);
    void setMonth(unsigned month);
    void setYear(unsigned year);

    void print() const;
    void goToNextDay();
    int getDayOfWeek();

    bool good() const;
    void clear();
};
int compareBulgarianDates(const Date& lhs, const Date& rhs);

#endif //OOP_PRACT_DATE_H

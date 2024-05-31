#pragma once
#include <iostream>
#include "../../String/MyString.h"
class StringViewer {
public:
    virtual char operator[](size_t index) const = 0;
    virtual size_t length() const  = 0;
    virtual bool isEmpty() const = 0;
    virtual void removeSuffix(size_t count) = 0;
    virtual void removePrefix(size_t count) = 0;
    virtual StringViewer* substr(size_t pos, size_t count) = 0;
    virtual int indexOf() const = 0;
};


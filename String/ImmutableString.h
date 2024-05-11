#pragma once
#include "StringPool.h"
class ImmutableString {
private:
    const char* data;
    size_t length;
    static StringPool pool;

public:
    ImmutableString(const char* str);
    ImmutableString(const ImmutableString& other);
    ImmutableString& operator=(const ImmutableString& other) = delete;

    size_t getLength() const;
    char operator[](size_t index) const;
    const char* c_str() const;

    ~ImmutableString();

private:
    void copyFrom(const ImmutableString& other);
    void free();

    explicit ImmutableString(size_t capacity);
};

std::ostream& operator<<(std::ostream& os, const ImmutableString& str);

bool operator<(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator==(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs);
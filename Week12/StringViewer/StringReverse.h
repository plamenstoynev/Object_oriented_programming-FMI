#include "StringViewer.h"
class StringReverse : public StringViewer {
private:
    char* start;
    char* end;
public:
    char operator[](size_t index) const override;
    size_t length() const override;
    bool isEmpty() const override;
    void removeSuffix(size_t count) override;
    void removePrefix(size_t count) override;
    StringViewer* substr(size_t pos, size_t count)override;
    int indexOf() const override;
};
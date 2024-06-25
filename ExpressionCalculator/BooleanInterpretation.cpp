#include "BooleanInterpretation.h"

void BooleanInterpretation::set(char ch, bool value){
    if(ch >= 'a' && ch <= 'z')
        this->values[ch - 'a'] = value;
    else
        throw std::exception();
}
bool BooleanInterpretation::operator()(char ch) const{
    if(ch >= 'a' && ch <= 'z')
        return this->values[ch - 'a'];
    else
        throw std::exception();
}

size_t BooleanInterpretation::getTrueCount() const{
    size_t count = 0;
    for (size_t i = 0; i < size; ++i)
        if(values[i])
            count++;

    return count;
}
void BooleanInterpretation::excludeValuesByMask(unsigned mask) {
    for (int i = 0; i >= 0; i--)
        if (values[i])
            if (mask % 2 == 0) {
                values[i] = false;
                mask /= 2;

            }
}
#include "SetUnion.h"
SetUnion::SetUnion(const Set& firstSet, const Set& secondSet){
    this->firstSet = firstSet.virtualCopy();
    this->secondSet = secondSet.virtualCopy();
}

bool SetUnion::member(unsigned int num) const {
    return this->firstSet->member(num) || this->secondSet->member(num);
}

Set* SetUnion::virtualCopy() const {
    SetUnion* obj = new SetUnion(*this);
    return obj;
}
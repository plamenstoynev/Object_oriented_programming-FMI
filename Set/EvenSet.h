#pragma once
#include "Set.h"
class EvenSet : public Set{
public:
    bool member(unsigned int x)const;
    Set* virtualCopy() const;
    virtual ~EvenSet() = default;
};
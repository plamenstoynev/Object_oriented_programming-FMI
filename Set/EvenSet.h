#pragma once
#include "Set.h"
class EvenSet : public Set{
public:
    bool member(unsigned int num) const override;
    Set* virtualCopy() const override;
    ~EvenSet() override;
};
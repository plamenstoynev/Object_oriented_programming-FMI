#pragma once
#include "Set.h"
class EmptySet : public Set{
public:
    bool member(unsigned num) const override;
    Set* virtualCopy() const override;
    virtual ~EmptySet() = default;
};
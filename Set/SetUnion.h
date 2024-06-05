#pragma once
#include "Set.h"
class SetUnion : public Set{
private:
    const Set* firstSet = nullptr;
    const Set* secondSet = nullptr;
public:
    SetUnion() = default;
    SetUnion(const Set& firstSet, const Set& secondSet);
    Set* virtualCopy() const override;

    bool member(unsigned int num) const override;

    virtual ~SetUnion() = default;
};
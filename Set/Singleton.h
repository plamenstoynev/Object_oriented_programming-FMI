#pragma once
#include "Set.h"
class Singleton : public Set{
private:
    unsigned int num;
public:
    Singleton() = default;
    Singleton(unsigned int num);
    Set* virtualCopy() const override;

    bool member(unsigned int num) const override;

    virtual ~Singleton() = default;
};
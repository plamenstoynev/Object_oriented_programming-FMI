#pragma once
class Set {
public:
    virtual bool member(unsigned int x) const = 0;
    virtual Set* virtualCopy() const;
    virtual ~Set();
};
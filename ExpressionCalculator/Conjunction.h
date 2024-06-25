#pragma once
#include "BinaryOperation.h"
class Conjunction : public BinaryOperation{
public:
    Conjunction(BooleanExpression* left, BooleanExpression* right);
    BooleanExpression* clone() const override;
    bool evaluate(const BooleanInterpretation& interpret) const override;
};
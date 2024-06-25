#pragma once
#include "BinaryOperation.h"
class Implies : public BinaryOperation{
public:
    Implies(BooleanExpression* left, BooleanExpression* right);
    BooleanExpression* clone() const override;
    bool evaluate(const BooleanInterpretation& interpret) const override;
};
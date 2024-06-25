#pragma once
#include "BinaryOperation.h"

class Disjunction : public BinaryOperation {
public:
    Disjunction(BooleanExpression* left, BooleanExpression* right);
    BooleanExpression* clone() const override;
    bool evaluate(const BooleanInterpretation& interpret) const override;
};
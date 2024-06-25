#pragma once
#include "BooleanExpression.h"
class BinaryOperation : public BooleanExpression {
protected:
    BooleanExpression* left;
    BooleanExpression* right;
public:
    BinaryOperation(BooleanExpression* left, BooleanExpression* right);
    void populateVariables(BooleanInterpretation& interpret) const override;
    ~BinaryOperation();
};
#pragma once
#include "BooleanExpression.h"
class UnaryOperation : public BooleanExpression {
protected:
    BooleanExpression* expr;
public:
    UnaryOperation(BooleanExpression* expr);

    void populateVariables(BooleanInterpretation& interpret) const override;

    ~UnaryOperation();
};
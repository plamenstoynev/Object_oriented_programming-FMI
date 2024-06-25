#pragma once
#include "BooleanExpression.h"
class Var : public  BooleanExpression {
private:
    char ch;
public:
    Var() = default;
    Var(char ch);

    bool evaluate(const BooleanInterpretation& interpret) const override;
    void populateVariables(BooleanInterpretation& interpret) const override;

    virtual BooleanExpression* clone() const override;
};
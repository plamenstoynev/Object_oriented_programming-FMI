#pragma once
#include "UnaryOperation.h"
class Negation : public UnaryOperation {
public:
    Negation(BooleanExpression* expr);

    virtual BooleanExpression* clone() const override;
    bool evaluate(const BooleanInterpretation& interpret) const override;
};
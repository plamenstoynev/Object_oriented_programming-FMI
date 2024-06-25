#pragma once
#include "BooleanInterpretation.h"
class BooleanExpression {
public:
    BooleanExpression() = default;
    BooleanExpression(const BooleanExpression& other) = delete;
    BooleanExpression operator=(const BooleanExpression& other) = delete;

    virtual bool evaluate(const BooleanInterpretation& interpret) const = 0;
    virtual void populateVariables(BooleanInterpretation& interpret) const = 0;

    virtual BooleanExpression* clone() const = 0;
    virtual ~BooleanExpression() = default;
};
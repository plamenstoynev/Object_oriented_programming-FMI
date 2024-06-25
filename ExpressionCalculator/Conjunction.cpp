#include "Conjunction.h"
Conjunction::Conjunction(BooleanExpression *left, BooleanExpression *right) : BinaryOperation(left, right){}

BooleanExpression *Conjunction::clone() const {
    return new Conjunction(left->clone(), right->clone());
}

bool Conjunction::evaluate(const BooleanInterpretation &interpret) const {
    return left->evaluate(interpret) && right->evaluate(interpret);
}
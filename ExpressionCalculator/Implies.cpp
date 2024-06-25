#include "Implies.h"

Implies::Implies(BooleanExpression *left, BooleanExpression *right) : BinaryOperation(left, right){}

BooleanExpression *Implies::clone() const {
    return new Implies(left->clone(), right->clone());
}

bool Implies::evaluate(const BooleanInterpretation &interpret) const {
    return !(left->evaluate(interpret) || right->evaluate(interpret));
}
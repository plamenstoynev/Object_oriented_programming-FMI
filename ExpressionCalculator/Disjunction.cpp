#include "Disjunction.h"

Disjunction::Disjunction(BooleanExpression *left, BooleanExpression *right) : BinaryOperation(left, right){}

BooleanExpression *Disjunction::clone() const {
    return new Disjunction(left->clone(), right->clone());
}

bool Disjunction::evaluate(const BooleanInterpretation &interpret) const {
    return left->evaluate(interpret) || right->evaluate(interpret);
}
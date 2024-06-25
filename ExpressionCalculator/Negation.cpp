#include "Negation.h"

Negation::Negation(BooleanExpression* expr) : UnaryOperation(expr){}

BooleanExpression* Negation::clone() const {
    return new Negation(expr->clone())
}
bool Negation::evaluate(const BooleanInterpretation& interpret) const{
    return !expr->evaluate(interpret);
}
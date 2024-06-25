#include "UnaryOperation.h"

UnaryOperation::UnaryOperation(BooleanExpression* expr) : expr(expr){}

void UnaryOperation::populateVariables(BooleanInterpretation& interpret) const {
    expr->populateVariables(interpret);
}

UnaryOperation::~UnaryOperation(){
    delete expr;
    expr = nullptr;
}
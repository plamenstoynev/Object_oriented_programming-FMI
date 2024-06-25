#include "BinaryOperation.h"

BinaryOperation::BinaryOperation(BooleanExpression *left, BooleanExpression *right) : left(left), right(right){}

void BinaryOperation::populateVariables(BooleanInterpretation &interpret) const {
    left->populateVariables(interpret);
    right->populateVariables(interpret);
}

BinaryOperation::~BinaryOperation() {
    delete left;
    delete right;

    left = nullptr;
    right = nullptr;
}
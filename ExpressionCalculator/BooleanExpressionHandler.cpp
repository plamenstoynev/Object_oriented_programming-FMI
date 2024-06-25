#include "BooleanExpressionHandler.h"

BooleanExpressionHandler::BooleanExpressionHandler(const MyString& str){
    this->expr = expressionFactory(str);
}
BooleanExpressionHandler::BooleanExpressionHandler(const BooleanExpressionHandler& other){
    copyFrom(other);
}
BooleanExpressionHandler& BooleanExpressionHandler::operator=(const BooleanExpressionHandler& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return this;
}
BooleanExpressionHandler::BooleanExpressionHandler(const BooleanExpressionHandler&& other){
    moveFrom(std::move(other));
}
BooleanExpressionHandler& BooleanExpressionHandler::operator=(const BooleanExpressionHandler&& other){
    if(this != &other){
        free();
        moveFrom(std::move(other));
    }
}

bool BooleanExpressionHandler::evaluate(const BooleanInterpretation& bi) const{
    return this->expr->evaluate(bi);
}
bool BooleanExpressionHandler::isTautology() const{
    return checkAllTrueAssignments(true);
}
bool BooleanExpressionHandler::isContradiction() const{
    return checkAllTrueAssignments(false);
}

BooleanExpressionHandler::~BooleanExpressionHandler() {
    free();
}

bool BooleanExpressionHandler::checkAllTrueAssignments(bool value) const{
    size_t varsCount = myVariables.getTrueCount();
    size_t powerOfTwo = 1 << varsCount;
    for(int i = 0; i < powerOfTwo; i++){
        BooleanInterpretation current = myVariables;
        current.excludeValuesByMask(i);
        if(expr->evaluate(current) != value)
            return false;
    }
}
void BooleanExpressionHandler::free(){
    deletete expr;
}
void BooleanExpressionHandler::copyFrom(BooleanExpressionHandler& other){
    expr = other.expr;
}
void BooleanExpressionHandler::moveFrom(BooleanExpressionHandler&& other){
    expr = other.expr;
    other.expr = nullptr;
}
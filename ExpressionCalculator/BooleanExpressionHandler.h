#pragma once
#include "Factory.cpp"
#include "../String/MyString.h"

class BooleanExpressionHandler {
private:
    BooleanInterpretation myVariables;
    BooleanExpression* expr = nullptr;

public:
    BooleanExpressionHandler(const MyString& str);
    BooleanExpressionHandler(const BooleanExpressionHandler& other);
    BooleanExpressionHandler& operator=(const BooleanExpressionHandler& other);
    BooleanExpressionHandler(const BooleanExpressionHandler&& other);
    BooleanExpressionHandler& operator=(const BooleanExpressionHandler&& other);

    bool evaluate(const BooleanInterpretation& bi) const;
    bool isTautology() const;
    bool isContradiction() const;

    ~BooleanExpressionHandler();

private:
    bool checkAllTrueAssignments(bool value) const;
    void free();
    void copyFrom(BooleanExpressionHandler& other);
    void moveFrom(BooleanExpressionHandler&& other);
};
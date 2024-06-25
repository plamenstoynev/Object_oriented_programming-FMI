#include "Var.h"

Var::Var(char ch) : ch (ch){}

bool Var::evaluate(const BooleanInterpretation& interpret) const {
    return interpret(ch);
};

void Var::populateVariables(BooleanInterpretation &interpret) const {
    interpret.set(ch, true);
}
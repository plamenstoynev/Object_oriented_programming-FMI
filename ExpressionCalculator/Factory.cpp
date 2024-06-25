#include "BooleanExpression.h"
#include "Var.h"
#include "BinaryOperation.h"
#include "Negation.h"
#include "Disjunction.h"
#include "Implies.h"
#include "Conjunction.h"
#include "../String/StringView.h"

BooleanExpression* expressionFactory(StringView str){
    str = str.substr(1, str.getLength() - 2);

    if(str.getLength() == 1)
        return new Var;
    
    unsigned count = 0;
    
    for(int i = 0; i < str.getLength(); i++){
        if(str[i] == '(')
            count++;
        else if(str[i] == ')')
            count--;
        else if(count == 0){
            switch (str[i]) {
                case '!': return new Negation(expressionFactory(str.substr(i+1, str.getLength() - i - 1)));
                case '&': return new Conjunction(expressionFactory(str.substr(0, i)), expressionFactory(str.substr(i+1, str.getLength() - i - 1)));
                case '|': return new Disjunction(expressionFactory(str.substr(0, i)), expressionFactory(str.substr(i+1, str.getLength() - i -1)));
                case '>': return new Implies(expressionFactory(str.substr(0, i)), expressionFactory(str.substr(i+1,str.getLength() - i -1)));
            }
        }
    }
}
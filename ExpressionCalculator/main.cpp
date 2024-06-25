#include "BooleanExpressionHandler.h"

int main(){
    BooleanExpressionHandler be("((p)|((q)&(t)))");
    BooleanInterpretation bi;
    bi.set('p', true);
    std::cout << be.evaluate(bi) << std::endl;
    BooleanExpressionHandler be2("((p)|(!(p)))");
    std::cout << be2.isTautology() << std::endl;
    return 0;
}
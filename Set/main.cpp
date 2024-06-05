#include  <iostream>
#include "Set.h"
#include "Singleton.h"
#include "EvenSet.h"
#include "EmptySet.h"
#include "SetUnion.h"

int main(){
    Set* set1 = new Singleton(5);
    Set* set2 = new EvenSet();
    Set* set3 = new EmptySet();
    Set* set4 = new SetUnion(*set1, *set2);

    std::cout << set1->member(5) << std::endl;
    std::cout << set2->member(5) << std::endl;
    std::cout << set3->member(5) << std::endl;
    std::cout << set4->member(5) << std::endl;

    delete set1;
    delete set2;
    delete set3;
    delete set4;
    return 0;
}
#include  <iostream>
#include "Set.h"
#include "Singleton.h"
#include "EvenSet.h"
#include "EmptySet.h"
#include "SetUnion.h"

int main(){
    Singleton s(5);
    /*EmptySet e;
    EvenSet ev;
    SetUnion u(s, e);
    SetUnion u2(s, ev);
    SetUnion u3(u, u2);

    std::cout << u3.member(5) << std::endl;
    */return 0;
}
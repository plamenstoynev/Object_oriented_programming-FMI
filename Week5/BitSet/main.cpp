#include "BitSet.h"

int main() {
    BitSet bs1;
    bs1.addNUmber(1);
    bs1.addNUmber(2);
    bs1.addNUmber(3);

    bs1.removeNUmber(2);

    std::cout << bs1.contains(1) << std::endl;

    std::cout << "BitSet1:" << std::endl;
    bs1.print();

    BitSet bs2;
    bs2.addNUmber(2);
    bs2.addNUmber(3);
    bs2.addNUmber(4);

    std::cout << "BitSet2:" << std::endl;
    bs2.print();


    BitSet bs3 = combine(bs1, bs2);

    std::cout << "BitSet3:" << std::endl;
    bs3.print();


    BitSet bs4 = cross(bs1, bs2);

    std::cout << "BitSet4:" << std::endl;
    bs4.print();

    return 0;
}

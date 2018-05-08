#include<iostream>
#include "ArrayList.h"

int main()
{
    auto* arrayList = new ArrayList(5);
    arrayList->print();
    arrayList->add(1);
    arrayList->add(2);
    arrayList->add(3);
    arrayList->add(4);
    arrayList->add(5);
    arrayList->print();
    arrayList->add(6);
    arrayList->print();
    arrayList->add(6, 7);
    arrayList->print();
    arrayList->add(3, 9999);
    arrayList->print();

    arrayList->removeRange(1, 3);
    arrayList->print();

    arrayList->clear();
    arrayList->print();
    arrayList->add(1);
    arrayList->print();
//
//
//    arrayList->add(45, 1);
////    std::cout << arrayList->size << std::endl;
    return 0;
}

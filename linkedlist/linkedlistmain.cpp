#include<iostream>
#include "LinkedList.h"

int main()
{
    auto* lst = new LinkedList();
    lst->print();
    lst->add(1);
    lst->print();
    lst->add(2);
    lst->print();
    lst->add(3);
    lst->print();
    lst->add(1, 7);
    lst->print();
    return 0;
}

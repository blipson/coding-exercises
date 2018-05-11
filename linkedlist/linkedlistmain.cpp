#include<iostream>
#include "LinkedList.h"

int main()
{
    auto* lst = new LinkedList();
    lst->print();
    lst->add(2, 7);
    lst->print();
    return 0;
}

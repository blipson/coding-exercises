#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList()
{
    this->head = nullptr;
    this->size = 0;
}

LinkedList::~LinkedList()
{
    std::cout << "LINKED LIST DELETED" << std::endl;
}

void LinkedList::print()
{
    Node* current = this->head;
    std::cout << "[";
    int i = 0;
    while (current != nullptr)
    {
        if (i > 0)
        {
            std::cout<< ",";
        }
        std::cout << current->data;
        i++;
        current = current->next;
    }
    std::cout << "]";
}

bool LinkedList::add(int e)
{
    if (this->head == nullptr)
    {
        this->head = new Node();
        this->head->data = e;
        this->head->next = nullptr;
    }
    else
    {
        auto* n = new Node();
        n->data = e;
        n->next = nullptr;

        Node* current = this->head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = n;
    }
    this->size++;
    return true;
}

void LinkedList::add(int index, int e)
{
    int i = 0;
    Node* current = nullptr;
    while (i <= index)
    {
        if (i == 0)
        {
            current = this->head;
        }
        else
        {
            current = current->next;
        }
        i++;
    }
    Node* atIndex = current;

    int j = 0;
    int temp;
    int temp2;
    bool end = false;
    while (!end)
    {
        if (j == 0)
        {
            temp = current->next->data;
            current->next->data = current->data;
            current = current->next;
        }
        else
        {
            if (current->next == nullptr)
            {
                temp2 = temp;
                end = true;
            }
            else
            {
                temp2 = current->next->data;
                current->next->data = temp;
                temp = temp2;
                current = current->next;
            }
        }
        j++;
    }
    atIndex->data = e;
    current->next = new Node();
    current->next->data = temp2;
}

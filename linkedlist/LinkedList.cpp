#include <iostream>
#include "LinkedList.h"
#include "LinkedListOutOfBoundsException.h"

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
    if (index > size-1)
    {
        throw LinkedListOutOfBoundsException(index);
    }
    int i = 0;
    auto* current = new Node();
    if (this->head != nullptr)
    {
        while (i < index)
        {
            if (i == 0)
            {
                current = this->head;
            } else
            {
                current = current->next;
            }
            i++;
        }
    }
    auto* insert = new Node();
    insert->data = e;

    if (current->next != nullptr)
    {
        Node* prevIndex = current;
        insert->next = prevIndex->next;
        prevIndex->next = insert;
    }
    else
    {
        this->head = insert;
    }
    size++;
}

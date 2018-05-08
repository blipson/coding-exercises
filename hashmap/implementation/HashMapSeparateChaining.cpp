#include <iostream>
#include "../headers/HashMapSeparateChaining.h"
#include "../headers/HashKeyDuplicateElementException.h"
#include "../headers/HashKeyElementNotFoundException.h"

HashMapSeparateChaining::HashMapSeparateChaining()
{
    for (auto &i : hashTable)
    {
        i = nullptr;
    }
}

int HashMapSeparateChaining::hash(std::string key)
{
    int hash = 0;
    int index;

    for (char i : key)
    {
        hash += (int) i;
    }

    index = hash % tableSize;

    return index;
}

void HashMapSeparateChaining::put(std::string key, std::string value)
{
    int index = hash(key);
    if (hashTable[index] == nullptr)
    {
        hashTable[index] = new HashEntrySeparateChaining(key, value);
    } else
    {
        HashEntrySeparateChaining* currentItem = hashTable[index];
        auto* newItem = new HashEntrySeparateChaining(key, value);
        if (currentItem->getKey() == key)
        {
            throw HashKeyDuplicateElementException(key);
        }
        while (currentItem->getNext() != nullptr)
        {
            if (currentItem->getNext()->getKey() == key)
            {
                throw HashKeyDuplicateElementException(key);
            }
            currentItem = currentItem->getNext();
        }
        currentItem->setNext(newItem);
    }
}

HashEntrySeparateChaining HashMapSeparateChaining::get(std::string key)
{
    for (auto &i : hashTable)
    {
        if (i != nullptr)
        {
            if (i->getKey() == key)
            {
                return *i;
            }
            HashEntrySeparateChaining* currentItem = i;
            while (currentItem->getNext() != nullptr)
            {
                if (currentItem->getNext()->getKey() == key)
                {
                    return *currentItem->getNext();
                }
                currentItem = currentItem->getNext();
            }
        }
    }
    throw HashKeyNotFoundException(key);
}

int HashMapSeparateChaining::numberOfItemsInIndex(int index)
{
    int count = 0;
    if (hashTable[index] == nullptr)
    {
        return count;
    } else
    {
        count++;
        HashEntrySeparateChaining* currentItem = hashTable[index];
        while (currentItem->getNext() != nullptr)
        {
            count++;
            currentItem = currentItem->getNext();
        }
    }
    return count;
}

void HashMapSeparateChaining::printTable()
{
    int number;
    for (int i = 0; i < tableSize; i++)
    {
        number = numberOfItemsInIndex(i);
        std::cout << "----------------------------" << std::endl;
        std::cout << "index  = " << i << std::endl;
        if (hashTable[i] != nullptr)
        {
            std::cout << hashTable[i]->getKey().append(", ").append(hashTable[i]->getValue()) << std::endl;
            HashEntrySeparateChaining* current = hashTable[i];
            while (current->getNext() != nullptr)
            {
                std::cout << current->getNext()->getKey().append(", ").append(current->getNext()->getValue())
                          << std::endl;
                current = current->getNext();
            }
        }
        std::cout << "# of items = " << number << std::endl;
        std::cout << "----------------------------" << std::endl;
    }
}

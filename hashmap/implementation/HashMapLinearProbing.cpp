#include "../headers/HashMapLinearProbing.h"
#include "../headers/HashKeyElementNotFoundException.h"
#include <iostream>

HashMapLinearProbing::HashMapLinearProbing()
{
    table = new HashEntryLinearProbing* [tableSize];
    for (int i = 0; i < tableSize; i++)
    {
        table[i] = nullptr;
    }
}

HashEntryLinearProbing HashMapLinearProbing::get(std::string key)
{
    int hash = 0;
    while (table[hash] != nullptr && table[hash]->getKey() != key)
    {
        hash = (hash + 1) % tableSize;
        if (hash == 0)
        {
            throw HashKeyNotFoundException(key);
        }
    }
    if (table[hash] == nullptr)
    {
        throw HashKeyNotFoundException(key);
    }
    return *table[hash];
}

void HashMapLinearProbing::put(std::string key, std::string value)
{
    int hash = 0;
    while (table[hash] != nullptr)
    {
        hash = (hash + 1) % tableSize;
        if (hash == 0)
        {
            break;
        }
    }
    table[hash] = new HashEntryLinearProbing(key, value);
}

void HashMapLinearProbing::printTable()
{
    for (int i = 0; i < tableSize; i++)
    {
        std::cout << "----------------------------" << std::endl;
        std::cout << "index  = " << i << std::endl;
        if (table[i] != nullptr)
        {
            std::cout << table[i]->getKey().append(", ").append(table[i]->getValue()) << std::endl;
        }
        std::cout << "----------------------------" << std::endl;
    }
}

std::string* HashMapLinearProbing::getAll(std::string key)
{
    auto* all = new std::string[tableSize];
    int next = 0;
    for (int i = 0; i < tableSize; i++)
    {
        if (this->table[i] != nullptr)
        {
            if (this->table[i]->getKey() == key)
            {
                all[next] = this->table[i]->getValue();
                next++;
            }
        }
    }
    return all;
}

HashMapLinearProbing::~HashMapLinearProbing()
{
    for (int i = 0; i < tableSize; i++)
    {
        if (table[i] != 0)
        {
            delete table[i];
        }
    }
    delete[] table;
}

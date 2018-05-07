#include "../headers/HashEntrySeparateChaining.h"

HashEntrySeparateChaining::HashEntrySeparateChaining(std::string key, std::string value)
{
    this->key = key;
    this->value = value;
    this->next = nullptr;
}

std::string HashEntrySeparateChaining::getKey()
{
    return this->key;
}

std::string HashEntrySeparateChaining::getValue()
{
    return this->value;
}

HashEntrySeparateChaining* HashEntrySeparateChaining::getNext()
{
    return this->next;
}

void HashEntrySeparateChaining::setNext(HashEntrySeparateChaining* next)
{
    this->next = next;
}

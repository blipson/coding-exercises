#include "../headers/HashEntryLinearProbing.h"

HashEntryLinearProbing::HashEntryLinearProbing(std::string key, std::string value)
{
    this->key = key;
    this->value = value;
}

std::string HashEntryLinearProbing::getKey()
{
    return this->key;
}

std::string HashEntryLinearProbing::getValue()
{
    return this->value;
}

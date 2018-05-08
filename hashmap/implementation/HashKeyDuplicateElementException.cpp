#include "../headers/HashKeyDuplicateElementException.h"

const char* HashKeyDuplicateElementException::what() const noexcept
{
    std::string msg = "Duplicate value disallowed at \"";
    msg.append(this->key).append("\"");
    return msg.c_str();
}

HashKeyDuplicateElementException::HashKeyDuplicateElementException(std::string key)
{
    this->key = key;
}

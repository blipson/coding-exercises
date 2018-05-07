#include "../headers/HashKeyDuplicateException.h"

const char* HashKeyDuplicateException::what() const noexcept
{
    std::string msg = "Duplicate value disallowed at \"";
    msg.append(this->key).append("\"");
    return msg.c_str();
}

HashKeyDuplicateException::HashKeyDuplicateException(std::string key)
{
    this->key = key;
}

#include "../headers/HashKeyElementNotFoundException.h"

const char* HashKeyNotFoundException::what() const noexcept
{
    std::string msg = "Hash value not found at key \"";
    msg.append(this->key).append("\"");
    return msg.c_str();
}

HashKeyNotFoundException::HashKeyNotFoundException(std::string key)
{
    this->key = key;
}

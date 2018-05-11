#include <string>
#include "LinkedListOutOfBoundsException.h"

LinkedListOutOfBoundsException::LinkedListOutOfBoundsException(int index)
{
    value = index;
}

const char* LinkedListOutOfBoundsException::what() const noexcept
{
    std::string msg = "Array list index out of bounds at \"";
    msg.append(std::to_string(this->value)).append("\"");
    return msg.c_str();
}

#include <string>
#include "ArrayListIndexOutOfBoundsException.h"

ArrayListIndexOutOfBoundsException::ArrayListIndexOutOfBoundsException(int index)
{
    index = index;
}

const char* ArrayListIndexOutOfBoundsException::what() const noexcept
{
    std::string msg = "Array list index out of bounds at \"";
    msg.append(std::to_string(this->index)).append("\"");
    return msg.c_str();
}

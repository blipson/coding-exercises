//
// Created by Ben J. Lipson on 5/8/18.
//

#include <string>
#include "ArrayListInvalidEntryException.h"

ArrayListInvalidEntryException::ArrayListInvalidEntryException(int value)
{
    value = value;
}

const char* ArrayListInvalidEntryException::what() const
{
    std::string msg = "Array list value invalid: \"";
    msg.append(std::to_string(this->value)).append("\"");
    return msg.c_str();
}

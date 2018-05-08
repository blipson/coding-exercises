#include <exception>

#ifndef CODING_EXERCISES_ARRAYLISTELEMENTNOTFOUNDEXCEPTION_H
#define CODING_EXERCISES_ARRAYLISTELEMENTNOTFOUNDEXCEPTION_H


struct ArrayListIndexOutOfBoundsException : public std::exception
{
    int index;
    explicit ArrayListIndexOutOfBoundsException(int index);
    const char* what() const noexcept override;
};


#endif //CODING_EXERCISES_ARRAYLISTELEMENTNOTFOUNDEXCEPTION_H

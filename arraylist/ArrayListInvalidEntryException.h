#include <exception>

#ifndef CODING_EXERCISES_ARRAYLISTINVALIDENTRYEXCEPTION_H
#define CODING_EXERCISES_ARRAYLISTINVALIDENTRYEXCEPTION_H


struct ArrayListInvalidEntryException : public std::exception
{
    int value;
    explicit ArrayListInvalidEntryException(int value);
    const char* what() const noexcept override;

};


#endif //CODING_EXERCISES_ARRAYLISTINVALIDENTRYEXCEPTION_H

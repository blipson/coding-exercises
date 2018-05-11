#include <exception>

#ifndef CODING_EXERCISES_LINKEDLISTOUTOFBOUNDSEXCEPTION_H
#define CODING_EXERCISES_LINKEDLISTOUTOFBOUNDSEXCEPTION_H

struct LinkedListOutOfBoundsException : public std::exception
{
    int value;

    explicit LinkedListOutOfBoundsException(int value);

    const char* what() const noexcept override;
};


#endif //CODING_EXERCISES_LINKEDLISTOUTOFBOUNDSEXCEPTION_H

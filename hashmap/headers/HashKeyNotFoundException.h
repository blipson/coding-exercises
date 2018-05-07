#ifndef INTERVIEW_PREP_MYEXCEPTION_H
#define INTERVIEW_PREP_MYEXCEPTION_H


#include <exception>
#include <string>

struct HashKeyNotFoundException : public std::exception
{
    std::string key;

    explicit HashKeyNotFoundException(std::string key);

    const char* what() const noexcept override;
};


#endif //INTERVIEW_PREP_MYEXCEPTION_H

#ifndef INTERVIEW_PREP_HASHKEYDUPLICATEEXCEPTION_H
#define INTERVIEW_PREP_HASHKEYDUPLICATEEXCEPTION_H


#include <exception>
#include <string>

struct HashKeyDuplicateElementException : public std::exception
{
    std::string key;

    explicit HashKeyDuplicateElementException(std::string key);

    const char* what() const noexcept override;
};


#endif //INTERVIEW_PREP_HASHKEYDUPLICATEEXCEPTION_H

#ifndef INTERVIEW_PREP_HASHKEYDUPLICATEEXCEPTION_H
#define INTERVIEW_PREP_HASHKEYDUPLICATEEXCEPTION_H


#include <exception>
#include <string>

struct HashKeyDuplicateException : public std::exception
{
    std::string key;

    explicit HashKeyDuplicateException(std::string key);

    const char* what() const noexcept override;
};


#endif //INTERVIEW_PREP_HASHKEYDUPLICATEEXCEPTION_H

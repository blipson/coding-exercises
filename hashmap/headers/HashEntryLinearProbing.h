#ifndef INTERVIEW_PREP_HASHENTRY_H
#define INTERVIEW_PREP_HASHENTRY_H


#include <string>

class HashEntryLinearProbing
{
private:
    std::string key;
    std::string value;

public:
    std::string getKey();

    std::string getValue();

    HashEntryLinearProbing(std::string key, std::string value);
};


#endif //INTERVIEW_PREP_HASHENTRY_H

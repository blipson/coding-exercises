#ifndef INTERVIEW_PREP_HASHENTRYSEPARATECHAINING_H
#define INTERVIEW_PREP_HASHENTRYSEPARATECHAINING_H

#include <string>


class HashEntrySeparateChaining
{
private:
    std::string key;
    std::string value;
    HashEntrySeparateChaining* next;

public:
    std::string getKey();

    std::string getValue();

    HashEntrySeparateChaining* getNext();

    void setNext(HashEntrySeparateChaining* next);

    HashEntrySeparateChaining(std::string key, std::string value);
};


#endif //INTERVIEW_PREP_HASHENTRYSEPARATECHAINING_H

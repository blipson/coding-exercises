#ifndef INTERVIEW_PREP_HASHMAP_H
#define INTERVIEW_PREP_HASHMAP_H


#include <string>
#include "HashEntryLinearProbing.h"

class HashMapLinearProbing
{
private:
    static const int tableSize = 10;
    HashEntryLinearProbing** table;

public:
    HashMapLinearProbing();
    ~HashMapLinearProbing();

    HashEntryLinearProbing get(std::string key);

    std::string* getAll(std::string key);

    void put(std::string key, std::string value);

    void printTable();
};


#endif //INTERVIEW_PREP_HASHMAP_H

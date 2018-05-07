#ifndef INTERVIEW_PREP_HASHMAPSEPARATECHAINING_H
#define INTERVIEW_PREP_HASHMAPSEPARATECHAINING_H


#include <string>
#include "HashEntrySeparateChaining.h"

class HashMapSeparateChaining
{
private:
    static const int tableSize = 10;
    HashEntrySeparateChaining* hashTable[tableSize];
    int hash(std::string key);

public:
    HashMapSeparateChaining();
    HashEntrySeparateChaining get(std::string key);
    void put(std::string key, std::string value);
    int numberOfItemsInIndex(int index);
    void printTable();
};


#endif //INTERVIEW_PREP_HASHMAPSEPARATECHAINING_H

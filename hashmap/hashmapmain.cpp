#include <iostream>
#include "headers/HashMapLinearProbing.h"
#include "headers/HashKeyNotFoundException.h"
#include "headers/HashMapSeparateChaining.h"
#include "headers/HashKeyDuplicateException.h"

class Student
{
public:
    std::string name;
    std::string address;
    std::string gpa;

    Student(std::string name, std::string address, std::string gpa)
    {
        this->name = name;
        this->address = address;
        this->gpa = gpa;
    }

    std::string getName()
    {
        return this->name;
    }

    std::string getAddress()
    {
        return this->address;
    }

    std::string getGpa()
    {
        return this->gpa;
    }
};

void testHashMapLinearProbing()
{
    Student students[5] = {
            Student("Jeffrey", "111 Fake St", "3.5"),
            Student("Thomas", "222 Not Real Ave", "3.0"),
            Student("Sarah", "333 Imaginary Ln", "3.9"),
            Student("Bethany", "444 Made Up Cir", "2.6"),
            Student("Teddy", "555 Fake St", "3.2"),
    };
    HashMapLinearProbing hashMap = HashMapLinearProbing();

    for (Student &student : students)
    {
        hashMap.put(student.getName(), student.getAddress());
    }
    try
    {
        std::cout << "Getting individual students..." << std::endl;
        std::cout << hashMap.get("Jeffrey").getValue() << std::endl;
        std::cout << hashMap.get("Thomas").getValue() << std::endl;
        std::cout << hashMap.get("Sarah").getValue() << std::endl;
        std::cout << hashMap.get("Bethany").getValue() << std::endl;
        std::cout << hashMap.get("Teddy").getValue() << std::endl << std::endl;
        std::cout << "Attempting unresolved lookup..." << std::endl;
        std::cout << hashMap.get("woops").getValue() << std::endl;
    }
    catch (HashKeyNotFoundException &e)
    {
        std::cout << "HashKeyNotFoundException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
    hashMap.put("Jeffrey", "override");
    try
    {
        std::cout << std::endl << "Getting Jeffrey after entering second entry..." << std::endl;
        std::cout << hashMap.get("Jeffrey").getValue() << std::endl;
    }
    catch (HashKeyNotFoundException &e)
    {
        std::cout << "HashKeyNotFoundException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::string* allJeffs = hashMap.getAll("Jeffrey");
        std::cout << std::endl << "Getting all Jeffreys..." << std::endl;
        for (int i = 0; i < sizeof(allJeffs); i++)
        {
            if (!allJeffs[i].empty())
            {
                std::cout << allJeffs[i] << std::endl;
            }
        }
    }
    catch (HashKeyNotFoundException &e)
    {
        std::cout << "HashKeyNotFoundException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }


    std::cout << std::endl << "Getting the full hashmap..." << std::endl;
    hashMap.printTable();
}

void testHashMapSeparateChaining()
{
    Student students[5] = {
            Student("Jeffrey", "111 Fake St", "3.5"),
            Student("Thomas", "222 Not Real Ave", "3.0"),
            Student("Sarah", "333 Imaginary Ln", "3.9"),
            Student("Bethany", "444 Made Up Cir", "2.6"),
            Student("Teddy", "555 Fake St", "3.2"),
    };
    HashMapSeparateChaining hashMap = HashMapSeparateChaining();

    for (Student &student : students)
    {
        try
        {
            hashMap.put(student.getName(), student.getAddress());
        }
        catch (HashKeyDuplicateException &e)
        {
            std::cout << "HashKeyDuplicateException caught" << std::endl;
            std::cout << e.what() << std::endl;
        }
    }
    try
    {
        hashMap.put("Teddy", "test");
    }
    catch (HashKeyDuplicateException &e)
    {
        std::cout << "HashKeyDuplicateException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "Getting individual students..." << std::endl;
        std::cout << hashMap.get("Jeffrey").getValue() << std::endl;
        std::cout << hashMap.get("Thomas").getValue() << std::endl;
        std::cout << hashMap.get("Sarah").getValue() << std::endl;
        std::cout << hashMap.get("Bethany").getValue() << std::endl;
        std::cout << hashMap.get("Teddy").getValue() << std::endl << std::endl;
        std::cout << "Attempting unresolved lookup..." << std::endl;
        std::cout << hashMap.get("woops").getValue() << std::endl;
    }
    catch (HashKeyNotFoundException &e)
    {
        std::cout << "HashKeyNotFoundException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << "Getting the full hashmap..." << std::endl;
    hashMap.printTable();
}

int main()
{
    testHashMapLinearProbing();
    testHashMapSeparateChaining();

    return 0;
}

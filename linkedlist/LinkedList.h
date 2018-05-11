#ifndef CODING_EXERCISES_LINKEDLIST_H
#define CODING_EXERCISES_LINKEDLIST_H


struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
private:
    int size;
    Node* head;

    ~LinkedList();

    bool addAll(int* c);
    bool addAll(int index, int* c);
    void addFirst(int e);
    void addLast(int e);
    void clear();
    bool contains(int e);
    int get(int index);
    int getFirst();
    int getLast();
    int indexOf(int e);
    int lastIndexOf(int e);
    void push(int e);
    int remove();
    int remove(int index);
    bool removeFirstOccurence(int e);
    int removeFirst();
    int removeLast();
    bool removeLastOccurence(int e);
    int set(int index, int e);

public:
    LinkedList();

    bool add(int e);
    void add(int index, int e);

    void print();
};


#endif //CODING_EXERCISES_LINKEDLIST_H

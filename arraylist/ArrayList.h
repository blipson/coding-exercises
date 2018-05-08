#ifndef CODING_EXERCISES_ARRAYLIST_H
#define CODING_EXERCISES_ARRAYLIST_H


class ArrayList
{
private:
    void remake(int newLength);
    int length;

public:
    int* data;
    int size;

    explicit ArrayList(int length = 0);
    ~ArrayList();
    bool add(int e);
    void add(int index, int e);
    void clear();
    bool contains(int e);
    int get(int index);
    int indexOf(int e);
    bool isEmpty();
    int remove(int index);
    bool removeFirstInstance(int e);
    void removeRange(int fromIndex, int toIndex);
    void print();
    int set(int index, int e);

};


#endif //CODING_EXERCISES_ARRAYLIST_H

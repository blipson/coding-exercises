#include <iostream>
#include "ArrayList.h"
#include "ArrayListIndexOutOfBoundsException.h"
#include "ArrayListInvalidEntryException.h"

ArrayList::ArrayList(int length)
{
    data = new int[length];
    this->length = length;
    size = 0;
    for (int i = 0; i < length; i++)
    {
        data[i] = 0;
    }
}

ArrayList::~ArrayList()
{
    delete[] data;
}

bool ArrayList::add(int e)
{
    if (e == 0)
    {
        throw ArrayListInvalidEntryException(e);
    }
    int i = 0;
    while (data[i] != 0)
    {
        i++;
    }
    if (i == length)
    {
        if (size >= length)
        {
            remake(length + (length / 2));
        }
    }
    data[i] = e;
    size++;
    return true;
}

void ArrayList::add(int index, int e)
{
    if (e == 0)
    {
        throw ArrayListInvalidEntryException(e);
    }
    if (index > size || index <= 0)
    {
        throw ArrayListIndexOutOfBoundsException(index);
    } else if (index == size + 1)
    {
        if (size >= length)
        {
            remake(length + (length / 2));
        }
        data[index] = e;
        size++;
    } else
    {
        if (size >= length)
        {
            remake(length + (length / 2));
        }
        int buffer[size - index];
        int j = 0;
        for (int i = index; i < size; i++)
        {
            buffer[j] = data[i];
            j++;
        }
        j = 0;
        for (int k = index + 1; k < size + 1; k++)
        {
            data[k] = buffer[j];
            j++;
        }
        data[index] = e;
        size++;
    }
}

void ArrayList::remake(int newLength)
{
    if (newLength == 0)
    {
        auto* buffer = new int[1];
        delete[] data;
        data = buffer;
        length = 1;
        length = 1;
    } else if (newLength < 0)
    {
        throw ArrayListIndexOutOfBoundsException(newLength);
    } else
    {
        auto* buffer = new int[newLength];
        if (newLength > length)
        {
            for (int i = 0; i < length; i++)
            {
                buffer[i] = data[i];
            }
        } else
        {
            for (int i = 0; i < newLength; i++)
            {
                buffer[i] = data[i];
            }
        }
        delete[] data;
        data = buffer;
        length = newLength;
    }
}

void ArrayList::clear()
{
    remake(0);
    size = 0;
}

bool ArrayList::contains(int e)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == e)
        {
            return true;
        }
    }
    return false;
}

int ArrayList::get(int index)
{
    if (index > size - 1 || index < 0)
    {
        throw ArrayListIndexOutOfBoundsException(index);
    } else
    {
        return data[index];
    }
}

int ArrayList::indexOf(int e)
{
    int i = 0;
    while (data[i] != e)
    {
        i++;
        if (i == size)
        {
            return -1;
        }
    }
    return i;
}

bool ArrayList::isEmpty()
{
    if (size == 0)
    {
        return true;
    } else
    {
        return false;
    }
}

int ArrayList::remove(int index)
{
    if (index > length - 1 || index < 0)
    {
        throw ArrayListIndexOutOfBoundsException(index);
    }
    int removed = data[index];
    for (int i = index; i < size; i++)
    {
        data[i] = data[i + 1];
    }
    size--;
    if (size <= length / 2)
    {
        remake(length / 2);
    }
    return removed;
}

bool ArrayList::removeFirstInstance(int e)
{
    int i = 0;
    while (data[i] != e)
    {
        i++;
    }
    if (i >= size - 1)
    {
        return false;
    } else
    {
        remove(i);
        return true;
    }
}

void ArrayList::removeRange(int fromIndex, int toIndex)
{
    if (fromIndex >= 0 && fromIndex <= length - 1 && toIndex >= 0 && toIndex <= length - 1 && toIndex >= fromIndex)
    {
        for (int i = fromIndex; i <= toIndex; i++)
        {
            remove(fromIndex);
        }
    }
}

void ArrayList::print()
{
    std::cout << "DATA: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "SIZE: " << size << std::endl;
    std::cout << "LENGTH: " << length << std::endl;
    std::cout << std::endl;
}

int ArrayList::set(int index, int e)
{
    if (index < 0 || index >= size)
    {
        throw ArrayListIndexOutOfBoundsException(index);
    }
    int replaced = data[index];
    data[index] = e;
    return replaced;
}

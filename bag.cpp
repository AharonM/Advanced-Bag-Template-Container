#include <iostream>

#include "bag.h"
#include "bag_exception.h"

using namespace std;

#define DEBUG true

template <typename T>
ostream &operator <<(ostream &os,const Bag<T> &obj)
{
    os << "{";
    for (int i = 0; i < obj.size; i++)
        os << obj.bag[i] << (i < obj.size-1 ? ", " : "");
    os << "}";
    return os;
}

template <typename T>
Bag<T> &Bag<T>::operator+=(const Bag<T> &obj)
{
    int j = size;
    size += obj.size;
    checkCapacity();
    for (int i=0; i < size; i++)
        bag[j+i] = obj.bag[i];
    return *this;
}

template <typename T>
Bag<T> operator+(const Bag<T> &obj, T val)
{
    Bag<T> result;
    result.size = obj.size;
    result.checkCapacity();
    for (int x = 0; x < result.size; x++)
        result.bag[x] = obj.bag[x];
    result.bag[result.size] = val;
    result.size++;
    return result;
}

template <typename T>
Bag<T> operator+(const Bag<T> &bag1, const Bag<T> &bag2)
{
    Bag<T> result = bag1;
    return result += bag2;
}

template <typename T>
Bag<T>::Bag(const Bag &other) : bag(new T[other.capacity]), capacity(other.capacity), size(other.size)
{
    for (int i = 0; i < size; i++)
        bag[i] = other.bag[i];
}

template <typename T>
Bag<T> &Bag<T>::operator =(const Bag<T> &rhs)
{
    if (this == &rhs) return *this;
    delete [] bag;
    size = rhs.size;
    capacity = rhs.capacity;
    bag = new T[capacity];
    for (int i = 0; i < size; i++)
        bag[i] = rhs.bag[i];
    return *this;
}

template <typename T>
Bag<T> &Bag<T>::operator +=(T val)
{
    checkCapacity();
    bag[size] = val;
    size++;
    return *this;
}

template <typename T>
bool Bag<T>::isEmpty()
{
    if (size == 0)
        return true;
    else
        return false;
}

template <typename T>
bool Bag<T>::contains(T val) const
{
    for (int i=0; i < size; i++)
    {
        if(bag[i] == val)
            return true;
    }
    return false;
}

template <typename T>
int Bag<T>::find(T val) const
{
    int occurrence=0;
    for(int i=0; i < size; i++)
    {
        if(bag[i] == val)
            occurrence++;
    }
    if(occurrence > 0)
        return occurrence;
    else
        return -1;
}

template <typename T>
void Bag<T>::checkCapacity()
{
    if (size < capacity) return;

    capacity *= 2;
    T *newBag = new T [capacity];
    for (int i=0; i < size; i++)
        newBag[i] = bag[i];
    delete [] bag;
    bag = newBag;
    if (DEBUG) cerr << "Increased array capacity to " << capacity << endl;
}

template <typename T>
void Bag<T>::clear()
{
    delete [] bag;
    bag = 0;
    size = 0;
}

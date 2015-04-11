#ifndef BAG_H
#define BAG_H

#include <iostream>

using namespace std;

template <typename T>
class Bag;

template <typename T>
ostream &operator <<(ostream &os,const Bag<T> &obj);

template <typename T>
Bag<T> operator+(const Bag<T> &obj, T val);

template <typename T>
Bag<T> operator+(const Bag<T> &bag1, const Bag<T> &bag2);

template <typename T>
class Bag
{
    friend ostream &operator << <>(ostream &os,const Bag<T> &obj);
    friend Bag<T> operator+ <>(const Bag<T> &obj, T val);
    friend Bag<T> operator+ <>(const Bag<T> &bag1, const Bag<T> &bag2);

public:
    Bag(int capacity=100) : bag(new T[capacity]), capacity(capacity), size(0) {}
    Bag(const Bag<T> &other);
    ~Bag(){ delete [] bag;}
    Bag<T> & operator =(const Bag<T> &rhs);
    Bag<T> &operator +=(T val);
    Bag<T> &operator +=(const Bag<T> &bag);
    int getSize() const{return size;}
    bool isEmpty();
    bool contains(T val) const;
    int find(T val) const;
    void clear();
private:
    void checkCapacity();
    T *bag;
    int capacity;
    int size;
};

#endif

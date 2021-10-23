#pragma once
#include "Dog.h"

template<typename Dog> class DynamicArray;
class DynamicArrayIterator
{
    friend class DynamicArray<Dog>;

private:
    const DynamicArray<Dog>& da;
    int current;

public:
    Dog getCurrent() const;
    bool valid() const;
    void next();
    int get_current() const;
    void first();

    explicit DynamicArrayIterator(const DynamicArray<Dog>& d);
};
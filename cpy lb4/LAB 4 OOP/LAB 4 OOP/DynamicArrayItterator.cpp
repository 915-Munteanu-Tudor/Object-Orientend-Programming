#include "DynamicArrayItterator.h"
#include "DynamicArray.h"
#include <exception>

using namespace std;

DynamicArrayIterator::DynamicArrayIterator(const DynamicArray<TT>& d) : da(d) {
    //constructor of the iterator, initialises it to 0
    this->current = 0;
    //BC=WC=AC=THETA(1)
}

TT DynamicArrayIterator::getCurrent() const {
    //returns the current element in the array
    if (!this->valid())
        throw exception();
    return this->da.data[current];
    //BC=WC=AC=THETA(1)
}

bool DynamicArrayIterator::valid() const {
    //checks if the index is valid
    if (this->current < this->da.lenght)
        return true;
    return false;
    //BC=WC=AC=THETA(1)
}

void DynamicArrayIterator::next() {
    //passes to the next position
    if (this->valid())
        this->current++;
    else
        throw exception();
    //BC=WC=AC=THETA(1)
}

int DynamicArrayIterator::get_current() const{
    //returns the current index
    return this->current;
}

void DynamicArrayIterator::first() {
    //resets the iterator to 0,first position
    this->current = 0;
    //BC=WC=AC=THETA(1)
}


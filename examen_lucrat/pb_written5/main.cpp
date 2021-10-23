#include <iostream>
#include <cstring>
#include <vector>
#include <cassert>

template<typename T> class Stack{
private:
    int maxCapacity;
    std::vector<T> elements;
public:
    explicit Stack(int maxCapacity):maxCapacity(maxCapacity) {};
    Stack& operator+(const T& other){
        if(elements.size() == maxCapacity) {
            throw std::runtime_error("Stack is full!");
        }
        elements.push_back(other);
        return *this;
    }
    int getMaxCapacity(){
        return maxCapacity;
    }
    T pop(){
        T last_elem = elements[elements.size()-1];
        elements.erase(elements.end());
        return last_elem;
    }
    Stack& operator=(Stack& other){
        this->elements = other.elements;
        this->maxCapacity = other.maxCapacity;
        return *this;
    }
};

void testStack()
{
    Stack<std::string> s{ 2 };
    assert(s.getMaxCapacity() == 2);
    try {
        s = s + "examination";
        s = s + "oop";
        s = s + "test";
    } catch (std::exception& e) {
        assert(strcmp(e.what(), "Stack is full!") == 0);
    }
    assert(s.pop() == "oop");
    assert(s.pop() == "examination");
}
int main() {
    testStack();
    return 0;
}

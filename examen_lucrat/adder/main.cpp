#include <iostream>
#include "vector"

using namespace std;

template<typename T> class Adder{
private:
    T value;
    vector<T> last_added;
public:
    Adder(T value): value{value} {
        last_added.push_back(value);
    };
    Adder& operator+(T other){
        value += other;
        last_added.push_back(other);
        return *this;
    }
    Adder& operator++(){
        value +=last_added[last_added.size()-1];
        last_added.push_back(last_added.size()-1);
        return *this;
    }
    Adder& operator--(){
        if (last_added.empty())
            throw std::runtime_error("No more values!");
        value -=last_added[last_added.size()-1];
        last_added.pop_back();
        return *this;
    }
    T sum(){
        return value;
    }
};

void function2(){
    Adder<int> add{5};
    add = add+5+2;
    ++add;
    add+8;
    cout<< add.sum() << "\n";
    --add;
    cout<< add.sum() << "\n";
    --(--add);
    cout<< add.sum() << "\n";
    try {
        --(--(--add));
    }
    catch (runtime_error& ex) {
        cout<<ex.what();
    }
}

int main() {
    function2();
    return 0;
}

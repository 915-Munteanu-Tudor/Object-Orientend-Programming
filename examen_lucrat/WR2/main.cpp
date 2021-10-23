#include <iostream>
#include <cassert>
#include "sstream"
#include "cstring"

using namespace std;

int fct1(int x) {
    if (x % 10 == x) {
        throw std::runtime_error{"Number contains a single digit"};
    }
    stringstream s;
    s << x;
    string str = s.str();
    int y = str.size();
    int i = 0;
    while (i < y - 1 && str[i] > str[i + 1]) {
        i++;
    }
    return (i == y - 1);
}

void fct1_test(int x){
    try {
        fct1(x);
    }
    catch (exception& ex){
        cout << ex.what() << "\n";
        return;
    }


    try {
        if (fct1(x) == 1){
            assert(true);
            cout << "the number has its digits in descending order\n";
            return;
        }

        else if (fct1(x) == 0){
            throw std::runtime_error("the number does not have the digits in ascending order");
            assert(false);
        }
    }
    catch (exception &ex) {
        cout << ex.what() << "\n";
        return;
    }



}

int main(){

    fct1_test(12);

}

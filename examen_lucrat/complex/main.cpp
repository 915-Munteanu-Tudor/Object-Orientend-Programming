#include <iostream>
#include <cassert>
#include <cstring>
#include <utility>
#include <fstream>
#include "vector"

using namespace std;

class Complex{
public:
    Complex() = default;

    Complex(Complex const &c){
        this->real = c.getReal();
        this->imaginary = c.getImaginary();
    }

    Complex(int real, int imaginary) : real(real), imaginary(imaginary) {}

    int getReal() const {
        return real;
    }

    int getImaginary() const {
        return imaginary;
    }

    bool operator==(const Complex &rhs) const {
        return real == rhs.real &&
               imaginary == rhs.imaginary;
    }

    Complex operator/(int x){
        if (x == 0)
            throw std::runtime_error("Division by 0!");
        return Complex{real/x, imaginary/x};
    }

    friend ostream &operator<<(ostream &os, const Complex &complex) {
        os << complex.real << "+" << complex.imaginary<<"i";
        return os;
    }


private:
    int real;
    int imaginary;

};

template<typename T> class Vector{
private:
    std::vector<T> v;
public:
    Vector(std::vector<T> v): v(std::move(v)){};
    void printAll(std::ostream &os){
        for(int i=0; i< v.size(); i++){
            if (i == v.size()-1){
                os << v[i];
            }
            else {
                os << v[i] <<", ";
            }
        }
        os << "\n";
    }
};

void complex(){
    Complex a{}, b{1,2}, c{6,4}, d{b};
    assert(a.getReal() == 0 && a.getImaginary() == 0);
    assert(c.getImaginary() == 4);
    assert( b==d );
    Complex res1=c/2;
    cout << res1 << "\n";
    try {
        Complex res2 = b/0;
    }
    catch (runtime_error& e){
        assert(strcmp(e.what(), "Division by 0!") == 0);
    }
    Vector<string> v1{std::vector<string>{"hello", "bye"}};
    v1.printAll(std::cout);
    Vector<Complex> v2{std::vector<Complex>{a, b, c, d}};
    v2.printAll(std::cout);

}

int main() {
    complex();
    return 0;
}

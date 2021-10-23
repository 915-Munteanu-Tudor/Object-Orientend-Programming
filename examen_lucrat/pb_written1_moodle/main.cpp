#include <iostream>
#include <cstring>
#include <cassert>
#include <utility>
#include <vector>

class Car{
private:
    std::string name;
    int price;
public:
    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Car::name = name;
    }

    int getPrice() const {
        return price;
    }

    void setPrice(int price) {
        Car::price = price;
    }

    Car(std::string name, int price) : name(std::move(name)), price(price) {}

    bool operator<(const Car &rhs) const {
        return price < rhs.price;
    }

    bool operator>(const Car &rhs) const {
        return rhs < *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Car &car) {
        os << car.name << " " << car.price;
        return os;
    }

};

template<typename T1, typename T2> class List{
private:
   std::vector<std::pair<T1, T2>> list;
public:
    void sortByFirstComponent(){
        if(list.empty()) {
            throw std::runtime_error("List is empty!");
        }
        for (int i = 0; i < list.size() - 1; i++) {
            for (int j = i + 1; j < list.size(); j++) {
                if (list.at(j).first < list.at(i).first) {
                    std::swap(list.at(j), list.at(i));
                }
            }
        }
    };
    void add(T1 i, T2 j){
        list.push_back(std::pair<T1, T2>(i, j));
    };
    void printReverse(std::ostream& stream){
        for(int i = list.size() - 1; i >= 0; i--) {
            stream << list.at(i).first << " -> " << list.at(i).second << "; ";
        }
        stream << std::endl;
    };
    void sortBySecondComponent(){
        if(list.empty()) {
            throw std::runtime_error("List is empty!");
        }
        for (int i = 0; i < list.size() - 1; i++) {
            for (int j = i + 1; j < list.size(); j++) {
                if (list.at(j).second < list.at(i).second) {
                    std::swap(list.at(j), list.at(i));
                }
            }
        }
    }

};

void function1() {
    List<Car, int> list1;
    try {
        list1.sortByFirstComponent();
        assert(false);
    }
    catch (std::runtime_error& e) { assert(strcmp(e.what(), "List is empty!") == 0);	}

    list1.add(Car{ "Audi", 20 }, 8);
    list1.add(Car{ "Volkswagen", 10 }, 9);
    list1.add(Car{ "Bentley", 300 }, 10);

    list1.sortByFirstComponent();
    list1.printReverse(std::cout); // prints: Bentley 300 -> 10; Audi 20 -> 8; Volkswagen 10 -> 9
    list1.sortBySecondComponent();
    list1.printReverse(std::cout); // prints: Bentley 300 -> 10; Volkswagen 10 -> 9; Audi 20 -> 8;
}

int main() {
    function1();
    return 0;
}

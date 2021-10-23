#include <iostream>
#include <utility>

class Beverage {
private:
    std::string description;
public:
    Beverage(std::string desc) : description(std::move(desc)){}
    virtual double price() = 0;
    void print() {
        std::cout << description << " price: " << price();
    }
};

class Coffee : public Beverage {
public:
    Coffee(const std::string& desc) : Beverage("Coffee") {};
    double price() override{
        return 2.5;
    }
};

class Tea : public Beverage {
public:
    Tea(const std::string& desc) : Beverage("Tea") {};
    double price() override {
        return 1.5;
    }
};

class BeverageWithMilk : public Beverage {
private:
    Beverage* beverage;
    int milkCount;
public:
    BeverageWithMilk(Beverage* beverage, std::string desc, int mc) : beverage(beverage), Beverage(desc), milkCount(mc){};
    double price() override {
        return beverage->price() + 0.5 * milkCount;
    }
    void print() {
        beverage->print();
        std::cout << ", milk count: " << milkCount << std::endl;
    }
};

class BeverageMachine {
public:
    void prepare(std::string type, int milkCount){
        if(type == "Tea") {
            Tea* b = new Tea("Tea");
            BeverageWithMilk bwm(b, type, milkCount);
            bwm.print();
            std::cout << "Total price: " << bwm.price() << std::endl;
        }
        else if(type == "Coffee") {
            Coffee* b = new Coffee("Coffee");
            BeverageWithMilk bwm(b, type, milkCount);
            bwm.print();
            std::cout << "Total price: " << bwm.price() << std::endl;
        }
    };
};
int main() {
    BeverageMachine bm;
    bm.prepare("Tea", 0);
    bm.prepare("Coffee", 1);
    bm.prepare("Coffee", 2);
    return 0;
}

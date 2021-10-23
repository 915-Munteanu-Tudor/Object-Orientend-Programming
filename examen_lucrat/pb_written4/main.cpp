#include <iostream>
#include <utility>
#include <vector>


class SaleItem{
private:
    int code;
    double price;

public:
    SaleItem(int code, double price) : code(code), price(price) {}

    int getCode() const {
        return code;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        SaleItem::price = price;
    }

};


class Sale{
private:
    std::vector<SaleItem>* items;

public:
    Sale(std::vector<SaleItem> *items) : items(items) {}

    std::vector<SaleItem> *getItems() const {
        return items;
    }

};

class Discount{
public:
    virtual double calc(Sale s) = 0;
};

class ItemDiscount : public Discount {
private:
    int percentage;
    int code;

public:
    ItemDiscount(int percentage, int code) : percentage(percentage), code(code) {}

    double calc(Sale s) override {
        double sum = 0;
        for(auto e : *s.getItems())
            if(e.getCode() == code) {
                sum += percentage * e.getPrice() / 100;
                e.setPrice((1 - percentage / 100) * e.getPrice());
            }
        return sum;
    }
};

class SumDiscount : public Discount {
private:
    std::vector<Discount*> discounts;
public:
    SumDiscount(std::vector<Discount *> discounts) : discounts(std::move(discounts)) {}

    void add(Discount *d){
        discounts.push_back(d);
    }

    double calc(Sale s) override{
        double sum;
        for(auto d : discounts) {
            sum += d->calc(s);
        }
        return sum;
    }
};



int main() {
    SaleItem s1{1, 3.5};
    SaleItem s2{1, 4.5};
    SaleItem s3{2, 3};
    auto v = new std::vector<SaleItem>;
    v->push_back(s1);
    v->push_back(s2);
    v->push_back(s3);
    Sale s{v};
    auto* is1 = new ItemDiscount{10, 1};
    auto* is3 = new ItemDiscount{15, 2};
    std::vector<Discount*> discounts;
    SumDiscount sd{discounts};
    sd.add(is1);
    sd.add(is3);
    std::cout << "Total discount: " << sd.calc(s);
    return 0;
}

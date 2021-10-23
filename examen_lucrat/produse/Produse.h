//
// Created by munte on 21/06/2021.
//

#ifndef PRODUSE_PRODUSE_H
#define PRODUSE_PRODUSE_H

#include <utility>
#include "fstream"
#include "iostream"
#include "string"

using namespace std;

class Produs {

public:

    Produs() = default;

    Produs(int id, string name, string type, double price) : id(id), name(std::move(name)), type(std::move(type)),
                                                                           price(price) {}

    friend std::ostream &operator<<(std::ostream &os, const Produs &pd);


    friend std::istream &operator>>(std::istream &is, Produs &pd);

    std::string tostring(){
        return to_string(id) + ";" + name + ";" + type + to_string(price);
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        Produs::id = id;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Produs::name = name;
    }

    const string &getType() const {
        return type;
    }

    void setType(const string &type) {
        Produs::type = type;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        Produs::price = price;
    }

    int get_nr_vocale(const string& description){
        int contor = 0;
        for (char i : description) {
            if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u'){
                contor++;
            }
        }
        return contor;
    }

    bool operator<(Produs& pd){
        return price < pd.price;
    }


private:
    int id;
    string name;
    string type;
    double price;


};


#endif //PRODUSE_PRODUSE_H

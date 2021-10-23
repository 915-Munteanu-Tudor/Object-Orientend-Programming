//
// Created by munte on 21/06/2021.
//

#include <algorithm>
#include "Exceptions.h"
#include "RepoProduse.h"

vector<Produs> &RepoProduse::getProducts() {
    return products;
}

RepoProduse::RepoProduse() {
    read_from_file();

}

void RepoProduse::read_from_file() {
    string line;
    ifstream myfile("produse.txt");
    while (true) {
        if (myfile.eof()) {
            break;
        }
        Produs pd;

        try {
            myfile >> pd;
            this->add_product(pd);
        }
        catch (...) {

        }

    }
    myfile.close();

}

void RepoProduse::add_product(const Produs &prod) {
    if (find_if(this->products.begin(), this->products.end(), [&prod](auto const &prod1) {
        return prod.getId() == prod1.getId();
    }) != this->products.end()) {
        throw ProductException("This idea is already in your list");
    }
    this->products.push_back(prod);

}

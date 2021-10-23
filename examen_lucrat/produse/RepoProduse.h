//
// Created by munte on 21/06/2021.
//

#ifndef PRODUSE_REPOPRODUSE_H
#define PRODUSE_REPOPRODUSE_H

#include "vector"
#include "iostream"
#include "Produse.h"

using namespace std;

class RepoProduse {
private:
    vector<Produs> products;
public:
    RepoProduse();
    void read_from_file();
    void add_product(const Produs &prod);

    vector<Produs> &getProducts();

};


#endif //PRODUSE_REPOPRODUSE_H

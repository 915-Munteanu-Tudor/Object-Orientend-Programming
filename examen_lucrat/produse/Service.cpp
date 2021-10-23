//
// Created by munte on 21/06/2021.
//

#include <cstring>
#include <algorithm>
#include "Service.h"

vector<Produs> &Service::getProducts() {
    return rp.getProducts();
}

int Service::prod_type( const string& type) {
    int contor =0;
    for (auto &el:rp.getProducts()){
        if (el.getType() == type){
            contor ++;
        }
    }
    return contor;
}

vector<Produs> &Service::get_Sorted_prod() {
    auto v1 = new vector<Produs>;
    for (auto &el:rp.getProducts())
        v1->push_back(el);
    std::sort(v1->begin(), v1->end());
    return *v1;
}

void Service::add_product( int id, const std::string& name, const std::string& type, double price) {
    Produs i{id, name, type, price};
    rp.add_product(i);
}
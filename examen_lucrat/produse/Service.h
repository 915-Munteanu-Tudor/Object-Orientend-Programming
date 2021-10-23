//
// Created by munte on 21/06/2021.
//

#ifndef PRODUSE_SERVICE_H
#define PRODUSE_SERVICE_H


#include "iostream"
#include "RepoProduse.h"
#include "utility"

class Service {
private:
    RepoProduse& rp;
public:
    Service(RepoProduse &rp): rp{rp}{};

    vector<Produs>& getProducts();

    int prod_type( const string& type);

//    vector<Idea> &getSortedIdeas();
//
//    void add_idea(const string &description, const string &creator, int act);
//
//    void accept_idea(const string& description);
//
//    bool has_accepted(const string &name);


    vector<Produs> &get_Sorted_prod();

    void add_product(int id, const string &name, const string &type, double price);
};

#endif //PRODUSE_SERVICE_H

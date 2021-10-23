//
// Created by munte on 21/06/2021.
//

#include "Produse.h"

#include <utility>

std::ostream &operator<<(ostream &os, const Produs &pd) {
    os << pd.getId() << ";" << pd.getName() <<";"<< pd.getType() <<";"<< pd.getPrice();
    return os;
}

std::istream &operator>>(istream &is, Produs &pd) {
    string line;
    int k=0, q=0;
    string newstr[11];
    std::getline(is,line);
    if (line.empty())
        throw std::runtime_error("empty line");
    int cont = 0;
    for (k = 0; k < (line.size()); k++) {
        if (line[k] == ';' || line[k] == '\0') {
            //newstr[cont][q] = '\0';
            cont++;  //for next word
            //q = 0;  //for next word, init index to 0
        } else {
            newstr[cont] += line[k];
            q++;
        }
    }
    pd.id = stoi(newstr[0]);
    pd.name= newstr[1];
    pd.type = newstr[2];
    pd.price = stoi(newstr[3]);
    return is;
}



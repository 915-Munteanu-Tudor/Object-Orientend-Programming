//
// Created by munte on 20/06/2021.
//

#include "User.h"
#include "string"
#include <utility>
#include <stdexcept>

using namespace std;

User::User(std::string name) : name(std::move(name)) {}

const std::string &User::getName() const {
    return name;
}

std::istream &operator>>(std::istream &is, User &pg) {
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
    pg.name = newstr[0];
    return is;
}

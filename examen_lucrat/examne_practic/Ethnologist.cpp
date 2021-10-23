//
// Created by munte on 22/06/2021.
//

#include "Ethnologist.h"

#include <utility>

Ethnologist::Ethnologist(string name, string thematicArea) : name(std::move(name)), thematic_area(std::move(thematicArea)) {}

const string &Ethnologist::getName() const {
    return name;
}

void Ethnologist::setName(const string &name) {
    Ethnologist::name = name;
}

const string &Ethnologist::getThematicArea() const {
    return thematic_area;
}

void Ethnologist::setThematicArea(const string &thematicArea) {
    thematic_area = thematicArea;
}

std::ostream &operator<<(ostream &os, const Ethnologist &et) {
    return os;
}

std::istream &operator>>(istream &is, Ethnologist &et) {
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
    et.name = newstr[0];
    et.thematic_area = newstr[1];

    return is;
}

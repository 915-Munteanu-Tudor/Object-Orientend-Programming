//
// Created by munte on 21/06/2021.
//

#include "Writer.h"

#include <utility>

Writer::Writer(string name, string expertise) : name(std::move(name)), expertise(std::move(expertise)) {}

const string &Writer::getName() const {
    return name;
}

void Writer::setName(const string &name) {
    Writer::name = name;
}

const string &Writer::getExpertise() const {
    return expertise;
}

void Writer::setExpertise(const string &expertise) {
    Writer::expertise = expertise;
}

std::istream &operator>>(istream &is, Writer &wrt) {
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
    wrt.name = newstr[0];
    wrt.expertise = newstr[1];
    return is;
}

ostream &operator<<(ostream &os, const Writer &wrt) {
    os << wrt.getName() << ";" << wrt.getExpertise();
    return os;
}
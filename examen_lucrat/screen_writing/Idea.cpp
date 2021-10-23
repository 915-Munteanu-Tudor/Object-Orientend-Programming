//
// Created by munte on 21/06/2021.
//

#include "Idea.h"

#include <utility>

Idea::Idea(string description, string status, string creator, int act) : description(std::move(description)),
                                                                                              status(std::move(status)),
                                                                                              creator(std::move(creator)),
                                                                                              act(act) {}

const string &Idea::getDescription() const {
    return description;
}

void Idea::setDescription(const string &description) {
    Idea::description = description;
}

const string &Idea::getStatus() const {
    return status;
}

void Idea::setStatus(const string &status) {
    Idea::status = status;
}

const string &Idea::getCreator() const {
    return creator;
}

void Idea::setCreator(const string &creator) {
    Idea::creator = creator;
}

int Idea::getAct() const {
    return act;
}

void Idea::setAct(int act) {
    Idea::act = act;
}

std::istream &operator>>(istream &is, Idea &id) {
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
    id.description = newstr[0];
    id.status = newstr[1];
    id.creator = newstr[2];
    id.act = stoi(newstr[3]);
    return is;
}

std::ostream &operator<<(ostream &os, const Idea &id) {
    os << id.getDescription() << ";" << id.getStatus() <<";"<<id.getCreator()<<";"<<id.getAct();
    return os;
}

//
// Created by munte on 17/06/2021.
//

#include "Programmer.h"
#include<iostream>
#include "exceptions.h"
#include <sstream>
#include <utility>
using namespace std;

const std::string &Programmer::getName() const {
    return name;
}

void Programmer::setName(const std::string &name) {
    Programmer::name = name;
}

int Programmer::getNrRevisedFiles() const {
    return nr_revised_files;
}

void Programmer::setNrRevisedFiles(int nrRevisedFiles) {
    nr_revised_files = nrRevisedFiles;
}

int Programmer::getToRevise() const {
    return to_revise;
}

void Programmer::setToRevise(int toRevise) {
    to_revise = toRevise;
}

std::ostream &operator<<(std::ostream &os, const Programmer &pg) {
    //os << "Dog \n\t breed: " << dog.breed << " "<< std::endl << "\t name: " << dog.name << std::endl << "\t age: " << dog.age << std::endl << "\t photo: " << dog.photo << std::endl << std::endl;
    return os;
}

istream &operator>>(istream &is, Programmer &pg) {
    string line;
    int k=0, q=0;
    string newstr[11];
    std::getline(is,line);
    if (line.empty())
        throw std::runtime_error("empty line");
    int cont = 0;
    for (k = 0; k < (line.size()); k++) {
        if (line[k] == ',' || line[k] == '\0') {
            //newstr[cont][q] = '\0';
            cont++;  //for next word
            //q = 0;  //for next word, init index to 0
        } else {
            newstr[cont] += line[k];
            q++;
        }
    }
    pg.name = newstr[0];
    pg.nr_revised_files = stoi(newstr[1]);
    pg.to_revise = stoi(newstr[2]);
    return is;
}

Programmer::Programmer(string name, int nrRevisedFiles, int toRevise) : name(std::move(name)),
                                                                               nr_revised_files(nrRevisedFiles),
                                                                               to_revise(toRevise) {}


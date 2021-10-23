//
// Created by munte on 22/06/2021.
//

#include <algorithm>
#include "fstream"
#include "RepoEthnologists.h"

RepoEthnologists::RepoEthnologists() {
    read_from_file();
}

vector<Ethnologist> &RepoEthnologists::getEthnologist() {
    return ethnologists;
}

void RepoEthnologists::add_ethnologist(const Ethnologist &et) {
    if (find_if(this->getEthnologist().begin(), this->getEthnologist().end(), [&et](auto const &et1) {
        return et.getName() == et1.getName();
    }) != this->getEthnologist().end()) {
        throw std::runtime_error("This ethnologist is already in your list");
    }
    this->ethnologists.push_back(et);
}

void RepoEthnologists::read_from_file() {
    string line;
    ifstream myfile("ethnologists.txt");
    while (true) {
        if (myfile.eof()) {
            break;
        }
        Ethnologist et;

        try {
            myfile >> et;
            this->add_ethnologist(et);
        }
        catch (...) {

        }

    }
    myfile.close();
}

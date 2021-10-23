//
// Created by munte on 22/06/2021.
//
#include <algorithm>
#include "fstream"
#include "RepoBuildings.h"

vector<Building> &RepoBuildings::getBuildings() {
    return buildings;
}

void RepoBuildings::read_from_file() {
    string line;
    ifstream myfile("buildings.txt");
    while (true) {
        if (myfile.eof()) {
            break;
        }
        Building bd;

        try {
            myfile >> bd;
            this->add_building(bd);
        }
        catch (...) {

        }

    }
    myfile.close();
}

RepoBuildings::RepoBuildings() {
    read_from_file();
}

void RepoBuildings::add_building(const Building &bd) {
    if (find_if(this->getBuildings().begin(), this->getBuildings().end(), [&bd](auto const &bd1) {
        return bd.getId() == bd1.getId();
    }) != this->getBuildings().end()) {
        throw std::runtime_error("This answer id is already in your list");
    }
    this->buildings.push_back(bd);
}


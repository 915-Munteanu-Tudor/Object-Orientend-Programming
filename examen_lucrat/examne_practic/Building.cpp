//
// Created by munte on 22/06/2021.
//

#include "Building.h"

#include <utility>

int Building::getId() const {
    return id;
}

void Building::setId(int id) {
    Building::id = id;
}

const string &Building::getDescription() const {
    return description;
}

void Building::setDescription(const string &description) {
    Building::description = description;
}

const string &Building::getThematicArea() const {
    return thematic_area;
}

void Building::setThematicArea(const string &thematicArea) {
    thematic_area = thematicArea;
}

const vector<string> &Building::getCoordinates() const {
    return coordinates;
}

void Building::setCoordinates(const vector<string> &coordinates) {
    Building::coordinates = coordinates;
}

Building::Building(int id, string description, string thematicArea, const vector<string> &coordinates)
        : id(id), description(std::move(description)), thematic_area(std::move(thematicArea)), coordinates(coordinates) {}

std::istream &operator>>(istream &is, Building &bd) {
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
    bd.id = stoi(newstr[0]);
    bd.description = newstr[1];
    bd.thematic_area = newstr[2];
    for (int i = 3; i < cont+1; i++) {
        bd.coordinates.push_back(newstr[i]);
    }
    return is;
}

std::ostream &operator<<(ostream &os, const Building &bd) {
    os << bd.id << ";" << bd.description << ";" << bd.thematic_area << ";" << bd.coordinates[0] << bd.coordinates[1];
    return os;
}

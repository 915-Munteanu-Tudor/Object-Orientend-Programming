//
// Created by munte on 17/06/2021.
//

#include "SourceFile.h"
#include<iostream>
#include <sstream>
#include <utility>
using namespace std;
const std::string &SourceFile::getName() const {
    return name;
}

void SourceFile::setName(const std::string &name) {
    SourceFile::name = name;
}

const std::string &SourceFile::getStatus() const {
    return status;
}

void SourceFile::setStatus(const std::string &status) {
    SourceFile::status = status;
}

const std::string &SourceFile::getCreator() const {
    return creator;
}

void SourceFile::setCreator(const std::string &creator) {
    SourceFile::creator = creator;
}

const std::string &SourceFile::getReviewer() const {
    return reviewer;
}

void SourceFile::setReviewer(const std::string &reviewer) {
    SourceFile::reviewer = reviewer;
}

std::ostream &operator<<(std::ostream &os, const SourceFile &pg) {
    //os << "Dog \n\t breed: " << dog.breed << " "<< std::endl << "\t name: " << dog.name << std::endl << "\t age: " << dog.age << std::endl << "\t photo: " << dog.photo << std::endl << std::endl;
    return os;
}

istream &operator>>(istream &is, SourceFile &sf) {
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
    sf.name = newstr[0];
    sf.status = newstr[1];
    sf.creator = newstr[2];
    sf.reviewer = newstr[3];
    return is;
}

SourceFile::SourceFile(string name, string status, string creator, string reviewer) : name(std::move(
        name)), status(std::move(status)), creator(std::move(creator)), reviewer(std::move(reviewer)) {}

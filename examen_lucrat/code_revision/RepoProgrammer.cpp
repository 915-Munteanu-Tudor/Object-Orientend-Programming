//
// Created by munte on 17/06/2021.
//

#include <fstream>
#include <algorithm>
#include "RepoProgrammer.h"
#include "Programmer.h"
using namespace std;

void RepoProgrammer::read_from_file() {

    string line;
    ifstream myfile("programmers.txt");
    while (true) {
        if (myfile.eof()) {
            break;
        }
        Programmer pg;

        try {
            myfile >> pg;
            this->add_programmer(pg);
        }
        catch (...) {

        }

    }
    myfile.close();
}

void RepoProgrammer::add_programmer(const Programmer &pg) {
    if (find_if(this->pgs.begin(), this->pgs.end(), [&pg](auto const &pg1) {
        return pg.getName() == pg1.getName();
    }) != this->pgs.end()) {
        throw ProgrammerException("This programmer is already in your list");
    }
    this->pgs.push_back(pg);
}

RepoProgrammer::RepoProgrammer() {
    read_from_file();
}

vector<Programmer> &RepoProgrammer::getPgs(){
    return pgs;
}

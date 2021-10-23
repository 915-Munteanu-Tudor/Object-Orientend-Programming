//
// Created by munte on 21/06/2021.
//

#include <algorithm>
#include "RepoWriter.h"
#include "Exceptions.h"
#include "fstream"

void RepoWriter::read_from_file() {

    string line;
    ifstream myfile("writers.txt");
    while (true) {
        if (myfile.eof()) {
            break;
        }
        Writer wrt;

        try {
            myfile >> wrt;
            this->add_writer(wrt);
        }
        catch (...) {

        }

    }
    myfile.close();
}

void RepoWriter::add_writer(const Writer &wrt) {
    if (find_if(this->writers.begin(), this->writers.end(), [&wrt](auto const &wrt1) {
        return wrt.getName() == wrt1.getName();
    }) != this->writers.end()) {
        throw WriterException("This writer is already in your list");
    }
    this->writers.push_back(wrt);
}

vector<Writer> &RepoWriter::getWriters() {
    return writers;
}

RepoWriter::RepoWriter() {
    read_from_file();

}



//
// Created by munte on 17/06/2021.
//

#include <algorithm>
#include <stdexcept>
#include "RepoSourceFile.h"
#include "exceptions.h"
#include <fstream>
#include <utility>

void RepoSourceFile::read_from_file() {

    string line;
    ifstream myfile("source_files.txt");
    while (true) {
        if (myfile.eof()) {
            break;
        }
        SourceFile pg;

        try {
            myfile >> pg;
            this->add_sourcefile(pg);
        }
        catch (...) {

        }

    }
    myfile.close();
}

void RepoSourceFile::add_sourcefile(const SourceFile &pg) {
    if (find_if(this->sfs.begin(), this->sfs.end(), [&pg](auto const &pg1) {
        return pg.getName() == pg1.getName();
    }) != this->sfs.end()) {
        throw SourceFileException("This sourcefile is already in your list");
    }
    this->sfs.push_back(pg);
}

RepoSourceFile::RepoSourceFile() {
    read_from_file();
}

vector<SourceFile> &RepoSourceFile::getSfs() {
    return sfs;
}

void RepoSourceFile::add(string file_name, string name) {
    SourceFile s{std::move(file_name), "not_revised", std::move(name)};
    sfs.push_back(s);
}

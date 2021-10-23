//
// Created by munte on 22/06/2021.
//

#ifndef EXAMNE_PRACTIC_REPOETHNOLOGISTS_H
#define EXAMNE_PRACTIC_REPOETHNOLOGISTS_H


#include "Ethnologist.h"
#include "iostream"
#include "vector"

using namespace std;

class RepoEthnologists {
private:
    vector<Ethnologist> ethnologists;
public:
    RepoEthnologists();
    void read_from_file();
    void add_ethnologist(const Ethnologist &et);

    vector<Ethnologist> &getEthnologist();

    //void write();

};


#endif //EXAMNE_PRACTIC_REPOETHNOLOGISTS_H

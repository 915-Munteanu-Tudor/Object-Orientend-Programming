//
// Created by munte on 21/06/2021.
//

#ifndef SCREEN_WRITING_REPOWRITER_H
#define SCREEN_WRITING_REPOWRITER_H
#include "vector"
#include "iostream"
#include "Writer.h"

using namespace std;

class RepoWriter {
private:
    std::vector<Writer> writers;
public:
    RepoWriter();
    void read_from_file();
    void add_writer(const Writer &wrt);

    vector<Writer> &getWriters();

};


#endif //SCREEN_WRITING_REPOWRITER_H

//
// Created by munte on 21/06/2021.
//

#ifndef SCREEN_WRITING_REPOIDEA_H
#define SCREEN_WRITING_REPOIDEA_H


#include "Idea.h"
#include "vector"
#include "iostream"


class RepoIdea {
private:
    std::vector<Idea> ideas;
public:
    RepoIdea();
    void read_from_file();
    void add_idea(const Idea &id);

    vector<Idea> &getIdeas();
};


#endif //SCREEN_WRITING_REPOIDEA_H

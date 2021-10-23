//
// Created by munte on 21/06/2021.
//

#include <fstream>
#include <algorithm>
#include "RepoIdea.h"
#include "Exceptions.h"

RepoIdea::RepoIdea() {
    read_from_file();
}

void RepoIdea::read_from_file() {
    string line;
    ifstream myfile("ideas.txt");
    while (true) {
        if (myfile.eof()) {
            break;
        }
        Idea id;

        try {
            myfile >> id;
            this->add_idea(id);
        }
        catch (...) {

        }

    }
    myfile.close();
}

vector<Idea> &RepoIdea::getIdeas() {
    return ideas;
}

void RepoIdea::add_idea(const Idea &id) {
    if (find_if(this->ideas.begin(), this->ideas.end(), [&id](auto const &id1) {
        return id.getDescription() == id1.getDescription() && id.getAct() == id1.getAct();
    }) != this->ideas.end()) {
        throw IdeaException("This idea is already in your list");
    }
    this->ideas.push_back(id);
}


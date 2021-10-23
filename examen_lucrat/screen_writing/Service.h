//
// Created by munte on 21/06/2021.
//

#ifndef SCREEN_WRITING_SERVICE_H
#define SCREEN_WRITING_SERVICE_H
#include "iostream"
#include "RepoIdea.h"
#include "RepoWriter.h"
#include "utility"

class Service {
private:
    RepoWriter& rw;
    RepoIdea& ri;
public:
    Service(RepoIdea &ri, RepoWriter &rw): ri{ri}, rw{rw}{};

    vector<Writer>& getWriters();
    vector<Idea>& getIdeas();

    vector<Idea> &getSortedIdeas();

    void add_idea(const string &description, const string &creator, int act);

    void accept_idea(const string& description);

    bool has_accepted(const string &name);
};


#endif //SCREEN_WRITING_SERVICE_H

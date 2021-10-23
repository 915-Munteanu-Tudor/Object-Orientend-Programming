//
// Created by munte on 20/06/2021.
//

#include <algorithm>
#include <fstream>
#include "RepoUsers.h"

vector<User> &RepoUsers::getUsers() {
    return users;
}

void RepoUsers::read_from_file() {
    string line;
    ifstream myfile("users.txt");
    while (true) {
        if (myfile.eof()) {
            break;
        }
        User pg;

        try {
            myfile >> pg;
            this->add_user(pg);
        }
        catch (...) {

        }

    }
    myfile.close();
}

RepoUsers::RepoUsers() {
    read_from_file();

}

void RepoUsers::add_user(const User &pg) {
    if (find_if(this->users.begin(), this->users.end(), [&pg](auto const &pg1) {
        return pg.getName() == pg1.getName();
    }) != this->users.end()) {
        throw QuestionException("This user is already in your list");
    }
    this->users.push_back(pg);
}
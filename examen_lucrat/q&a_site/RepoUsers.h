//
// Created by munte on 20/06/2021.
//

#ifndef Q_A_SITE_REPOUSERS_H
#define Q_A_SITE_REPOUSERS_H


#include "User.h"
#include "fstream"
#include "exceptions.h"
#include <vector>

using namespace std;

class RepoUsers {
private:
    vector<User> users;
public:
    RepoUsers();
    void read_from_file();
    void add_user(const User &pg);

    vector<User> &getUsers();
};


#endif //Q_A_SITE_REPOUSERS_H

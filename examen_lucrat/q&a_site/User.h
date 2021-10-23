//
// Created by munte on 20/06/2021.
//

#ifndef Q_A_SITE_USER_H
#define Q_A_SITE_USER_H

#include <iostream>
#include <string>

class User {
private:
    std::string name;
public:
    User() = default;

    User(std::string name);

    const std::string &getName() const;

    friend std::istream &operator>>(std::istream &is, User &pg);

};


#endif //Q_A_SITE_USER_H

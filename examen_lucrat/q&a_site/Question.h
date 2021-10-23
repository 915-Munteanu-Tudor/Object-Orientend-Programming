//
// Created by munte on 20/06/2021.
//

#ifndef Q_A_SITE_QUESTION_H
#define Q_A_SITE_QUESTION_H

#include <iostream>
#include <string>

class Question {
private:
    int id;
    std::string text;
    std::string user;

public:
    Question() = default;

    friend std::ostream &operator<<(std::ostream &os, const Question &question);

    Question(int id, std::string text, std::string user);

    int getId() const;

    const std::string &getText() const;

    const std::string &getUser() const;

    friend std::istream &operator>>(std::istream &is, Question &pg);

    std::string tostring(){
        return std::to_string(id) + "; " + user + "; " + text;
    }
};


#endif //Q_A_SITE_QUESTION_H

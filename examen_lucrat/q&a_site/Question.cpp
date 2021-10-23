//
// Created by munte on 20/06/2021.
//

#include "Question.h"

#include <utility>
#include <stdexcept>
#include "string"
#include<iostream>
using namespace  std;

Question::Question(int id, std::string text, std::string user) : id(id), text(std::move(text)), user(std::move(user)) {}

int Question::getId() const {
    return id;
}

const std::string &Question::getText() const {
    return text;
}

const std::string &Question::getUser() const {
    return user;
}

std::istream &operator>>(std::istream &is, Question &pg) {
    string line;
    int k=0, q=0;
    string newstr[11];
    std::getline(is,line);
    if (line.empty())
        throw std::runtime_error("empty line");
    int cont = 0;
    for (k = 0; k < (line.size()); k++) {
        if (line[k] == ';' || line[k] == '\0') {
            //newstr[cont][q] = '\0';
            cont++;  //for next word
            //q = 0;  //for next word, init index to 0
        } else {
            newstr[cont] += line[k];
            q++;
        }
    }
    pg.id = stoi(newstr[0]);
    pg.text = newstr[1];
    pg.user = newstr[2];
    return is;
}

ostream &operator<<(ostream &os, const Question &question) {
    os << question.id << ";" << question.text << ";" << question.user;
    return os;
}

//
// Created by munte on 20/06/2021.
//

#include "Answer.h"

#include <utility>
#include <stdexcept>
#include <string>
#include <fstream>
using namespace std;


Answer::Answer(int id, int q, std::string user, std::string text, int votes) : id(id), q(q), user(std::move(user)),
                                                                                             text(std::move(text)), votes(votes) {}

int Answer::getId() const {
    return id;
}

void Answer::setId(int id) {
    Answer::id = id;
}

int Answer::getQ() const {
    return q;
}

void Answer::setQ(int q) {
    Answer::q = q;
}

const std::string &Answer::getUser() const {
    return user;
}

void Answer::setUser(const std::string &user) {
    Answer::user = user;
}

const std::string &Answer::getText() const {
    return text;
}

void Answer::setText(const std::string &text) {
    Answer::text = text;
}

int Answer::getVotes() const {
    return votes;
}

void Answer::setVotes(int votes) {
    Answer::votes = votes;
}

istream &operator>>(istream &is, Answer &sf) {
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
    sf.id = stoi(newstr[0]);
    sf.q = stoi(newstr[1]);
    sf.user = newstr[2];
    sf.text = newstr[3];
    sf.votes = stoi(newstr[4]);
    return is;
}

std::string Answer::tostring() {
    return to_string(id) + ";" + to_string(q) + ";" + user + ";" + text + ";" + to_string(votes);
}

ostream &operator<<(ostream &os, const Answer &answer) {
    os << answer.id << ";" << answer.q << ";" << answer.user << ";" << answer.text
       << ";" << answer.votes;
    return os;
}

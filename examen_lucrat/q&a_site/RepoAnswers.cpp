//
// Created by munte on 20/06/2021.
//

#include <fstream>
#include <algorithm>
#include "exceptions.h"
#include "RepoAnswers.h"

RepoAnswers::RepoAnswers() {
    read_from_file();
}

void RepoAnswers::read_from_file() {
    string line;
    ifstream myfile("answers.txt");
    while (true) {
        if (myfile.eof()) {
            break;
        }
        Answer pg;

        try {
            myfile >> pg;
            this->add_answer(pg);
        }
        catch (...) {

        }

    }
    myfile.close();
}

void RepoAnswers::add_answer(const Answer &pg) {
    if (find_if(this->answers.begin(), this->answers.end(), [&pg](auto const &pg1) {
        return pg.getId() == pg1.getId();
    }) != this->answers.end()) {
        throw AnswerException("This answer id is already in your list");
    }
    this->answers.push_back(pg);
}

vector<Answer> &RepoAnswers::getAnswers() {
    return answers;
}

void RepoAnswers::write() {

    ofstream myfile("answers.txt");
    for (auto const &ans:this->answers) {
        myfile << ans << "\n";
    }
    myfile.close();
}
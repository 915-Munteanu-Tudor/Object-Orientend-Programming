//
// Created by munte on 20/06/2021.
//

#include <algorithm>
#include "RepoQuestions.h"
#include "fstream"
#include "exceptions.h"

using namespace std;

void RepoQuestions::read_from_file() {
    string line;
    ifstream myfile("questions.txt");
    while (true) {
        if (myfile.eof()) {
            break;
        }
        Question pg;

        try {
            myfile >> pg;
            this->add_question(pg);
        }
        catch (...) {

        }

    }
    myfile.close();
}

RepoQuestions::RepoQuestions() {
    read_from_file();

}
void RepoQuestions::write() {

    ofstream myfile("questions.txt");
    for (auto const &q:this->questions) {
        myfile << q << "\n";
    }
    myfile.close();
}
void RepoQuestions::add_question(const Question &pg) {
    if (find_if(this->questions.begin(), this->questions.end(), [&pg](auto const &pg1) {
        return pg.getId() == pg1.getId();
    }) != this->questions.end()) {
        throw QuestionException("This question id is already in your list");
    }
    this->questions.push_back(pg);
}

std::vector<Question> &RepoQuestions::getQuestions() {
    return questions;
}


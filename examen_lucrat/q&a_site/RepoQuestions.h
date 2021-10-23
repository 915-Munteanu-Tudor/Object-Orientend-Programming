//
// Created by munte on 20/06/2021.
//

#ifndef Q_A_SITE_REPOQUESTIONS_H
#define Q_A_SITE_REPOQUESTIONS_H


#include <vector>
#include "string"
#include "Question.h"

class RepoQuestions {
private:
    std::vector<Question> questions;
public:
    RepoQuestions();
    void read_from_file();
    void add_question(const Question &pg);

    std::vector<Question> &getQuestions();
    void write();

};


#endif //Q_A_SITE_REPOQUESTIONS_H

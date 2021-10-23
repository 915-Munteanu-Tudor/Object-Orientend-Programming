//
// Created by munte on 20/06/2021.
//

#ifndef Q_A_SITE_REPOANSWERS_H
#define Q_A_SITE_REPOANSWERS_H


#include "Answer.h"
#include <vector>
using namespace std;

class RepoAnswers {
private:
    vector<Answer> answers;
public:
    RepoAnswers();
    void read_from_file();
    void add_answer(const Answer &pg);

    vector<Answer> &getAnswers();

    void write();

};


#endif //Q_A_SITE_REPOANSWERS_H

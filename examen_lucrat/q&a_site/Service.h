//
// Created by munte on 20/06/2021.
//

#ifndef Q_A_SITE_SERVICE_H
#define Q_A_SITE_SERVICE_H


#include "RepoUsers.h"
#include "RepoQuestions.h"
#include "RepoAnswers.h"
#include <utility>

class Service {
public:
    Service(RepoUsers &ru, RepoQuestions &rq, RepoAnswers &ra);

    vector<User>& getUsers();
    vector<Question>& getQuestions();
    vector<Answer>& getAnswers();
    vector<Question> getSortQuestions() const;
    vector<Answer> getTopAnswers(int id);
    void add_question(std::string user, std::string text);
    void add_answer(string user, int q, string text);
    void change_votes(int id, int votes);
    void write_to_file();
private:
    RepoUsers& ru;
    RepoQuestions& rq;
    RepoAnswers& ra;


};


#endif //Q_A_SITE_SERVICE_H

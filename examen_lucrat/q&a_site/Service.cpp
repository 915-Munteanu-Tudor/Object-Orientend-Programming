//
// Created by munte on 20/06/2021.
//

#include "Service.h"

Service::Service(RepoUsers &ru, RepoQuestions &rq, RepoAnswers &ra) : ru(ru), rq(rq), ra(ra) {}


vector<User> &Service::getUsers() {
    return ru.getUsers();
}

vector<Answer> &Service::getAnswers() {
    return ra.getAnswers();
}

vector<Question> &Service::getQuestions() {
    return rq.getQuestions();
}

vector<Question> Service::getSortQuestions() const {
    auto qst = rq.getQuestions();
    int freq[rq.getQuestions().size()+1];
    for(int i = 0; i < rq.getQuestions().size()+1; i++) {
        freq[i] = 0;
    }
    for (auto &i:ra.getAnswers()){
        freq[i.getQ()]++;
    }
    for (int i = 0; i < qst.size() - 1; i++) {
        for (int j = i + 1; j < qst.size(); j++) {
            if (freq[qst.at(j).getId()] > freq[qst.at(i).getId()]) {
                std::swap(qst.at(j), qst.at(i));
            }
        }
    }
    return qst;
}

vector<Answer> Service::getTopAnswers(int id) {
    std::vector<Answer> answers_for_id;
    for(auto& ans: getAnswers()) {
        if(ans.getQ() == id) {
            answers_for_id.push_back(ans);
        }
    }
    if(answers_for_id.size() == 0) {
        return answers_for_id;
    }
    for (int i = 0; i < answers_for_id.size() - 1; i++) {
        for (int j = i + 1; j < answers_for_id.size(); j++) {
            if (answers_for_id.at(j).getVotes() > answers_for_id.at(i).getVotes()) {
                std::swap(answers_for_id.at(j), answers_for_id.at(i));
            }
        }
    }
    return answers_for_id;
}

void Service::add_question(std::string user, std::string text) {
    int id = rq.getQuestions().size()+1;
    Question q{id, text, user};
    rq.add_question(q);
}

void Service::add_answer(std::string user,int q, std::string text){
    int id = ra.getAnswers().size()+1;
    Answer a{id, q, user, text, 0};
    ra.add_answer(a);
}
void Service::change_votes(int id, int votes){
    for(auto &it:ra.getAnswers()){
        if (it.getId() == id){
            it.setVotes(votes);
        }
    }
}

void Service::write_to_file() {
    ra.write();
    rq.write();
}

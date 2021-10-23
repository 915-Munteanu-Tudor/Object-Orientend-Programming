//
// Created by munte on 20/06/2021.
//

#ifndef Q_A_SITE_ANSWER_H
#define Q_A_SITE_ANSWER_H


#include <string>
#include <iostream>

class Answer {

private:
    int id;
    int q;
    std::string user;
    std::string text;
    int votes;

public:
    Answer() = default;

    Answer(int id, int q, std::string user, std::string text, int votes);

    int getId() const;

    void setId(int id);

    int getQ() const;

    void setQ(int q);

    const std::string &getUser() const;

    void setUser(const std::string &user);

    const std::string &getText() const;

    void setText(const std::string &text);

    int getVotes() const;

    void setVotes(int votes);

    friend std::istream &operator>>(std::istream &is, Answer &pg);

    std::string tostring();

    friend std::ostream &operator<<(std::ostream &os, const Answer &answer);
};


#endif //Q_A_SITE_ANSWER_H

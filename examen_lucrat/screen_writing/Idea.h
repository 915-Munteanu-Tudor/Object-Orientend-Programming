//
// Created by munte on 21/06/2021.
//

#ifndef SCREEN_WRITING_IDEA_H
#define SCREEN_WRITING_IDEA_H
#include <iostream>
using namespace std;

class Idea {

private:
    string description;
    string status;
    string creator;
    int act;

public:
    Idea() = default;

    bool operator<(Idea& id){
        return act < id.act;
    }

    Idea(string description, string status, string creator, int act);

    friend std::ostream &operator<<(std::ostream &os, const Idea &id);


    friend std::istream &operator>>(std::istream &is, Idea &id);

    std::string tostring(){
        return description + ";" + status + ";" + creator + to_string(act);
    }

    const string &getDescription() const;

    void setDescription(const string &description);

    const string &getStatus() const;

    void setStatus(const string &status);

    const string &getCreator() const;

    void setCreator(const string &creator);

    int getAct() const;

    void setAct(int act);



};


#endif //SCREEN_WRITING_IDEA_H

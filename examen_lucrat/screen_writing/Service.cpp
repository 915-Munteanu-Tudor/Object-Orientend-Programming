//
// Created by munte on 21/06/2021.
//

#include <algorithm>
#include "Service.h"

vector<Writer> &Service::getWriters() {
    return rw.getWriters();
}

vector<Idea> &Service::getIdeas() {
    return ri.getIdeas();
}

vector<Idea> &Service::getSortedIdeas(){
    auto v1 = new vector<Idea>;
    for (auto &el:ri.getIdeas())
        v1->push_back(el);
    std::sort(v1->begin(), v1->end());
    return *v1;
}

void Service::add_idea(const std::string& description, const std::string& creator, int act) {
    Idea i{description, "proposed", creator, act};
    ri.add_idea(i);
}

void Service::accept_idea(const string& description){
    for(auto &el:ri.getIdeas()){
        if (el.getDescription() == description) {
            el.setStatus("accepted");
            return;
        }
    }
}

bool Service::has_accepted(const string& name){
    for (auto &el:ri.getIdeas()){
        if (el.getCreator() == name && el.getStatus() == "accepted")
            return true;
    }
    return false;
}
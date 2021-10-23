//
// Created by munte on 22/06/2021.
//

#include "Service.h"

#include <utility>

vector<Ethnologist> &Service::getEthnologists() {
    return re.getEthnologist();
}

vector<Building> &Service::getBuildings() {
    return rb.getBuildings();
}

Service::Service(RepoBuildings &rb, RepoEthnologists &re): re(re), rb(rb){};

void Service::add_building(int id, string description, string thematic_area, const vector<string>& coords) {
    //int id = rq.getQuestions().size()+1;
    Building q{id, std::move(description), std::move(thematic_area), coords};
    rb.add_building(q);
}

vector<Building> &Service::getSortByArea(const string& area) {
    auto v = new vector<Building>;
    for(auto &el:rb.getBuildings()){
        if(el.getThematicArea() == area){
            v->push_back(el);
        }
    }
    for(auto &el:rb.getBuildings()){
        if(el.getThematicArea() != area && el.getThematicArea() != "office"){
            v->push_back(el);
        }
    }
    for(auto &el: rb.getBuildings()){
        if(el.getThematicArea() == "office"){
            v->push_back(el);
        }
    }
    return *v;
}

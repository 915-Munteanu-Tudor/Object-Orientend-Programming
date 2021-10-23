//
// Created by munte on 22/06/2021.
//

#ifndef EXAMNE_PRACTIC_SERVICE_H
#define EXAMNE_PRACTIC_SERVICE_H


#include "RepoBuildings.h"
#include "RepoEthnologists.h"
#include <utility>

class Service {
public:
    Service(RepoBuildings &rb, RepoEthnologists &re);

    vector<Ethnologist> &getEthnologists();

    vector<Building> &getBuildings();
    vector<string> &getCoords(){
        return rb.getCoordinates();
    }

    void update_buildings(int id, const string& description, const vector<string>& crds){
        rb.update_buildings(id, description, crds);
    }

    void add_building(int id, string description, string thematic_area, const vector<string> &coords);

//    vector<Answer> &getAnswers();
//
//    vector<Question> getSortQuestions() const;
//
//    vector<Answer> getTopAnswers(int id);
//
//    void add_question(std::string user, std::string text);
//
//    void add_answer(string user, int q, string text);
//
//    void change_votes(int id, int votes);
//
//    void write_to_file();

    vector<Building> &getSortByArea(const string &area);

private:
    RepoBuildings &rb;
    RepoEthnologists &re;


};



#endif //EXAMNE_PRACTIC_SERVICE_H

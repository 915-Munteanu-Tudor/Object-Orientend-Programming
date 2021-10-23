//
// Created by munte on 22/06/2021.
//

#ifndef EXAMNE_PRACTIC_REPOBUILDINGS_H
#define EXAMNE_PRACTIC_REPOBUILDINGS_H

#include "iostream"
#include "vector"
#include "Building.h"

using namespace std;

class RepoBuildings {
private:
    vector<Building> buildings;
    vector<string> coordinates;
public:
    RepoBuildings();
    void read_from_file();
    void add_building(const Building &bd);

    vector<Building> &getBuildings();

    vector<string> &getCoordinates(){
        for (auto &el:buildings){
            coordinates.push_back(el.coords_tostring());
        }
        return coordinates;
    }

    void update_buildings(int id, const string& description, const vector<string>& crds){
        for (auto &el:buildings){
            if (el.getId() == id){
                el.setDescription(description);
                el.setCoordinates(crds);
            }
        }
    }
    //void write();

};


#endif //EXAMNE_PRACTIC_REPOBUILDINGS_H

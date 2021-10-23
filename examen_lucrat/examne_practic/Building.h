//
// Created by munte on 22/06/2021.
//

#ifndef EXAMNE_PRACTIC_BUILDING_H
#define EXAMNE_PRACTIC_BUILDING_H


#include <string>
#include "iostream"
#include "vector"

using namespace std;

class Building {
public:

    Building() = default;

    Building(int id, string description, string thematicArea, const vector<string> &coordinates);

    int getId() const;

    void setId(int id);

    const string &getDescription() const;

    void setDescription(const string &description);

    const string &getThematicArea() const;

    void setThematicArea(const string &thematicArea);

    const vector<string> &getCoordinates() const;

    void setCoordinates(const vector<string> &coordinates);

    std::string coords_tostring(){
        string linie;
        for (auto &el:coordinates){
            linie += el;
        }
        return linie;
    }

    friend std::ostream &operator<<(std::ostream &os, const Building &bd);

    friend std::istream &operator>>(std::istream &is, Building &bd);

private:
    int id;
    string description;
    string thematic_area;
    vector<string> coordinates;


};


#endif //EXAMNE_PRACTIC_BUILDING_H

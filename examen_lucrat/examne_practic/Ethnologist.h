//
// Created by munte on 22/06/2021.
//

#ifndef EXAMNE_PRACTIC_ETHNOLOGIST_H
#define EXAMNE_PRACTIC_ETHNOLOGIST_H
#include "iostream"
#include "string"

using namespace std;

class Ethnologist {
public:
    Ethnologist() = default;

    Ethnologist(string name, string thematicArea);

    const string &getName() const;

    void setName(const string &name);

    const string &getThematicArea() const;

    void setThematicArea(const string &thematicArea);

    std::string tostring(){
        return name + "; " + thematic_area ;
    }

    friend std::ostream &operator<<(std::ostream &os, const Ethnologist &et);

    friend std::istream &operator>>(std::istream &is, Ethnologist &et);

private:
    string name;
    string thematic_area;

};


#endif //EXAMNE_PRACTIC_ETHNOLOGIST_H

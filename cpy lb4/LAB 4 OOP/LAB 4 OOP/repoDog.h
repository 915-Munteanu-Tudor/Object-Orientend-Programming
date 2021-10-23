#pragma once
#include <vector>
#include <memory>
#include "Dog.h"
//#include "adoption.h"

class RepoDog
{
public:
    std::vector<Dog>elements;
    //std::unique_ptr<AdoptionList> adoptionList = nullptr;

public:
    void write_to_file();
    RepoDog();
    void add_dog(const Dog& dog, bool save=true);
    void remove_dog(const string& nm);
    void update_dog(const string & nm,const string& nm1, const string& nm2, char ag[25], const string& nm3);
    std::vector<Dog> filter_dogs(const string& nm, const char nm1[25]);
    const vector<Dog> &getElements() const;

    void read_from_file();

};

template<typename T>
ostream &operator<<(ostream &os, const vector<T>v) {
for (auto& el:v)
    os <<el<<endl;
return os;
 }
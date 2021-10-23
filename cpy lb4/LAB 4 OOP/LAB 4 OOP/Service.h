#include "repoDog.h"
#include "UndoRedo.h"
#pragma once

class Service {
private:
    RepoDog& repo;
    vector<unique_ptr<Undo>> undo;
    vector<unique_ptr<Undo>> redo;
public:

    explicit Service(RepoDog &repo) : repo(repo){}

    //explicit Service(RepoDog &repo);

    void add_dog(const Dog& dog, bool save=true);
    void remove_dog(const string& nm);
    void update_dog(const string & nm,const string& nm1, const string& nm2, char ag[25], const string& nm3);
    std::vector<Dog> filter_dogs(const string& nm, const char nm1[25]);
    const vector<Dog> &getElements() const;
    void Undo();
    void Redo();
};

//
// Created by munte on 17/06/2021.
//

#ifndef CODE_REVISION_REPOPROGRAMMER_H
#define CODE_REVISION_REPOPROGRAMMER_H
#include <vector>
#include "Programmer.h"
#include "exceptions.h"
using namespace std;

class RepoProgrammer {
private:
    vector<Programmer> pgs;
public:

    RepoProgrammer();

    void read_from_file();

    void add_programmer(const Programmer &pg);

    vector<Programmer> &getPgs();
};


#endif //CODE_REVISION_REPOPROGRAMMER_H

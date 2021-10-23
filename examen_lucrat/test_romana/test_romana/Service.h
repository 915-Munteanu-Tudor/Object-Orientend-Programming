//
// Created by kida on 5/23/21.
//

#ifndef TEST_ROMANA_SERVICE_H
#define TEST_ROMANA_SERVICE_H


#include "Repository.h"

class Service {
public:
    Service(const Repository &repo);

private:
    Repository repo;
public:
    std::vector<Concert>* get_elements();
    void read_from_file();
    bool tryParse(std::string &input, int &output);
};


#endif //TEST_ROMANA_SERVICE_H

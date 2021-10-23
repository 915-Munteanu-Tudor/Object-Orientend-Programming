//
// Created by kida on 5/23/21.
//

#ifndef TEST_ROMANA_REPOSITORY_H
#define TEST_ROMANA_REPOSITORY_H


#include <vector>
#include "Concert.h"

class Repository {
private:
    std::vector<Concert>*& concerte;
    std::string file_name;
public:
    Repository(std::vector<Concert>* &concerte, std::string fileName);

    std::vector<Concert>* get_elements();

    void read_from_file();
};


#endif //TEST_ROMANA_REPOSITORY_H

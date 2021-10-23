//
// Created by kida on 5/23/21.
//

#include "Service.h"

Service::Service(const Repository &repo) : repo(repo) {}

std::vector<Concert>* Service::get_elements() {
    return repo.get_elements();
}

void Service::read_from_file() {
    repo.read_from_file();
}

bool Service::tryParse(std::string &input, int &output) {
    try{
        output = std::stoi(input);
    } catch (std::invalid_argument) {
        return false;
    }
    return true;
}


//
// Created by kida on 5/23/21.
//

#include <fstream>
#include <utility>
#include "Repository.h"


void Repository::read_from_file() {
    std::string line;
    std::ifstream f(file_name);
    while (true) {
        if (f.eof()) {
            break;
        }
        Concert c;
        try {
            f >> c;
            concerte->push_back(c);
        }
        catch (std::runtime_error) {

        }
    }
    f.close();
}

Repository::Repository(std::vector<Concert> *&concerte, std::string fileName) : concerte(concerte),
                                                                                            file_name(std::move(fileName)) {}

std::vector<Concert> *Repository::get_elements() {
    return concerte;
}

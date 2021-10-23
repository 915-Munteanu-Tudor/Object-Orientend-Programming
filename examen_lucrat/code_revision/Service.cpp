//
// Created by munte on 17/06/2021.
//

#include <algorithm>
#include <utility>
#include "Service.h"

Service::Service(RepoProgrammer &rp, RepoSourceFile &rsf) : rp(rp), rsf(rsf) {}

vector<Programmer> &Service::getProgrammers() {
    return rp.getPgs();
}

vector<SourceFile> &Service::getSourceFiles() {
    return rsf.getSfs();
}

vector<SourceFile> Service::getSortByName() const{
    auto sourcefiles = rsf.getSfs();
    for (int i = 0; i < sourcefiles.size() - 1; i++) {
        for (int j = i + 1; j < sourcefiles.size(); j++) {
            if (sourcefiles.at(j).getName() < sourcefiles.at(i).getName()) {
                std::swap(sourcefiles.at(j), sourcefiles.at(i));
            }
        }
    }
    return sourcefiles;
}

vector<SourceFile> Service::getSortByStatus() const{
    auto sourcefiles = rsf.getSfs();
    for (int i = 0; i < sourcefiles.size() - 1; i++) {
        for (int j = i + 1; j < sourcefiles.size(); j++) {
            if (sourcefiles.at(j).getStatus() < sourcefiles.at(i).getStatus()) {
                std::swap(sourcefiles.at(j), sourcefiles.at(i));
            }
        }
    }
    return sourcefiles;
}

vector<SourceFile> Service::getSortByCreator() const {
    auto sourcefiles = rsf.getSfs();
    for (int i = 0; i < sourcefiles.size() - 1; i++) {
        for (int j = i + 1; j < sourcefiles.size(); j++) {
            if (sourcefiles.at(j).getCreator() < sourcefiles.at(i).getCreator()) {
                std::swap(sourcefiles.at(j), sourcefiles.at(i));
            }
        }
    }
    return sourcefiles;
}

vector<SourceFile> Service::getSortByReviewer() const {
    auto sourcefiles = rsf.getSfs();
    for (int i = 0; i < sourcefiles.size() - 1; i++) {
        for (int j = i + 1; j < sourcefiles.size(); j++) {
            if (sourcefiles.at(j).getReviewer() < sourcefiles.at(i).getReviewer()) {
                std::swap(sourcefiles.at(j), sourcefiles.at(i));
            }
        }
    }
    return sourcefiles;
}

void Service::add(string file_name, string name) {
    rsf.add(std::move(file_name), std::move(name));
}

//
// Created by munte on 17/06/2021.
//

#ifndef CODE_REVISION_SERVICE_H
#define CODE_REVISION_SERVICE_H


#include "RepoProgrammer.h"
#include "RepoSourceFile.h"

class Service {

private:
    RepoProgrammer& rp;
    RepoSourceFile& rsf;

public:
    Service(RepoProgrammer &rp, RepoSourceFile &rsf);
    vector<Programmer>& getProgrammers();
    vector<SourceFile>& getSourceFiles();
    vector<SourceFile> getSortByName() const;
    vector<SourceFile> getSortByStatus() const;
    vector<SourceFile> getSortByCreator() const;
    vector<SourceFile> getSortByReviewer() const;
    void add(string file_name, string name);
};


#endif //CODE_REVISION_SERVICE_H

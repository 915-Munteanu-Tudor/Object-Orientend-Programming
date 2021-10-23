//
// Created by munte on 17/06/2021.
//

#ifndef CODE_REVISION_REPOSOURCEFILE_H
#define CODE_REVISION_REPOSOURCEFILE_H
#include "SourceFile.h"
#include "Programmer.h"
#include <vector>

using namespace std;

class RepoSourceFile {
private:
    vector<SourceFile> sfs;
public:
    RepoSourceFile();
    void read_from_file();
    void add_sourcefile(const SourceFile &pg);

    vector<SourceFile> &getSfs();

    void add(string file_name, string name);
};


#endif //CODE_REVISION_REPOSOURCEFILE_H

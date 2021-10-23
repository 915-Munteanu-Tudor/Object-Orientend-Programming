//
// Created by munte on 17/06/2021.
//

#ifndef CODE_REVISION_PROGRAMMER_H
#define CODE_REVISION_PROGRAMMER_H


#include <string>

class Programmer {
private:
    std::string name;
    int nr_revised_files{};
    int to_revise{};

public:
    Programmer() = default;

    Programmer(std::string name, int nrRevisedFiles, int toRevise);

    const std::string &getName() const;

    void setName(const std::string &name);

    int getNrRevisedFiles() const;

    void setNrRevisedFiles(int nrRevisedFiles);

    int getToRevise() const;

    void setToRevise(int toRevise);

    friend std::ostream &operator<<(std::ostream &os, const Programmer &pg);

    friend std::istream &operator>>(std::istream &is, Programmer &pg);

};


#endif //CODE_REVISION_PROGRAMMER_H

//
// Created by munte on 17/06/2021.
//

#ifndef CODE_REVISION_SOURCEFILE_H
#define CODE_REVISION_SOURCEFILE_H


#include <string>
#include <utility>

class SourceFile {
private:
    std::string name;
    std::string status;
    std::string creator;
    std::string reviewer;

public:
    SourceFile() = default;

    SourceFile(std::string name, std::string status, std::string creator,
               std::string reviewer);

    SourceFile(std::string name, std::string status, std::string creator) : name{std::move(name)}, status(std::move(status)), creator(std::move(creator)){};

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getStatus() const;

    void setStatus(const std::string &status);

    const std::string &getCreator() const;

    void setCreator(const std::string &creator);

    const std::string &getReviewer() const;

    void setReviewer(const std::string &reviewer);

    friend std::ostream &operator<<(std::ostream &os, const SourceFile &pg);

    friend std::istream &operator>>(std::istream &is, SourceFile &pg);

};


#endif //CODE_REVISION_SOURCEFILE_H

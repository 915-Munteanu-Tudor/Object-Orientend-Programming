//
// Created by munte on 17/06/2021.
//

#ifndef CODE_REVISION_EXCEPTIONS_H
#define CODE_REVISION_EXCEPTIONS_H


#include <exception>
#include <string>

class ProgrammerException: public std::exception{

public:

    explicit ProgrammerException(std::string message);

    const char *what() const noexcept override;

private:
    std::string message;

};

class SourceFileException: public std::exception{

public:

    explicit SourceFileException(std::string message);

    const char *what() const noexcept override;

private:
    std::string message;

};


#endif //CODE_REVISION_EXCEPTIONS_H

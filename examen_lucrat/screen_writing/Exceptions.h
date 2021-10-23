//
// Created by munte on 21/06/2021.
//

#ifndef SCREEN_WRITING_EXCEPTIONS_H
#define SCREEN_WRITING_EXCEPTIONS_H



#include <exception>
#include <string>

class WriterException: public std::exception{

public:

    explicit WriterException(const std::string& message);

    const char *what() const noexcept override;

private:
    std::string message;

};

class IdeaException: public std::exception{

public:

    explicit IdeaException(const std::string& message);

    const char *what() const noexcept override;

private:
    std::string message;

};



#endif //SCREEN_WRITING_EXCEPTIONS_H

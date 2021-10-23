//
// Created by munte on 20/06/2021.
//

#ifndef Q_A_SITE_EXCEPTIONS_H
#define Q_A_SITE_EXCEPTIONS_H



#include <exception>
#include <string>

class UserException: public std::exception{

public:

    explicit UserException(std::string message);

    const char *what() const noexcept override;

private:
    std::string message;

};

class AnswerException: public std::exception{

public:

    explicit AnswerException(std::string message);

    const char *what() const noexcept override;

private:
    std::string message;

};

class QuestionException: public std::exception{

public:

    explicit QuestionException(std::string message);

    const char *what() const noexcept override;

private:
    std::string message;

};


#endif //Q_A_SITE_EXCEPTIONS_H

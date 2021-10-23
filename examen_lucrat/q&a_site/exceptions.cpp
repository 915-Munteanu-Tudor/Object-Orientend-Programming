//
// Created by munte on 20/06/2021.
//

#include "exceptions.h"

#include <utility>

UserException::UserException(std::string message): message(std::move(message)) {

}

const char *UserException::what() const noexcept {
    return this->message.c_str();
}

AnswerException::AnswerException(std::string message): message(std::move(message)) {

}

const char *AnswerException::what() const noexcept {
    return this->message.c_str();
}

QuestionException::QuestionException(std::string message): message(std::move(message)) {

}

const char *QuestionException::what() const noexcept {
    return this->message.c_str();
}

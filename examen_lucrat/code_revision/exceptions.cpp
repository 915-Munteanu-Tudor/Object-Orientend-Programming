//
// Created by munte on 17/06/2021.
//

#include "exceptions.h"

ProgrammerException::ProgrammerException(std::string message) :message(std::move(message)) {

}

const char *ProgrammerException::what() const noexcept {
    return this->message.c_str();
}

SourceFileException::SourceFileException(std::string message) :message(std::move(message)) {

}

const char *SourceFileException::what() const noexcept {
    return this->message.c_str();
}

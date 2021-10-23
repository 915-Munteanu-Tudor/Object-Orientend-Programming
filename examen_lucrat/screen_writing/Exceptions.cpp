//
// Created by munte on 21/06/2021.
//

#include "Exceptions.h"

WriterException::WriterException(const std::string& message) {

}

const char *WriterException::what() const noexcept {
    return this->message.c_str();
}

IdeaException::IdeaException(const std::string& message) {

}

const char *IdeaException::what() const noexcept {
    return this->message.c_str();
}

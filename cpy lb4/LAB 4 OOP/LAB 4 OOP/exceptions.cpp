#include "exceptions.h"

const char *DogException::what() const noexcept {
    return this->message.c_str();
}

DogException::DogException(std::string message) : message(std::move(message)) {}

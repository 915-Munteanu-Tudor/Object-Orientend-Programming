//
// Created by munte on 21/06/2021.
//

#include "Exceptions.h"

ProductException::ProductException(const std::string &message) {

}

const char *ProductException::what() const noexcept {
    return this->message.c_str();
}

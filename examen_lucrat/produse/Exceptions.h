//
// Created by munte on 21/06/2021.
//

#ifndef PRODUSE_EXCEPTIONS_H
#define PRODUSE_EXCEPTIONS_H



#include <exception>
#include <string>

class ProductException: public std::exception{

public:

    explicit ProductException(const std::string& message);

    const char *what() const noexcept override;

private:
    std::string message;

};


#endif //PRODUSE_EXCEPTIONS_H

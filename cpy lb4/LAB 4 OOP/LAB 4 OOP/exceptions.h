#include <exception>
#include <string>

class DogException: public std::exception{

public:

    explicit DogException(std::string message);

    const char *what() const noexcept override;

private:
    std::string message;

};
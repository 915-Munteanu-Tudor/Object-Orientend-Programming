//
// Created by kida on 5/23/21.
//

#include <string>
#include <sstream>
#include "Data.h"

int Data::getMonth() const {
    return month;
}

int Data::getDay() const {
    return day;
}

Data::Data(int month, int day) : month(month), day(day) {}

std::string Data::to_string() const {
    std::stringstream ss;
    ss << this->getMonth() << "/" << this->getDay();
    return ss.str();
}

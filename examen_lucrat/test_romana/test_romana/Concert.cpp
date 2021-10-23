//
// Created by kida on 5/23/21.
//


#include "Concert.h"

#include <utility>
#include <stdexcept>


Concert::Concert(std::string numeFormatie, const Data &date, int numarBilete, int pretBilet) : numeFormatie(std::move(
        numeFormatie)), date(date), numarBilete(numarBilete), pretBilet(pretBilet) {}

const std::string &Concert::getNumeFormatie() const {
    return numeFormatie;
}

void Concert::setNumeFormatie(const std::string &numeFormatie) {
    Concert::numeFormatie = numeFormatie;
}

const Data Concert::getDate() const {
    return date;
}

void Concert::setDate(const Data &date) {
    Concert::date = date;
}

int Concert::getNumarBilete() const {
    return numarBilete;
}

void Concert::setNumarBilete(int numarBilete) {
    Concert::numarBilete = numarBilete;
}

int Concert::getPretBilet() const {
    return pretBilet;
}

void Concert::setPretBilet(int pretBilet) {
    Concert::pretBilet = pretBilet;
}

std::istream &operator>>(std::istream &is, Concert &mv) {
    std::string line;
    std::getline(is, line);
    if(line.empty()){
        throw std::runtime_error("empty");
    }
    std::string movie_raw[10];
    int nr_words = 0;
    for(int i = 0; i < line.size(); i++) {
        if(line[i] == ';' || line[i] == '\0') {
            nr_words++;
        }
        else {
            movie_raw[nr_words] += line[i];
        }
    }
    mv.setNumeFormatie(movie_raw[0]);
    nr_words = 0;
    std::string data_raw[10];
    for(int i = 0; i < movie_raw[1].size(); i++) {
        if(movie_raw[1][i] == '/' || movie_raw[1][i] == '\0') {
            nr_words++;
        }
        else {
            data_raw[nr_words] += movie_raw[1][i];
        }
    }
    mv.setDate(Data(stoi(data_raw[0]), stoi(data_raw[1])));
    mv.setNumarBilete(stoi(movie_raw[2]));
    mv.setPretBilet(stoi(movie_raw[3]));
    return is;
}

bool Concert::operator<(const Concert &c) {
    if(date.getMonth() < c.getDate().getMonth()) {
        return true;
    }
    else if(date.getMonth() > c.getDate().getMonth()) {
        return false;
    }
    else {
        if(date.getDay() < c.getDate().getDay()) {
            return true;
        }
        return false;
    }
}


//
// Created by munte on 26/05/2021.
//

#include <vector>
#include <stdexcept>
#include "Concurent.h"

int Concurent::etapaCompetitie=1;

double Concurent::getPunctaj() const {
    return punctaj;
}

void Concurent::setPunctaj(double punctaj) {
    Concurent::punctaj = punctaj;
}

int Concurent::getEtapaCompetitie() {
    return etapaCompetitie;
}

void Concurent::setEtapaCompetitie(int e) {
    etapaCompetitie = e;
}

Concurent::Concurent(const std::string &nume, int anulNasterii, double punctaj) : Persoana(nume, anulNasterii),
                                                                                  punctaj(punctaj) { setEtapaCompetitie(1);}

Concurent::Concurent(double punctaj) : punctaj(punctaj) { setEtapaCompetitie(1);}

Concurent::Concurent() {
    setEtapaCompetitie(1);
}

int Concurent::verifica() {
    if (getAnulNasterii() < 2003)
        return 1;
    return 0;
}

void Concurent::setEtapa(const std::vector<Concurent>&concurenti) {
    for (auto &conc:concurenti) {
        if(conc.getPunctaj() < 100)
            return;
    }
    /*for (auto &conc:concurenti) {
        conc.setEtapaCompetitie(conc.getEtapaCompetitie()+1);
    }*/
    etapaCompetitie++;

}

std::istream &operator>>(std::istream &is, Concurent &mv) {
    std::string line;
    std::getline(is, line);
    if(line.empty()){
        throw std::runtime_error("empty");
    }
    std::string conc[10];
    int nr_words = 0;
    for(int i = 0; i < line.size(); i++) {
        if(line[i] == ' ' || line[i] == '\0') {
            nr_words++;
        }
        else {
            conc[nr_words] += line[i];
        }
    }
    mv.setNume(conc[0]);
    mv.setAnulNasterii(stoi(conc[1]));
    mv.setPunctaj(stof(conc[2]));
    return is;
}

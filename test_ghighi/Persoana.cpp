
#include "Persoana.h"

Persoana::Persoana(const std::string &nume, int anulNasterii) : nume(nume), anul_nasterii(anulNasterii) {}

const std::string &Persoana::getNume() const {
    return nume;
}

void Persoana::setNume(const std::string &nume) {
    Persoana::nume = nume;
}

int Persoana::getAnulNasterii() const {
    return anul_nasterii;
}

void Persoana::setAnulNasterii(int anulNasterii) {
    anul_nasterii = anulNasterii;
}

Persoana::Persoana() {
}

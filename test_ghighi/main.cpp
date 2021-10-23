#include <iostream>
#include <fstream>
#include <vector>
#include "Concurent.h"

int main() {

    std::vector<Concurent>concurenti;
    int majori = 0;
    int etp;

    std::string line;
    std::ifstream f("concurenti.txt");
    while (true) {
        if (f.eof()) {
            break;
        }
        Concurent c;
        try {
            f >> c;
            concurenti.push_back(c);
        }
        catch (std::runtime_error) {

        }
    }
    f.close();

    for (auto &conc:concurenti) {
        if (conc.verifica() == 1){
            majori++;
        }

    }
    Concurent conc;
    conc.setEtapa(concurenti);
    std::cout << "etapa:\n";
    for (auto &conc:concurenti) {
        std::cout << conc.getNume() << " " << conc.getEtapaCompetitie() << std::endl;
    }

    Persoana* pers;
    std::cout << "Datele concurentilor sunt: \n";
    for(auto c: concurenti) {
        pers = &c;
        std::cout << pers->getNume() << " " << pers->getAnulNasterii() << " ";
        std::cout << c.getPunctaj() << "\n";
    }
    std::cout << "Numarul concurentilor majori : " << majori << std::endl;
}

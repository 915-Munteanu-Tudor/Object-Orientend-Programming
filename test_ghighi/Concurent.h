#include "Persoana.h"
#include <string>
#include <fstream>

class Concurent: public Persoana{
public:
    explicit Concurent();

    Concurent(const std::string &nume, int anulNasterii, double punctaj);

    Concurent(double punctaj);

    double getPunctaj() const;

    void setPunctaj(double punctaj);

    static int getEtapaCompetitie();

    static void setEtapaCompetitie(int etapaCompetitie);

    int verifica() override;

    static void setEtapa(const std::vector<Concurent>&concurenti);

    friend std::istream &operator>>(std::istream &is, Concurent &mv);



private:
    double punctaj;
    static int etapaCompetitie;

};


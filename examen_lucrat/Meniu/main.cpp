#include <iostream>
#include <utility>
#include "string"

using namespace std;

class Meniu{
private:
    int pret;
public:
    Meniu(int pret) : pret(pret) {}

    virtual string descriere() = 0;
    int getPret() const {
        return pret;
    }
};

class CuRacoritoare: public Meniu{
private:
    Meniu* mn;
public:
    CuRacoritoare(Meniu *mn) : Meniu(mn->getPret()+4), mn(mn) {}

    string descriere() override{
        return mn->descriere() + " cu racoritoare";
    }
};

class CuCafea: public Meniu{
private:
    Meniu* mn;
public:
    CuCafea(Meniu *mn) : Meniu(mn->getPret()+5), mn(mn) {}

    string descriere() override{
        return mn->descriere() + " cu cafea";
    }
};

class MicDejun: public Meniu{
private:
    string denumire;
public:
    MicDejun(int pret, string denumire) : Meniu(pret), denumire(std::move(denumire)) {};


    string descriere() override{
        return denumire;
    }
};

int main() {
    auto mic_dejun = new MicDejun(15, "Omleta");
    auto mic_dejun_cu_cafea = new CuCafea(mic_dejun);
    auto mic_dejun_cu_cafea_si_racoritoare = new CuRacoritoare(mic_dejun_cu_cafea);
    cout << mic_dejun_cu_cafea_si_racoritoare->descriere() << " " << mic_dejun_cu_cafea_si_racoritoare->getPret();
    return 0;
}

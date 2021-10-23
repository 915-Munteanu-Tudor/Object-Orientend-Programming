#include <iostream>
#include <utility>
using namespace std;

class Smoothie {
private:
    int pret;
public:
    Smoothie(int pret) : pret(pret) {};

    virtual int getPret(){
        return pret;
    };
    virtual string descriere() = 0;
};

class DecoratorSmoothie : public Smoothie {
private:
    Smoothie* sm;
public:

    DecoratorSmoothie(Smoothie *sm) : Smoothie(sm->getPret()), sm(sm) {};

    int getPret() override {
        return sm->getPret();
    }
    string descriere() override {
        return sm->descriere();
    }

    Smoothie *getSm() const {
        return sm;
    }

};

class SmoothieCuFrisca : public DecoratorSmoothie{
public:
    SmoothieCuFrisca(Smoothie *sm) : DecoratorSmoothie(sm) {};

    string descriere() override {
        return getSm()->descriere() + " cu frisca";
    }
    int getPret() override {
        return getSm()->getPret() + 2;
    }
};

class SmoothieCuUmbreluta : public DecoratorSmoothie{
public:
    SmoothieCuUmbreluta(Smoothie *sm) : DecoratorSmoothie(sm) {};

    string descriere() override {
        return getSm()->descriere() + " cu umbreluta";
    }
    int getPret() override {
        return getSm()->getPret() + 3;
    }
};

class BasicSmoothie : public Smoothie {
private:
    string nume;
public:
    BasicSmoothie(int pret, string nume) : Smoothie(pret), nume(std::move(nume)) {}

    string descriere() override {
        return nume;
    }
};

int main() {
    auto kiwi_basic = new BasicSmoothie(5, "smoothie cu kiwi");
    auto kiwi_frisca = new SmoothieCuFrisca{kiwi_basic};
    SmoothieCuUmbreluta kiwi_frisca_umbreluta(kiwi_frisca);
    cout << kiwi_frisca_umbreluta.descriere() << " pret: " << kiwi_frisca_umbreluta.getPret() << "\n";
    auto capsuni_basic = new BasicSmoothie(6, "smoothie cu capsuni");
    auto capsuni_frisca = new SmoothieCuFrisca(capsuni_basic);
    cout << capsuni_frisca->descriere() << " pret: " << capsuni_frisca->getPret() << "\n";
    cout << kiwi_basic->descriere() << " pret: " << kiwi_basic->getPret() << "\n";
    return 0;
}

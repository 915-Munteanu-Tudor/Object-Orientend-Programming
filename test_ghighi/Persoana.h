#include <string>


class Persoana {
public:
    explicit Persoana();

    Persoana(const std::string &nume, int anulNasterii);

    const std::string &getNume() const;

    void setNume(const std::string &nume);

    int getAnulNasterii() const;

    void setAnulNasterii(int anulNasterii);

    virtual int verifica() = 0;

private:
    std::string nume;
    int anul_nasterii;

};

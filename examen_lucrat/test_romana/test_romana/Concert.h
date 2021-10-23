//
// Created by kida on 5/23/21.
//

#ifndef TEST_ROMANA_CONCERT_H
#define TEST_ROMANA_CONCERT_H


#include <string>
#include "Data.h"
#include <fstream>

class Concert {
public:
    Concert() = default;
    Concert(std::string numeFormatie, const Data &date, int numarBilete, int pretBilet);

    const std::string &getNumeFormatie() const;

    void setNumeFormatie(const std::string &numeFormatie);

    const Data getDate() const;

    void setDate(const Data &date);

    int getNumarBilete() const;

    void setNumarBilete(int numarBilete);

    int getPretBilet() const;

    void setPretBilet(int pretBilet);

    friend std::istream &operator>>(std::istream &is, Concert &mv);

    bool operator< (Concert const &c);

    friend std::ostream& operator<<(std::ostream &output, const Concert &M) {
        output << M.getNumeFormatie() << ";" << M.getDate().to_string() << ";" << M.getNumarBilete() << ";"
               << M.getPretBilet()<< "\n";
        return output;
    }

private:
    std::string numeFormatie;
    Data date;
    int numarBilete;
    int pretBilet;

};


#endif //TEST_ROMANA_CONCERT_H

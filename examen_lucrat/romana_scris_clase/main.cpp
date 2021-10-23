#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T> class Geanta{
private:
    std::vector<T> obiecte;
public:
    Geanta(T obj) {
        obiecte.push_back(obj);
    }
    Geanta operator+(T other) {
        obiecte.push_back(other);
        return *this;
    }
    auto begin(){
        return obiecte.begin();
    }
    auto end() {
        return obiecte.end();
    }
};

template<typename T> class Measurement{
private:
    T val;
public:
    Measurement() = default;
    Measurement(T v):val(v){};
    T value() const {
        return val;
    }
    Measurement<T>& operator+(T other){
        val += other;
        return *this;
    }

    bool operator<(const Measurement &rhs) const {
        return val < rhs.val;
    }

    bool operator>(const Measurement &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Measurement &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Measurement &rhs) const {
        return !(*this < rhs);
    }

};

class Examen{

private:
    string descriere;
    string ora;

public:
    Examen(string descriere, string ora) : descriere(std::move(descriere)), ora(std::move(ora)) {}

    string getDescriere() const {
        return descriere + " ora " + ora + "\n";
    }

    const string &getOra() const {
        return ora;
    }

    friend ostream &operator<<(ostream &os, const Examen &examen) {
        os << examen.descriere << " ora " << examen.ora;
        return os;
    };

};

template<typename T> class ToDo{
private:
    vector<T> chestii;
public:
    ToDo() =default;
    ToDo& operator<<(T other){
        chestii.push_back(other);
        return *this;
    }
    void printToDoList(std::ostream& os){
        os << "De facut:";
        for (auto &alte_chestii:chestii){
            os << alte_chestii << ";";
        }
    }

};

template<typename T> class Expresie{
private:
    T operand;
    T val;
    std::vector<T> operanzi;
    std::vector<char> operatori;
public:

    Expresie(T operand): operand(operand){
        operanzi.push_back(operand);
        val=operand;
        operatori.push_back('+');
    };

    Expresie<T>& operator+(T other){
        val = val + other;
        operatori.push_back('+');
        operanzi.push_back(other);
        return *this;
    }

    Expresie<T>& operator-(T other){
        val = val - other;
        operatori.push_back('-');
        operanzi.push_back(other);
        return *this;
    }

    T valoare(){
        return val;
    }

    Expresie<T>& undo(){
        if (!operanzi.empty() and !operatori.empty()) {
            if (operatori[operatori.size()-1] == '-'){
                val += operanzi[operanzi.size()-1];
            }
            else{
                val -= operanzi[operanzi.size()-1];
            }
            operanzi.pop_back();
            operatori.pop_back();
        }
        return *this;

    }


};

template <typename T> class Cos {
private:
    std::vector<T> objs;
public:
    Cos() = default;
    Cos& operator+(T other){
        objs.push_back(other);
        return *this;
    }
    Cos& undo(){
        objs.pop_back();
        return *this;
    }
    std::ostream& tipareste(std::ostream& os){
        for(auto &it: objs){
            os << it;
        }
        return os;
    }
};

void calatorie() {
    Geanta<string> geanta{ "Ion" };//creaza geanta pentru Ion
    geanta = geanta + string{ "haine" }; //adauga obiect in ganta
    geanta + string{ "pahar" };
    for (auto o : geanta) {//itereaza obiectele din geanta
        cout << o << "\n";
    }
}

void masuratori(){
    //creaza un vector de masuratori cu valorile (10,2,3)
    std::vector<Measurement<int>> v{ 10,2,3 };
    v[2] + 3 + 2; //aduna la masuratoarea 3 valuarea 5
    std::sort(v.begin(), v.end()); //sorteaza masuratorile
    //tipareste masuratorile (in acest caz: 2,8,10)
    for (const auto& m : v) std::cout << m.value() << ",";

}

void todolist() {
    ToDo <Examen> todo;
    Examen oop{"oop scris", "8:00"};
    todo << oop << Examen{"oop practic", "11:00"}; //Adauga 2 examene la todo
    std::cout << oop.getDescriere(); //tipareste la consola: oop scris ora 8:00
    //itereaza elementele adaugate si tipareste la consola lista de activitati
    //in acest caz tipareste: De facut:oop scris ora 8:00;oop practic ora 11:00
    todo.printToDoList(std::cout);
}

void operatii() {
    Expresie<int> exp{3};//construim o expresie,pornim cu operandul 3
//se extinde expresia in dreapta cu operator (+ sau -) si operand
    exp = exp + 7 + 3;
    exp = exp - 8;
//tipareste valoarea expresiei (in acest caz:5 rezultat din 3+7+3-8)
    cout << exp.valoare() << "\n";
    exp.undo(); //reface ultima operatie efectuata
//tipareste valoarea expresiei (in acest caz:13 rezultat din 3+7+3)
    cout << exp.valoare() << "\n";
    exp.undo().undo();
    cout << exp.valoare() << "\n"; //tipareste valoarea expresiei (in acest caz:3)
}

void cumparaturi() {
    Cos<string> cos;//creaza un cos de cumparaturi
    cos = cos + "Mere"; //adauga Mere in cos
    cos.undo();//elimina Mere din cos
    cos + "Mere"; //adauga Mere in cos
    cos = cos + "Paine" + "Lapte";//adauga Paine si Lapte in cos
    cos.undo().undo();//elimina ultimele doua produse adaugate

    cos.tipareste(std::cout);//tipareste elementele din cos (Mere)
}

int main() {
    //subiectul 1
    calatorie();

    //subiectul 2
    masuratori();

    //subiectul 3
    todolist();

    //subiectul 4
    operatii();

    //subiectul 5
    cumparaturi();

    return 0;
}

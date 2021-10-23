#include <algorithm>
#include "repoDog.h"
#include "exceptions.h"
#include <fstream>
#include <QSqlDatabase>

void RepoDog::add_dog(const Dog &dog, bool save) {
    if (find_if(this->elements.begin(), this->elements.end(), [&dog](auto const &dog1) {
        return dog.name == dog1.name;
    }) != this->elements.end()) {
        throw DogException("The dog is already in your list.\n\n");
    }
    this->elements.push_back(dog);
    if (save)
        write_to_file();

}


void RepoDog::remove_dog(const string &nm) {
    if (find_if(this->elements.begin(), this->elements.end(), [&nm](auto const &dog1) {
            return dog1.name == nm;

    }) == this->elements.end()) {
        throw DogException("The dog does not exist in your list.\n\n");
    }
    this->elements.erase(std::remove_if(this->elements.begin(), this->elements.end(), [&nm](auto const &dog) {
        return dog.getName() == nm;
    }), this->elements.end());
    write_to_file();


}

void RepoDog::update_dog(const string &nm, const string &nm1, const string &nm2, char *ag, const string &nm3) {
    if (find_if(this->elements.begin(), this->elements.end(), [&nm](auto const &dog1) {
        return dog1.name == nm;
    }) == this->elements.end()) {
        throw DogException("The dog does not exist in your list.\n\n");
    }
    for (auto &el:this->elements) {
        if (el.name == nm) {
            el.breed = nm1;
            el.name = nm2;
            el.age = stoi(ag);
            el.photo = nm3;

            break;
        }
    }

    write_to_file();
}

RepoDog::RepoDog() : elements(vector<Dog>()) {
    this->read_from_file();
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName(":memory:");
    //db.open();
//    Dog dog1("labrador", "Jackie", 1, "http://www.zooland.ro/data/Image/image/cainele-alb.jpg");
//    this->elements.push_back(dog1);
//    Dog dog2("pitbull", "Pitty", 3, "https://www.animalzoo.ro/wp-content/uploads/2017/05/cu11-604x515.jpg");
//    this->elements.push_back(dog2);
//    Dog dog3("maidanez", "Bruno", 5, "http://www.magazinoutdoor.ro/blog/wp-content/uploads/2019/12/caine-de-vanatoare-Pointer.jpg");
//    this->elements.push_back(dog3);
//    Dog dog4("bichon", "Bob", 2, "http://www.magazinoutdoor.ro/blog/wp-content/uploads/2019/12/Golden-Retriever.jpg");
//    this->elements.push_back(dog4);
//    Dog dog5("akita", "Aky", 1, "http://www.magazinoutdoor.ro/blog/wp-content/uploads/2019/12/English-Setter.jpg");
//    this->elements.push_back(dog5);
//    Dog dog6("retriever", "Goldie", 7, "http://www.magazinoutdoor.ro/blog/wp-content/uploads/2019/12/Irish-Setter.jpg");
//    this->elements.push_back(dog6);
//    Dog dog7("bulldog", "Chelutu", 4, "http://www.magazinoutdoor.ro/blog/wp-content/uploads/2019/12/Beagle.jpeg");
//    this->elements.push_back(dog7);
//    Dog dog8("teckel", "Thor", 9, "http://www.magazinoutdoor.ro/blog/wp-content/uploads/2019/12/Bloodhound.jpg");
//    this->elements.push_back(dog8);
//    Dog dog9("ciobanesc german", "Lupu", 3, "http://www.magazinoutdoor.ro/blog/wp-content/uploads/2019/12/English-Springer-Spaniel.jpg");
//    this->elements.push_back(dog9);
//    Dog dog10("maidanez", "Marta", 3, "http://www.magazinoutdoor.ro/blog/wp-content/uploads/2019/12/Weimaraner.jpg");
//    this->elements.push_back(dog10);
}

const vector<Dog> &RepoDog::getElements() const {
    return elements;
}


void RepoDog::write_to_file() {
    ofstream myfile("input.txt");
    for (auto &dog:this->elements) {
        myfile << dog.breed << "," << dog.name << "," << dog.age << "," << dog.photo << "\n";
    }
    myfile.close();
}

std::vector<Dog> RepoDog::filter_dogs(const string &nm, const char *nm1) {
    if (nm.empty())
        return this->elements;
    std::vector<Dog> filtered;
    std::copy_if(elements.begin(), elements.end(), std::back_inserter(filtered), [&nm, &nm1](const auto &el) {
        return el.getBreed() == nm and el.getAge() < stoi(nm1);
    });
    return filtered;
}

void RepoDog::read_from_file() {

    string line;
    ifstream myfile("input.txt");
    while (true) {
        if (myfile.eof()) {
            break;
        }
        Dog dog;

        try {
            myfile >> dog;
            this->add_dog(dog, false);
        }
        catch (...) {

        }

    }
    myfile.close();
}



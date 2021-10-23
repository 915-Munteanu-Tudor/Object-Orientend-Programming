#include "adoption.h"
#include <fstream>

void CsvAdoptionList::write() {

    ofstream myfile("user.csv");
    for (auto const &dog:this->adoptionlist) {
        myfile << dog.breed << "," << dog.name << "," << dog.age << "," << dog.photo << "\n";
    }
    myfile.close();
}

vector<Dog> &AdoptionList::getAdoptionlist() {
    return adoptionlist;
}

void AdoptionList::write() {

}

void HtmlAdoptionList::write() {
    ofstream myfile("usr.html");
    myfile << "<!DOCTYPE html>" << endl << "<html>" << endl << "<head>" << endl << "<title>Adoption list</title>"
           << endl << "</head>" << endl << "<body>" << "<table border=\"1\">" << endl << "<tr>" << "<td>Breed</td>"
           << endl << "<td>Name</td>" << endl << "<td>Age</td>" << endl << "<td>Photo link</td>" << endl << "</tr>"
           << "<tr>" << endl;
    for (auto const &dog:this->getAdoptionlist()) {
        myfile << "<tr>" << "<td>" << dog.getBreed() << "</td>" << "<td>" << dog.getName() << "</td>" << "<td>"
               << dog.getAge() << "</td>" << "<td>" << "<a href= \""<<dog.getPhoto() << "\">Link</a></td></tr>";
    }
    myfile << "</table>\n"
              "</body>\n"
              "</html>";
    myfile.close();
}

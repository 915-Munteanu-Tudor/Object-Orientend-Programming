#include "Dog.h"
#include<iostream>
#include <sstream>
using namespace std;
Dog::Dog() =default;

Dog::Dog(string breed, string name, int age, string photo)
{
    //here the dog object is created
	this->breed=std::move(breed);
	this->name = std::move(name);
	this->age= age;
	this->photo = std::move(photo);
}

Dog::~Dog()
{
    //destructor
    std::cout << "";
}

//getters and to string function for the printing part
string Dog::getBreed() const
{
	return this->breed;
}
string Dog::getName() const
{
	return this->name;
}
int Dog::getAge() const
{
    return this->age;
}
string Dog::getPhoto() const
{
    return this->photo;
}
string Dog::toString() const
{
    stringstream buffer;
    buffer << "Dog \n\t breed: " << this->breed << " "<< std::endl << "\t name: " << this->name << std::endl << "\t age: " << this->age << std::endl << "\t photo: " << this->photo << std::endl << std::endl;
    return buffer.str();
}

ostream &operator<<(ostream &os, const Dog &dog) {
    os << "Dog \n\t breed: " << dog.breed << " "<< std::endl << "\t name: " << dog.name << std::endl << "\t age: " << dog.age << std::endl << "\t photo: " << dog.photo << std::endl << std::endl;
    return os;
}

istream &operator>>(istream &is, Dog &dog) {
    string line;
    int k=0, q=0;
    string newstr[11];
    std::getline(is,line);
    if (line.empty())
        throw std::runtime_error("empty line");
    int cont = 0;
    for (k = 0; k < (line.size()); k++) {
        if (line[k] == ',' || line[k] == '\0') {
            //newstr[cont][q] = '\0';
            cont++;  //for next word
            //q = 0;  //for next word, init index to 0
        } else {
            newstr[cont] += line[k];
            q++;
        }
    }
    dog.breed = newstr[0];
    dog.name = newstr[1];
    dog.age = stoi(newstr[2]);
    dog.photo = newstr[3];
    return is;
}

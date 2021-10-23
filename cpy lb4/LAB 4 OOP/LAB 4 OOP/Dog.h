#pragma once
#include<iostream>
using namespace std;
//DOGS ARE UNIQUE BY THEIR NAME
class Dog
{
public:
	string breed;
	string name;
	int age{};
	string photo;
public:
	Dog();

    Dog(string breed, string name, int age, string photo);

    ~Dog();

    string getBreed() const;

    string getName() const;

    int getAge() const;

    string getPhoto() const;

    string toString() const;

    friend ostream &operator<<(ostream &os, const Dog &dog);

    friend istream &operator>>(istream &is, Dog &dog);

};


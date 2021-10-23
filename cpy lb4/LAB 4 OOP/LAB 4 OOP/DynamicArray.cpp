#include"Dog.h"
//#include "DynamicArray.h"
#include<iostream>
#include <cstdlib>
using namespace std;
//functions and domain of the dynamic array dedicated to the admin mode

DynamicArray::DynamicArray(){
    //dynamic array constructor
	this->capacity = 2;
	this->lenght = 0;
	this->data = new TT[capacity];

}

DynamicArray::~DynamicArray()
{
    //dynamic array destructor
	cout << "Bye";
	delete[] this->data;
}
DynamicArray::DynamicArray(const DynamicArray& copied_arr)
{
	this->capacity = copied_arr.capacity;
	this->lenght = copied_arr.lenght;
	this->data = new TT[copied_arr.capacity];
	for (int i = 0; i < copied_arr.lenght; i++)
	{
		this->data[i] = copied_arr.data[i];
	}
}
void DynamicArray::resize() {
    //resize function for the moment when the length = capacity
	this->capacity = this->capacity * 2;
	TT* newArray = new TT[this->capacity];
	for (int i = 0; i < this->lenght; i++)
		newArray[i] = this->data[i];
	delete[] this->data;
	this->data = newArray;
}

void DynamicArray::insertAtEnd(TT& elem)
{
    //add a new object in the array at the end
    int ok=1;
    for (int i = 0; i < this->getLenght(); i++) {
        if (this->data[i].getName() == elem.getName()) {
            ok = 0;
            break;
        }
    }
    if (ok == 1){
        if (this->capacity == this->lenght)
            this->resize();
        this->data[this->lenght] = elem;
        this->lenght++;
    }
    else{
        printf("The dog you want to add already exists.\n");
    }

}
void DynamicArray::showArray() const
{
    //prints all the elements of the array
    for (int i = 0; i < this->lenght; i++) {
        this->data[i].toString();
    }
}

void DynamicArray::deleteElem(const string& nm)
{
    int ok=1;
    //deletes a specific element from the array
    for (int i = 0; i < this->lenght; i++) {
        if (this->data[i].getName() == nm){
            for (int j = i; j < this->lenght-1 ; j++) {
                this->data[j] = this->data[j+1];
            }
            ok=0;
            this->lenght--;
            break;
        }
    }
    if (ok==1){
        printf("This dog does not exist.\n");
    }
}

void DynamicArray::updateElem(const string & nm,const string& nm1, const string& nm2, char ag[25], const string& nm3) {
    //updates a specific element of the array
    int ok=0;

    for (int i = 0; i < this->lenght ; i++) {
        if(this->data[i].name == nm){
            this->data[i].breed = nm1;
            this->data[i].name= nm2;
            this->data[i].age = strtol(ag,nullptr,10);
            this->data[i].photo = nm3;

            ok=1;
            break;
        }
    }
    if (ok==0){
        printf("The entered dog does not exist.\n\n");
    }
}

//getters and setters for the array
int DynamicArray::getLenght() const
{
	return this->lenght;
}
int DynamicArray::getCapacity()
{
	return this->capacity;
}
void DynamicArray::setCapacity(int new_cap)
{

	this->capacity = new_cap;
}
void DynamicArray::setLenght(int new_len)
{
	this->lenght = new_len;
}
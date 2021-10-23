#pragma once
#include"Dog.h"
#include "DynamicArrayItterator.h"
#include <iostream>
#include <cstring>

using namespace std;
typedef Dog TT;
template<typename TT>
class DynamicArray
{
public:
	int capacity{};
	int lenght{};
	TT* data;
public:
	DynamicArray();
	void init_array();
	//DynamicArray(int capacity); //our data vector is dynamic
	~DynamicArray();//destructor
	DynamicArray(const  DynamicArray& arr);//copy constructor
	void insertAtEnd(TT& elem);
	void resize();
    void showArray() const;
    void deleteElem(const string& nm);
    void updateElem(const string& nm, const string& nm1, const string& nm2, const char *ag, const string& nm3);
	int getLenght() const;
	int getCapacity();
    DynamicArrayIterator iterator() const;
    void dog_breed_age(const string& nm, char nm1[25]);
};

template<typename TT>
DynamicArray<TT>::DynamicArray(){
    //dynamic array constructor
    this->capacity = 2;
    this->lenght = 0;
    this->data = new TT[capacity];

}

template<typename TT>
DynamicArray<TT>::~DynamicArray()
{
    //dynamic array destructor
    cout << "";
    delete[] this->data;
}

template<typename TT>
DynamicArray<TT>::DynamicArray(const DynamicArray& copied_arr)
{
    //makes a copy of the array
    this->capacity = copied_arr.capacity;
    this->lenght = copied_arr.lenght;
    this->data = new TT[copied_arr.capacity];
    for (int i = 0; i < copied_arr.lenght; i++)
    {
        this->data[i] = copied_arr.data[i];
    }
}

template<typename TT>
void DynamicArray<TT>::resize() {
    //resize function for the moment when the length = capacity
    this->capacity = this->capacity * 2;
    TT* newArray = new TT[this->capacity];
    for (int i = 0; i < this->lenght; i++)
        newArray[i] = this->data[i];
    delete[] this->data;
    this->data = newArray;
}

template<typename TT>
void DynamicArray<TT>::insertAtEnd(TT& elem)
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
        printf("The dog you want to add already exists.\n\n");
    }

}

template<typename TT>
void DynamicArray<TT>::showArray() const
{
    //prints all the elements of the array
    for (int i = 0; i < this->lenght; i++) {
        cout<<this->data[i].toString();
    }
    if (this->getLenght() == 0)
        printf("\nThe list is empty.\n\n");
}

template<typename TT>
void DynamicArray<TT>::deleteElem(const string& nm)
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

template<typename TT>
void DynamicArray<TT>::updateElem(const string & nm, const string& nm1, const string& nm2, const char *ag, const string& nm3) {
    //updates a specific element of the array
    int ok=0;

    for (int i = 0; i < this->lenght ; i++) {
        if(this->data[i].name == nm){
            this->data[i].breed = nm1;
            this->data[i].name= nm2;
            this->data[i].age = strtod(ag, nullptr);
            this->data[i].photo = nm3;

            ok=1;
            break;
        }
    }
    if (ok==0){
        printf("The entered dog does not exist.\n\n");
    }
}

template<typename TT>
DynamicArrayIterator DynamicArray<TT>::iterator() const {
    //returns the iterator
    return DynamicArrayIterator(*this);
    //BC=WC=AC=THETA(this.nrElems)
}

template<typename TT>
void DynamicArray<TT>::dog_breed_age(const string& nm, char nm1[25]){
    //prints the dogs of a certain breed which have the age less than a given number, if exist
    int k=0;
    if (nm.empty()){
        showArray();
        k++;
    }
    else{
        for (int i = 0; i < this->lenght; i++)
            if (nm == this->data[i].breed && this->data[i].age < strtod(nm1, nullptr)) {
                cout << this->data[i].toString();
                k++;
            }
    }
    if (k==0)
        printf("\nThere is no dog of this breed and age.\n\n");

}

template<typename TT>
void DynamicArray<TT>::init_array()
{
    //the repo where the array is initialized with 10 elements

    Dog dog1("labrador", "Jackie", 1, "http://www.zooland.ro/data/Image/image/cainele-alb.jpg");
    this->insertAtEnd(dog1);
    Dog dog2("pitbull", "Pitty", 3, "https://www.animalzoo.ro/wp-content/uploads/2017/05/cu11-604x515.jpg");
    this->insertAtEnd(dog2);
    Dog dog3("maidanez", "Bruno", 5, "http://www.magazinoutdoor.ro/blog/wp-content/uploads/2019/12/caine-de-vanatoare-Pointer.jpg");
    this->insertAtEnd(dog3);
    Dog dog4("bichon", "Bob", 2, "http://www.magazinoutdoor.ro/blog/wp-content/uploads/2019/12/Golden-Retriever.jpg");
    this->insertAtEnd(dog4);
    Dog dog5("akita", "Aky", 1, "http://www.magazinoutdoor.ro/blog/wp-content/uploads/2019/12/English-Setter.jpg");
    this->insertAtEnd(dog5);
    Dog dog6("retriever", "Goldie", 7, "http://www.magazinoutdoor.ro/blog/wp-content/uploads/2019/12/Irish-Setter.jpg");
    this->insertAtEnd(dog6);
    Dog dog7("bulldog", "Chelutu", 4, "http://www.magazinoutdoor.ro/blog/wp-content/uploads/2019/12/Beagle.jpeg");
    this->insertAtEnd(dog7);
    Dog dog8("teckel", "Thor", 9, "http://www.magazinoutdoor.ro/blog/wp-content/uploads/2019/12/Bloodhound.jpg");
    this->insertAtEnd(dog8);
    Dog dog9("ciobanesc german", "Lupu", 3, "http://www.magazinoutdoor.ro/blog/wp-content/uploads/2019/12/English-Springer-Spaniel.jpg");
    this->insertAtEnd(dog9);
    Dog dog10("maidanez", "Marta", 3, "http://www.magazinoutdoor.ro/blog/wp-content/uploads/2019/12/Weimaraner.jpg");
    this->insertAtEnd(dog10);
}

//getters and setters for the array

template<typename TT>
int DynamicArray<TT>::getLenght() const
{
    return this->lenght;
}

template<typename TT>
int DynamicArray<TT>::getCapacity()
{
    return this->capacity;
}

#include "Medicine.h"
#include <string.h>
#include <stdio.h>

Medicine createMedicine(char name[], int concentration, int quantity, int price)
{
    // this function creates an element of type medicine
    Medicine m;
    strcpy(m.name, name);
    m.concentration=concentration;
    m.quantity=quantity;
    m.price=price;

    return m;
}

char* getName(Medicine* m)
{
    //returns the name of the medicine
    return m->name;
}

float getConcentration(Medicine* m)
{
    //returns the concentration of the medicine
    return m->concentration;
}

int getQuantity(Medicine* m)
{
    //returns the quantity of the medicine
    return m->quantity;
}

float getPrice(Medicine* m)
{
    //returns the price of the medicine
    return m->price;
}

void toString(Medicine m)
{
    //converts to string a medicine
    printf("%s,%d,%d,%d.\n", m.name, m.concentration, m.quantity, m.price);
}
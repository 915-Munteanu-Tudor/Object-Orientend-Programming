#pragma once

typedef struct
{
    //defines the type and the fields of the medicine
    char name[50];
    int concentration;
    int quantity;
    int price;
} Medicine;

Medicine createMedicine(char name[], int concentration, int quantity, int price);
char* getName(Medicine* m);
float getConcentration(Medicine* m);
int getQuantity(Medicine* m);
float getPrice(Medicine* m);
void toString(Medicine m);

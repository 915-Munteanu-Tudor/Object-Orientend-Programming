#include "DinamicArray.h"

void initialize_array(DynamicArray* da ){
    // this is the repository where the initial dynammic array is initialised

    Medicine m1=createMedicine("xanax",12, 57,23);
    add(da, m1);
    Medicine m2=createMedicine("biseptol", 21, 87,67);
    add(da,m2);
    Medicine m3=createMedicine("biosept", 45, 22, 90);
    add(da,m3);
    Medicine m4= createMedicine("nurofen",34,55,33);
    add(da, m4);
    Medicine m5= createMedicine("decasept", 11, 44, 76);
    add(da,m5);
    Medicine m6= createMedicine("tyrozol", 54, 7, 100);
    add(da, m6);
    Medicine m7=createMedicine("dicarbocalm", 29, 9,12);
    add(da,m7);
    Medicine m8=createMedicine("artrostop", 50,12,42);
    add(da,m8);
    Medicine m9=createMedicine("paracetamol", 73, 76,2);
    add(da,m9);
    Medicine m10=createMedicine("omeprazol", 37,14,115);
    add(da,m10);

}
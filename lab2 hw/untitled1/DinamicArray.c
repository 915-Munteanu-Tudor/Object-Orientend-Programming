#include "DinamicArray.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

DynamicArray* createDynamicArray(int capacity)
{
    // creates a new dynamic array with length 0 and given capacity
    DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));
    // make sure that the space was allocated
    if (da == NULL)
        return NULL;

    da->capacity = capacity;
    da->length = 0;

    // allocate space for the elements
    da->elems = (TElement*)malloc(capacity * sizeof(TElement));
    if (da->elems == NULL)
        return NULL;

    return da;
}

void destroy(DynamicArray* arr)
{
    // frees the memory of a useless dynamic array
    if (arr == NULL)
        return;

    // free the space allocated for the planets
    free(arr->elems);
    arr->elems = NULL;

    // free the space allocated for the dynamic array
    free(arr);
    //arr = NULL; // !!!
}

// Resizes the array, allocating more space.
void resize(DynamicArray* arr)
{
    //when the lenght equals the capacity, the capacity is doubled
    arr->capacity=arr->capacity*2;
    arr->elems = (TElement*)realloc(arr->elems,arr->capacity * sizeof(TElement));
}

void add(DynamicArray* arr, TElement t)
{
    //adds a new medicine or increases it's quantity by one if it is not uniquw
    int ok=0;

    if (arr == NULL)
        return;
    if (arr->elems == NULL)
        return;

    // resize the array, if necessary

    for (int i = 0; i < arr->length ; i++) {
        if (strcmp(arr->elems[i].name, t.name)==0 && arr->elems[i].concentration == t.concentration) {
            arr->elems[i].quantity += 1;
            //printf("Medicine was added.\n");
            //toString(arr->elems[i]);
            //printf("%d", ok);
            ok = 1;
            break;
        }
    }
    //printf("%d", ok);
    if (ok==0) {
        if (arr->length == arr->capacity)
            resize(arr);
        arr->elems[arr->length] = t;
        arr->length++;
        //printf("Medicine was added!\n");
        //toString(t);
    }

}

void removeEl(DynamicArray* arr, char a[20], char a1[20]){
    //removes a medicine from a dynamic array if it exists by name and concentration
    int i,ok=0;

    for (i = 0; i < arr->length; i++) {
        if (strcmp(arr->elems[i].name, a)==0 && strtod(a1, NULL)==arr->elems[i].concentration) {
            for (int j = i; j < arr->length-1 ; j++) {
                arr->elems[j] = arr->elems[j+1];
            }

//              arr->elems[i]=arr->elems[arr->length];
            ok=1;
            //printf("Medicine was removed.\n");
            arr->length--;
            break;
            }
        }

    //printf("%d", ok);
    if(ok == 0){
        printf("There is any medicine with this name to be removed.\n\n");
    }
}


void update(DynamicArray* arr, char up[20], char up1[20], char up2[20], char up3[20], char up4[20], char up5[20])
{
    // searches for a specific medicine and it updates all it's fields with other datas
    int ok=0;

    for (int i = 0; i < arr->length ; i++) {
        if(strcmp(arr->elems[i].name, up)==0 && arr->elems[i].concentration==strtod(up1, NULL)){
            strcpy(arr->elems[i].name, up2);
            arr->elems[i].concentration=strtod(up3, NULL);
            arr->elems[i].quantity=strtod(up4, NULL);
            arr->elems[i].price=strtod(up5, NULL);
            //toString(arr->elems[i]);
            //printf("The medicine was updated!\n");
            ok=1;
            break;
        }
    }
    if (ok==0){
        printf("The entered medicine does not exist.\n\n");
    }
}

void sort_vec_ascend(DynamicArray* arr, int* vec){
    //function to sort a vector increasingly taking into account that it's elems are the indexes of the elems of an da
    //it is sorted by the concentration of the elems of the da
    int len=arr->length;
    int i,mini;

    for(i=0; i<len; i++) {
       vec[i]=i;
    }
    for (int k = 0; k < len-1 ; k++) {
        mini=k;
        for (int l = k+1; l < len ; l++)
            if(strcmp(arr->elems[vec[l]].name, arr->elems[vec[mini]].name) < 0)
                mini=l;

        int aux=vec[mini];
        vec[mini]=vec[k];
        vec[k]=aux;
    }

}

void sort_vec_descend(DynamicArray* arr, int* vec){
    //function to sort a vector descendently taking into account that it's elems are the indexes of the elems of an da
    //it is sorted by the concentration of the elems of the da
    int len=arr->length;
    int i,maxi;

    for(i=0; i<len; i++) {
        vec[i]=i;
    }
    for (int k = 0; k < len-1 ; k++) {
        maxi=k;
        for (int l = k+1; l < len ; l++)
            if(arr->elems[vec[l]].concentration > arr->elems[vec[maxi]].concentration)
                maxi=l;

        int aux=vec[maxi];
        vec[maxi]=vec[k];
        vec[k]=aux;
    }
}

void sort_meds_concentration(DynamicArray* arr, char string[20]) {
    //prints the sorted meds descendently by their concentration or a message is shown
    // if no med has the given substr
    int l=arr->capacity;

    DynamicArray *drr = createDynamicArray(l);
    filter_meds(drr, arr, string);


     if (drr->length != 0){
        int *vect = malloc(sizeof(int)*drr->length);
        sort_vec_descend(drr, vect);
        for (int i = 0; i < drr->length; i++) {
            toString(drr->elems[vect[i]]);
        }
    }
     else{
        printf("There is any element containing the given substring.\n");
    }

    destroy(drr);

}

void filter_meds(DynamicArray* drr, DynamicArray* arr, char strg[20]){
    // filters the meds which contains a given substring and saves them in a new dynamic array
    for (int i = 0; i < arr->length; i++) {
        if (strstr(arr->elems[i].name, strg)){
            add(drr, arr->elems[i]);
        }
    }
}

void sort_meds(DynamicArray* arr, char string[20]) {
    //prints the filtered meds which contains a given substring sorted ascendently
    // if they don't contain the given substring a message is shown
    //else if the given substring is empty it prints all the meds sorted alphabetically
    int l=arr->capacity;

    DynamicArray *drr = createDynamicArray(l);
    filter_meds(drr, arr, string);


    if (strcmp(&string[0], "") == 0){
        int *vect = malloc(sizeof(int)*arr->length);
        sort_vec_ascend(arr, vect);
        for (int i = 0; i < arr->length; i++)
            toString(arr->elems[vect[i]]);
//        printf("1\n");
    }
    else if (strcmp(&string[0], "") != 0){
        int *vect = malloc(sizeof(int)*drr->length);
        sort_vec_ascend(drr, vect);
        for (int i = 0; i < drr->length; i++) {
            toString(drr->elems[vect[i]]);
//        printf("2\n");
        }
    }
    else{
        printf("There is any element containing the given substring.\n");
    }

    destroy(drr);

}

void meds_in_short_supply(DynamicArray* arr, char value[10]){
    // prints the meds which are in a quantity less than a given number
    for (int i = 0; i < arr->length; i++) {
        if(arr->elems[i].quantity < strtod(value, NULL)){
            toString(arr->elems[i]);
        }
    }
}

void list_elems(DynamicArray* arr){
    // lists all the elements from the dynamic array
    for (int i = 0; i < arr->length; i++) {
        printf("%d) ", i);
        toString(arr->elems[i]);
    }
    printf("\n");
}


void testsDynamicArray()
{
    // this function contains tests for all the non ui functions which can be tested
    DynamicArray* da = createDynamicArray(2);
    if (da == NULL)
        assert(0);

    assert(da->capacity == 2);
    assert(da->length == 0);

    char name[]="Xanax";
    int concentration=20;
    int quantity=15;
    int price=24;

    Medicine m1 = createMedicine(name, concentration, quantity, price);
    add(da, m1);
    assert(da->length == 1);
    assert(strcmp(getName(&m1), "Xanax") == 0);
    assert(getConcentration(&m1) == 20);
    assert(getQuantity(&m1) == 15);
    assert(getPrice(&m1) == 24);

    Medicine m2 = createMedicine("abc", 24, 15, 24);
    add(da, m2);
    assert(da->length == 2);
    assert(da->capacity == 2);

    removeEl(da, "abc", "24");
    assert(da->length == 1);
    update(da, "Xanax", "20", "proenzi", "11", "23", "55");
    assert(da->elems[0].concentration == 11);


    Medicine m3=createMedicine("biseptol", 21, 87,67);
    add(da,m3);
    Medicine m4=createMedicine("biosept", 45, 22, 90);
    add(da,m4);

    DynamicArray* dr = createDynamicArray(2);
    filter_meds(dr, da, "pt");
    assert(strcmp(dr->elems[0].name, "biseptol") == 0);
    assert(strcmp(dr->elems[1].name, "biosept") == 0);

    int vec[5];
    sort_vec_ascend(da, vec);
    assert(da->elems[vec[0]].concentration == 45);

    int vect[5];
    sort_vec_descend(da, vect);
    assert(da->elems[vect[1]].concentration == 21);

    destroy(da);
    destroy(dr);
    assert(dr->elems == NULL);

}
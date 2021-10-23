#pragma once
#include "Medicine.h"

typedef Medicine TElement;

typedef struct
{
    TElement* elems;
    int length;			// actual length of the array
    int capacity;
} DynamicArray;

/// <summary>
/// Creates a dynamic array of generic elements, with a given capacity.
/// </summary>
/// <param name="capacity">Integer, maximum capacity for the dynamic array.</param>
/// <returns>A pointer the the created dynamic array.</returns>
DynamicArray* createDynamicArray(int capacity);

/// <summary>
/// Destroys the dynamic array.
/// </summary>
/// <param name="arr">The dynamic array to be destoyed.</param>
/// <returns>A pointer the the created dynamic array.</returns>
void destroy(DynamicArray* arr);

/// <summary>
/// Adds a generic element to the dynamic array.
/// </summary>
/// <param name="arr">The dynamic array.</param>
/// <param name="p">The planet to be added.</param>
void add(DynamicArray* arr, TElement t);

// Tests
void testsDynamicArray();

void meds_in_short_supply(DynamicArray* arr, char value[10]);

void sort_meds_concentration(DynamicArray* arr, char string[20]);

void sort_meds(DynamicArray* arr, char string[20]);

void sort_vec_ascend(DynamicArray* arr, int* vec);

void filter_meds(DynamicArray* drr, DynamicArray* arr, char strg[10]);

void resize();

void list_elems(DynamicArray* arr);

void removeEl(DynamicArray* arr, char a[20], char a1[20]);

void update(DynamicArray* arr, char up[20], char up1[20], char up2[20], char up3[20], char up4[20], char up5[20]);
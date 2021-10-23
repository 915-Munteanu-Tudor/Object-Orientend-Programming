#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DinamicArray.h"
#include "repo.h"

void printMenu(){
    //function to print the menu
    printf("1 Add a medicine.\n");
    printf("2 Delete a medicine.\n");
    printf("3 Update a medicine.\n");
    printf("4 Filter all the medicines by string.\n");
    printf("5 List the medicines.\n");
    printf("6 Filter all the medicines by string and concentration.\n");
    printf("7 List the medicines that are in short supply.\n");
    printf("8 Undo.\n");
    printf("9 Redo.\n");
    printf("10 Exit.\n");
}

void run_cmd(){
    //the function which run the menu as a console
    //it manages the input and transforms it in words in order to perform the operations
    // for undo and redo it takes the arguments when it performs an operation and keeps the track of all the operations
    // when undo or redo is called it performs the inverse operation of the specific operation which has to be undone or redone

    int run = 1, i, j, ctr, i1, j1, ctr1, lengt, q=0;
    int l1=0;
    int ctr2,j2,i2;
    char str1[400];
    char op[100];
    char str[100];

    //strcpy(&op[0],"5");
    DynamicArray *da = createDynamicArray(10);
    initialize_array(da);
    lengt=1;

    while (run == 1) {
        char newString[20][20];
        char undoString[30][35];
        char redoString[30][35];
        printMenu();
        printf("Type an instruction:");
        gets(str1);
        ctr = 0;
        j = 0;
        for (i = 0; i <= (strlen(str1)); i++) {
            if (str1[i] == ',' || str1[i] == '\0') {
                newString[ctr][j] = '\0';
                ctr++;  //for next word
                j = 0;    //for next word, init index to 0
            } else {
                newString[ctr][j] = str1[i];
                j++;
            }
        }
        if ((strcmp(newString[0], "1") ==0 && ctr!=5) || (strcmp(newString[0], "2") ==0 && ctr!=3) || (strcmp(newString[0], "3") ==0 && ctr!=7)){
            printf("\nThere number of inputed arguments is wrong!\n\n");
        }
        else if (strcmp(newString[0], "1") == 0) {

            printf("\n");
            Medicine m = createMedicine(newString[1], strtod(newString[2], NULL), strtod(newString[3], NULL),
                                        strtod(newString[4], NULL));
            add(da, m);
            printf("Medicine was added!\n");

            //if((strcmp(&op[q-1], "8") != 0)){
                lengt++;
                printf("\n");
                strcat(undoString[lengt-1], "1 ");
                strcat(undoString[lengt-1], newString[1]);
                strcat(undoString[lengt-1], " ");
                strcat(undoString[lengt-1], newString[2]);
                strcpy(&op[q], "1");
                q++;
            //}


        } else if (strtod(newString[0], NULL) == 2) {

           // if ((strcmp(&op[q - 1], "8") != 0)) {
                lengt++;
                for (int k = 0; k < da->length; k++) {
                    if (strcmp(newString[1], da->elems[k].name) == 0 &&
                        da->elems[k].concentration == strtod(newString[2], NULL)) {
                        strcat(undoString[lengt - 1], "2 ");
                        strcat(undoString[lengt - 1], newString[1]);
                        strcat(undoString[lengt - 1], " ");
                        strcat(undoString[lengt - 1], newString[2]);
                        strcat(undoString[lengt - 1], " ");
                        strcat(undoString[lengt - 1], itoa(da->elems[k].quantity, str, 10));
                        strcat(undoString[lengt - 1], " ");
                        strcat(undoString[lengt - 1], itoa(da->elems[k].price, str, 10));
                        strcpy(&op[q], "2");
                        q++;
                        break;
                    }
                }
           // }

            printf("\n");
            removeEl(da, newString[1], newString[2]);
            //printf("The medicine was removed!\n");

        }
        else if (strcmp(newString[0], "3")==0){
            //if((strcmp(&op[q-1], "8") != 0)){
                lengt++;
                for (int p = 0; p < da->length; p++) {
                    if(strcmp(newString[1], da->elems[p].name)==0 && da->elems[p].concentration == strtod(newString[2], NULL)){
                        strcat(undoString[lengt-1], "3 ");
                        strcat(undoString[lengt-1], newString[3]);
                        strcat(undoString[lengt-1], " ");
                        strcat(undoString[lengt-1], newString[4]);
                        strcat(undoString[lengt-1], " ");
                        strcat(undoString[lengt-1], newString[1]);
                        strcat(undoString[lengt-1], " ");
                        strcat(undoString[lengt-1], newString[2]);
                        strcat(undoString[lengt-1], " ");
                        strcat(undoString[lengt-1], itoa(da->elems[p].quantity, str, 10));
                        strcat(undoString[lengt-1], " ");
                        strcat(undoString[lengt-1], itoa(da->elems[p].price, str, 10));
                        strcpy(&op[q], "3");
                        q++;
                        break;
                    }
                }
           // }
            printf("\n");
            update(da, newString[1], newString[2], newString[3], newString[4], newString[5], newString[6]);
            printf("The medicine was updated!\n\n");
        }
        else if (strcmp(newString[0], "4") == 0) {
            printf("\n");
            sort_meds(da, newString[1]);
            printf("\n");

        }
        else if (strtod(newString[0], NULL) == 5){
            printf("\n");
            list_elems(da);
        }
        else if (strtod(newString[0], NULL) == 6){
            printf("\n");
            sort_meds_concentration(da, newString[1]);
            printf("\n");
        }
        else if (strtod(newString[0], NULL) == 7){
            printf("\n");
            meds_in_short_supply(da, newString[1]);
            printf("\n");
        }
        else if (strtod(newString[0], NULL) == 8){
            j1=0;
            ctr1=0;
            char und[30][40];
            for (i1 = 0; i1 <= (strlen(undoString[lengt-1])); i1++) {
                if (undoString[lengt-1][i1] == ' ' || undoString[lengt-1][i1] == '\0') {
                    und[ctr1][j1] = '\0';
                    ctr1++;  //for next word
                    j1 = 0;    //for next word, init index to 0
                } else {
                    und[ctr1][j1] = undoString[lengt-1][i1];
                    j1++;
                }
            }
            if(lengt >1){
                strcpy(&op[q], "8");
                q++;
                if(strcmp(und[0], "1") == 0) {
                    printf("\n");

                    for (int k = 0; k < da->length; k++) {
                        if (strcmp(da->elems[k].name, und[1]) == 0 && da->elems[k].concentration == strtod(und[2], NULL)){
                            l1++;
                            strcat(redoString[l1], "1 ");
                            strcat(redoString[l1], und[1]);
                            strcat(redoString[l1], " ");
                            strcat(redoString[l1], und[2]);
                            strcat(redoString[l1], " ");
                            strcat(redoString[l1], itoa(da->elems[k].quantity, str, 10));
                            strcat(redoString[l1], " ");
                            strcat(redoString[l1], itoa(da->elems[k].price, str, 10));
                            break;
                            }
                        }
                    removeEl(da, und[1], und[2]);
                    printf("Undo done!\n\n");
                    lengt--;
                    undoString[lengt][0]='\0';
                }
                else if(strcmp(und[0], "2") == 0){
                    printf("\n");
                    Medicine m1= createMedicine(und[1], strtod(und[2], NULL), strtod(und[3], NULL), strtod(und[4], NULL));
                    add(da, m1);
                    l1++;
                    strcat(redoString[l1], "2 ");
                    strcat(redoString[l1], und[1]);
                    strcat(redoString[l1], " ");
                    strcat(redoString[l1], und[2]);
                    strcat(redoString[l1], " ");
                    printf("Undo done\n\n");
                    lengt--;
                    undoString[lengt][0]='\0';
                }
                else if (strcmp((und[0]), "3") == 0){

                    printf("\n\n");

                    for (int k = 0; k < da->length; k++) {
                        if (strcmp(und[1], da->elems[k].name) == 0 && da->elems[k].concentration == strtod(und[2], NULL)) {
                            l1++;
                            strcat(redoString[l1], "3 ");
                            strcat(redoString[l1], und[3]);
                            strcat(redoString[l1], " ");
                            strcat(redoString[l1], und[4]);
                            strcat(redoString[l1], " ");
                            strcat(redoString[l1], und[1]);
                            strcat(redoString[l1], " ");
                            strcat(redoString[l1], und[2]);
                            strcat(redoString[l1], " ");
                            strcat(redoString[l1], itoa(da->elems[k].quantity, str, 10));
                            strcat(redoString[l1], " ");
                            strcat(redoString[l1], itoa(da->elems[k].price, str, 10));
                            break;
                        }
                    }
                    update(da, und[1], und[2], und[3], und[4], und[5], und[6]);
                    printf("Undo done!\n\n");
                    lengt--;
                    undoString[lengt][0]='\0';
                }
            }

            else{
                printf("\n");
                printf("There is no undo to be performed.\n");
                printf("\n");
            }
        } else if(strcmp(newString[0], "9") == 0) {
            j2 = 0;
            ctr2 = 0;
            char red[30][40];
            for (i2 = 0; i2 < (strlen(redoString[l1])); i2++) {
                if (redoString[l1][i2] == ' ' || redoString[l1][i2] == '\0') {
                    red[ctr2][j2] = '\0';
                    ctr2++;  //for next word
                    j2 = 0;    //for next word, init index to 0
                } else {
                    red[ctr2][j2] = redoString[l1][i2];
                    j2++;
                }
            }


            if (l1 > 0) {
                strcpy(&op[q], "9");
                q++;
                if (strcmp(red[0], "1") == 0) {
                    printf("\n");
                    Medicine m = createMedicine(red[1], strtod(red[2], NULL), strtod(red[3], NULL),
                                                strtod(red[4], NULL));
                    add(da, m);
                    lengt++;
                    strcat(undoString[lengt-1], "1 ");
                    strcat(undoString[lengt-1], newString[1]);
                    strcat(undoString[lengt-1], " ");
                    strcat(undoString[lengt-1], newString[2]);
                    printf("Redo done!\n\n");
                    l1--;
                    redoString[l1][0] = '\0';

                } else if (strcmp(red[0], "2") == 0) {
                        lengt++;
                        for (int k = 0; k < da->length; k++) {
                            if (strcmp(newString[1], da->elems[k].name) == 0 &&
                                da->elems[k].concentration == strtod(newString[2], NULL)) {
                                strcat(undoString[lengt - 1], "2 ");
                                strcat(undoString[lengt - 1], newString[1]);
                                strcat(undoString[lengt - 1], " ");
                                strcat(undoString[lengt - 1], newString[2]);
                                strcat(undoString[lengt - 1], " ");
                                strcat(undoString[lengt - 1], itoa(da->elems[k].quantity, str, 10));
                                strcat(undoString[lengt - 1], " ");
                                strcat(undoString[lengt - 1], itoa(da->elems[k].price, str, 10));
                                break;
                            }
                        }

                    printf("\n");
                    removeEl(da, red[1], red[2]);
                    printf("Redo done!\n\n");
                    redoString[l1][0] = '\0';
                    l1--;
                } else if (strcmp(red[0], "3") == 0) {
                    printf("\n");
                    lengt++;
                    for (int p = 0; p < da->length; p++) {
                        if(strcmp(newString[1], da->elems[p].name)==0 && da->elems[p].concentration == strtod(newString[2], NULL)){
                            strcat(undoString[lengt-1], "3 ");
                            strcat(undoString[lengt-1], newString[3]);
                            strcat(undoString[lengt-1], " ");
                            strcat(undoString[lengt-1], newString[4]);
                            strcat(undoString[lengt-1], " ");
                            strcat(undoString[lengt-1], newString[1]);
                            strcat(undoString[lengt-1], " ");
                            strcat(undoString[lengt-1], newString[2]);
                            strcat(undoString[lengt-1], " ");
                            strcat(undoString[lengt-1], itoa(da->elems[p].quantity, str, 10));
                            strcat(undoString[lengt-1], " ");
                            strcat(undoString[lengt-1], itoa(da->elems[p].price, str, 10));
                            break;
                        }
                    }
                    update(da, red[1], red[2], red[3], red[4], red[5], red[6]);
                    printf("Redo done!\n\n");
                    redoString[l1][0] = '\0';
                    l1--;
                }
            }
            else{
                printf("\n");
                printf("There is no more redo to be performed!\n\n");
            }
        }
        else if (strtod(newString[0], NULL) == 10) {
            printf("\n");
            printf("Bye!\n");
            run=0;
        }
        else {
            printf("\n");
            printf("Bad command. Please enter another instruction.\n");
            printf("\n");

        }
        //printf("Ultima operqatie:%c", op[q-1]);
        if (strtod(&op[q-1], NULL) != 8 && strtod(&op[q-1], NULL) != 9) {
            //printf("\nSterge istoric undo!\n\n");
            for (int k = 0; k < l1; k++) {
                redoString[k][0]='\0';
            }
            l1=0;
        }

    }
    destroy(da);
}
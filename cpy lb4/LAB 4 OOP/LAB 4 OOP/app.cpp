#include "app.h"
#include "exceptions.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <repoDog.h>

using namespace std;

//void Console::read_from_file() {
//
//    string line;
//    ifstream myfile ("input.txt");
//    while (true){
//        if (myfile.eof()) {
//            break;
//        }
//        Dog dog;
//
//        try {
//            myfile>>dog;
//            this->repoDog.add_dog(dog, false);
//        }
//        catch (...){
//
//        }
//
//    }
//    myfile.close();
//}


void Console::print_menu_administrator()
{
    //menu for admin mode

    printf("1 Add dog.\n");
    printf("2 Delete a dog.\n");
    printf("3 Update a dog.\n");
    printf("4 Print.\n");
    printf("5 Exit administrator mode.\n");
}

void Console::print_menu_user()
{
    //menu for user mode

    printf("1 See the adoption list.\n");
    printf("2 See the dogs of a certain breed,with the age less than a given number.\n");
    printf("3 See the dogs one by one.\n");
    printf("4 Exit user mode.\n");
}

void Console::menuForItter(){
    printf("1 Adopt.\n");
    printf("2 Next.\n");
    printf("3 Exit.\n");
}

void Console::menu_for_data_store(){
    printf("\nChose 1 to store the dogs in CSV or 2 to store them in HTML.\n");
}


void Console::run_menu_cmd()
{
    //console which runs the app splits the input in commands and validates them

    int run=1, ctr = 0,i,j, run1=1, run2=1;
    char chose1[5];
    char stq[]="start ";

    char str1[256], newString[25][25];
    repoDog.read_from_file();
    //this->read_from_file();

    while (run1 ==1)
    {
        //chose1[0]='\0';
        printf("\nChose 1 for the administrator, 2 for the user mode or 3 to exit.\n");
        printf("Type a command:");
        cin>>chose1;
        printf("\n");
        if (strcmp(chose1, "1") == 0) {
            while (run == 1) {
                label:
                print_menu_administrator();
                printf("Type a command:");
                cin >> str1;
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
                if ((strcmp(newString[0], "1") ==0 && ctr!=5) || (strcmp(newString[0], "2") ==0 && ctr!=2) || (strcmp(newString[0], "3") ==0 && ctr!=6)) {
                    printf("\nThe number of inputted arguments is wrong!\n\n");
                }
                else if (strcmp((newString[0]), "1") == 0) {
                    try {
                        this->validator.is_nr(newString[3]);
                    }
                    catch (DogException& ex) {
                        cout<<ex.what()<<endl;
                        goto label;
                    }
//                    if(!only_nr(newString[3])){
//                        printf("\nThe inputted has to be an integer.\n\n");
//
//                    }
                    try{
                        Dog dg1(newString[1], newString[2], strtol(newString[3], nullptr, 10), newString[4]);
                        this->repoDog.add_dog(dg1);
                        printf("\n");
                    }
                    catch (DogException& ex){
                        cout<<ex.what()<<endl;
                    }


                } else if (strcmp(newString[0], "2") == 0) {
                    try{
                        this->repoDog.remove_dog(newString[1]);
                        printf("\n");
                    }
                    catch (DogException& ex){
                        cout<<endl<<ex.what();
                    }

                } else if (strcmp(newString[0], "3") == 0) {
                    try {
                        this->validator.is_nr(newString[4]);
                    }
                    catch (DogException& ex) {
                        cout<<ex.what()<<endl;
                        goto label;
                    }

                    try{
                        this->repoDog.update_dog(newString[1], newString[2], newString[3], newString[4], newString[5]);
                        printf("\n");
                    }
                    catch (DogException& ex) {
                        cout<<endl<<ex.what();
                    }

                } else if (strcmp(newString[0], "4") == 0) {
                    cout<<this->repoDog.getElements();
                } else if (strcmp(newString[0], "5") == 0)
                    break;
                else
                    printf("\nBad command.\n\n");
            }
        }
        else if (strcmp(chose1, "2") == 0){
            int opt;
            menu_for_data_store();
            cin>>opt;
            if (opt == 1){
                cout<<"\nData will be stored in CSV file.\n\n";
                this->adoptionList = std::make_unique<CsvAdoptionList>();
            }
            else{
                cout<<"\nData will be stored in HTML file.\n\n";
                this->adoptionList = std::make_unique<HtmlAdoptionList>();
            }

            while (run2==1){

                //label1:
                print_menu_user();
                printf("Type a command:");
                cin >> str1;
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

                if ((strcmp(newString[0], "1") ==0 && ctr!=1) || (strcmp(newString[0], "2") ==0 && ctr!=3) || (strcmp(newString[0], "3") ==0 && ctr!=1)
                                                                                                              || (strcmp(newString[0], "4") ==0 && ctr!=1)) {
                    printf("\nThe number of inputted arguments is wrong!\n\n");
                    //goto label1;
                }
                else if (strcmp(newString[0], "1") == 0){
                    if (this->adoptionList->getAdoptionlist().empty())
                        cout<<"\nAdoption list is empty.\n\n";
                    else{
                        if (opt == 1){
                            system("start user.csv");
                            cout<<endl;
                        } else{
                            system("start usr.html");
                            cout<<endl;
                        }
                    }

                }
                else if(strcmp(newString[0], "2") == 0){
                    try {
                        this->validator.is_nr(newString[2]);
                        auto filtered = this->repoDog.filter_dogs(newString[1], newString[2]);
                        if (filtered.empty())
                            cout<<"There is no dog according to these criteria.\n";
                        else
                            cout<<filtered;
                    }
                    catch (DogException& ex) {
                        cout << ex.what() << endl;
                    }

                }
                else if (strcmp(newString[0], "3") == 0){
                    // TODO: finish with adoption iterator
                    int run3=1;
                    auto it = this->repoDog.getElements().begin();

                    int qt=0;
                    while (run3 == 1){
                        int cmd=0;
                        cout<<endl;
                        menuForItter();
                        if (qt == 0){
                            cout<<endl;
                            cout<<*it;
                            strcat(stq, it->photo.c_str());
                            system(stq);
                            stq[0]='\0';
                            strcat(stq, "start ");
                            qt++;
                        }
                        //printf("\n");
                        label2:
                        printf("Type a command:");
                        cin>>cmd;
                        printf("\n");
                        if (it == this->repoDog.getElements().end()-1 && cmd == 2)
                            goto label3;
                        if(cmd == 3){
                            printf("\n");
                            break;
                        }
                        else if(cmd==2){
                            if (it == this->repoDog.getElements().end()-1)
                                goto label3;
                            it++;
                            cout<<*it;
                            strcat(stq, it->photo.c_str());
                            //std::string s(stq);
                            system(stq);
                            if(it == this->repoDog.getElements().end()-1)
                                goto label2;

                        }
                        else if(cmd == 1){
                            Dog dgq;
                            dgq=*it;
                            //printf("The dog was adopted.\n");
                            adoptionList->getAdoptionlist().push_back(dgq);
                            this->adoptionList->write();
                            if (it == this->repoDog.getElements().end()-1)
                                goto label3;
                            it++;
                            cout<<*it;
                            strcat(stq, it->photo.c_str());
                            system(stq);
                            if(it == this->repoDog.getElements().end()-1)
                                goto label2;
                        }
                        else{
                            printf("Bad command.\n");
                        }
                        label3:
                        if(it == this->repoDog.getElements().end()-1){
                            it = this->repoDog.getElements().begin();
                            qt=0;
                        }
                        stq[0]='\0';
                        strcat(stq, "start ");

                    }

                }
                else if (strcmp(newString[0], "4") == 0){
                    break;
                }
                else{
                    printf("\n");
                    printf("Bad command!\n\n");
                }

            }
        }
        else if (strcmp(chose1, "3") == 0){
            break;
        }
        else{
            printf("Bad command.\n");
        }
        //chose1[0]='\0';
    }
    ofstream myfile("usr.html");
    myfile.close();
    ofstream myfile1("user.csv");
    myfile.close();

}

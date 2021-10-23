#include "validators.h"
#include <cstring>
#include <exceptions.h>
#include <string>

void Validator::is_nr(char string[50]) {
    int ok=1;
    for (int i = 0; i < strlen(string); i++){
        if (!(string[i] <= '9' and string[i] >= '0')){
            ok=0;
            break;
        }
    }
    if (ok ==1 and std::stoi(string) < 0)
        ok=0;
    if (ok == 0)
        throw DogException("\nThe inputted number is not int.\n");
}

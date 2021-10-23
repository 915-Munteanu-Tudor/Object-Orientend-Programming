#include <stdio.h>
#include <stdlib.h>

int prim(int x){
    //the function cheks if n is a prime number by dividing it to all the numbers between 2 and n/2 and returns 1 or 0 if it is prime or not
    int ok=1 ;
    for (int i = 2; i <= x/2 ; i++) {
        if(x%i==0){
            ok=0;
            break;
        }
    }
    if(ok==1)
        return 1;
    return 0;
}

void print_menu(){
    //the function prints the console based menu
    printf("1 Generate the prime numbers smaller than n.\n");
    printf("2 The longest increasing contiguous subsequence in a vector, such the sum of that any 2 consecutive elements is prime.\n");
    printf("3 Decompose a given natural number in it's prime factors.\n");
    printf("4 Exit.\n");

}

void prim_factor(int x){
    int d=2;
    int p;
    while(x>1){
        p=0;
        while (x%d==0){
            ++p;
            x/=d;
        }
        if(p!=0)
            printf("Factor:%d, power:%d.\n", d, p);
        ++d;
    }

}

void prim_less_n(){
    //the function prints all the prime numbers less than a given n number
    int n=0;
    printf("n=");
    scanf("%d", &n);
    for (int i = 2; i < n ; i++) {
        if (prim(i)==1)
            printf("%d ", i);

    }
}

void longest_subsequence(int a[], int size){
    //the function finds the longest continous subsequence in a vector with the sum of any 2 consecutive numbers a prime number
    // we check if the sum of every 2 consecutive numbers is prime and retain the indexes of the begining and the end of the subsequence
    //if we find a good subsequence we update the final indexes and we reset that ones used to search another one
    //after the end of the while we check again for a longer subsequence because the loop can't check if the vector ends with the longest subsequence
    int b=0, bf=0;
    int ff=0;
    int l=0, lf=0;
    int i=0;
    while (i<size-1)
        if (prim(a[i]+a[i+1])) {
            l++;
            i++;


        }
        else if (l>lf) {
            lf = l;
            bf=b;
            b=i+1;
            l=0;
            ff=bf+lf+1;
            i++;
        }
        else {
            b=i+1;
            l=0;
            i++;

        }

    if (l>lf) {
        lf = l;
        bf=b;
        ff=bf+lf+1;
    }
    if(lf==0 && bf==0)
        printf("There is no subsequence as it is asked to search.");
    else{
        printf("The longest subsequence:");
        for (int j = bf; j <ff ; j++)
            printf("%d ", a[j]);
    }
}
void  console(){
    //this function is used to run the program until it is closed by the user when he inputs "3"
    // the function calls the functions "prim_less" or "longest_subsequence" asking for input in addition for the last one, depending on the user's input
    int run=1;
    //int a[]={1,1,4,3,2,3,5,2,3,4,1,2,3,4,1,7,4,3};
    int n=0;
    int q;
    int x=0;
    int y=0;
    int i;
    int* a;
    //printf("n=");
    //scanf("%d", &n);
    while (run==1){
        print_menu();
        printf("Type the command:");
        scanf("%d", &x);
        if(x==1) {
            prim_less_n();
            printf("\n");
            printf("\n");
        }
        else if (x==2) {
            printf("The size of the vector is:");
            scanf("%d", &n);
            a=(int*)malloc(n*sizeof(int));
            for(i=0; i<n; i++){
                printf("Input a number:");
                scanf("%d", &y);
                a[i]=y;
            }
            printf("\n");
            longest_subsequence(a, n);
            printf("\n");
            printf("\n");
        }
        else if (x==3){
            printf("The number is:");
            scanf("%d", &q);
            prim_factor(q);
            printf("\n");

        }
        else if (x==4)
            break;
        else {
            printf("Bad command.");
            printf("\n");
            printf("\n");
        }

    }
}

int main() {
    console();
}

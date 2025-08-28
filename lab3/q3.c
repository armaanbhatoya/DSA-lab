//check |b| == |r| without counting 
#include<stdio.h>

void add_r(char R[], int* R_top ){
    R[++(*R_top)] = 'r';  
}

int delete_r(int* R_top ){
    if(*R_top >= 0){
        (*R_top)--;   
        return 1;
    }
    else {
        return 0;  // no r to match b
    }
}

int main(){
    char arr[100]; // Increased size for user input
    printf("Enter the string of r's and b's: ");
    scanf("%99s", arr);

    char R[sizeof(arr)];
    int R_top = -1; 
    
    int valid = 1;   

    for (int i = 0; arr[i] != '\0'; i++) {
        if(arr[i] == 'r') {
            add_r(R, &R_top);
        }
        else if(arr[i] == 'b') {
            if(!delete_r(&R_top)) { 
                valid = 0;  
                break;
            }
        }
    }

    if(valid && R_top == -1) 
        printf("|b| = |r|\n");
    else 
        printf("|b| != |r|\n");

    return 0;
}

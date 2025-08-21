// A king suspects that one out of 1000 honey bottles has been poisoned.
// He has 10 lab rats available and wants to identify the poisoned bottle
// with a single round of testing, after which the rats will either die or
// survive. Each rat can drink from multiple bottles, and the poison will
// kill a rat within 24 hours. Each honey bottle is assigned a unique
// number from 1 to 1000, and its binary representation determines
// which rats will taste it. Write a C program to simulate this scenario.
// Accept the poisoned bottle number as input. Using the living status of
// the rats, reconstruct and print the poisoned bottle number.

#include<stdio.h>

int main(){

    int pois_bot;
    printf("enter the poisened bottle number(1-1000): ");
    scanf("%d",&pois_bot);

    if(pois_bot<=0 || pois_bot>1000){
        printf("__invalid bottle number__");
        return 1;
    }

    int rats[10] = {0};
    for(int i=0; i<10; i++){
        if(pois_bot>>i & 1){
            rats[i]=1;
        }
    }

    printf("Rats status after tasting:\n");

    for(int i=0; i<10; i++){
        printf("Rat %d : %s\n",i+1,rats[i]?"Dead":"Alive");
    }
    
    int bottle_found=0;
    for(int i=0; i<10; i++){
        if(rats[i]==1){
            bottle_found = bottle_found | (1<<i);
        }
    }
    printf("Reconstructed bottle number : %d\n", bottle_found);
    return 0;
}


//storing 10 employee details by making nodes

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee{
    char name[20];
    double salary;
};

struct A{
    struct Employee p;   //present
    struct A *q;    //next struct pointer
};

int main(){
    struct A *temp = NULL, *head = NULL , *prev = NULL;
    
    int n=10;
    for (int i = 0; i < n; i++)
    {
        temp = (struct A*)malloc(sizeof(struct A));
        printf("Enter the Employee %d name : ", i+1);
        scanf(" %19s",temp->p.name);
        printf("Enter the salary : ");
        scanf(" %lf",&temp->p.salary);
        temp->q = NULL;

        if(head == NULL){
            head = temp;
        }
        else{
            prev->q = temp;
        }
        prev = temp;
    }

    printf("\nEmployee details :->\n");
    temp = head;
    int i = 1;
    while(temp != NULL){
        printf("Employee %d name   : %s\n", i, temp->p.name);
        printf("           salary : %.2lf\n", temp->p.salary);
        temp = temp->q;
        i++;
    }

    return 0;
}
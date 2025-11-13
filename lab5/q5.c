//

# include<stdio.h>
# include<stdlib.h>

struct node {
    int value;
    struct node* next;
};

int main(){
    struct node* arr[5];
    struct node *temp,*q[5];//q[5]: used to track the last node in each bucket for easy insertion at the end
    for (int i=0; i<5; i++){
        arr[i]=NULL;
    }
    for (int i=0; i<5; i++){
        temp=(struct node *)malloc(sizeof(struct node));
        temp->next=NULL;
        printf("Enter value : ");
        scanf("%d",&temp->value);
        int n=(temp->value)%5;
        if (arr[n]==NULL){
            arr[n]=temp;
            q[n]=arr[n];
        }
        else{
            q[n]->next=temp;
            q[n]=temp;
        }
    }
    for(int i=0; i<5; i++){
        struct node*print=arr[i];
        if (print!=NULL) printf("Values at index %d:\n",i);
        while (print!=NULL){
            printf("%d\n",print->value);
            print=print->next;
        }

    }
    return 0;
}
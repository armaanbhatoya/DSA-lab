// arrray insertion deletion
#include<stdio.h>

void display_array(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

void insert_ele(int arr[], int* n, int pos, int value){
    if(pos<0 || pos>*n){
        printf("invalid position(index)\n");
        return;
    }
    for(int i=*n; i>pos; i--){
        arr[i]=arr[i-1];
    }
    arr[pos] = value;
    (*n)++;
    printf("element inserted successfully\n");
}

void delete_ele(int arr[], int* n, int pos){
    if(pos<0 || pos>*n)  {
        printf("invalid position(index)\n");
        return;
    }
    for (int i = pos; i < (*n) - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
    printf("element deleted successfully\n");
}

int main(){
    int n ;
    int arr[100];
    printf("enter the size of the array(1-100): ");
    scanf("%d", &n);
    printf("enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    while(1){
        printf("\nMENU\n");
        printf("1. Display array's elements.\n");
        printf("2. Insert element\n");
        printf("3. Delete element\n");
        printf("4. EXIT\n");
        
        int m;
        scanf("%d",&m);
        
        int pos, value;
        switch (m)
        {
        case 1:
            display_array(arr, n);
            break; 

        case 2:
            printf("enter position(index) and value to be added: ");
            scanf("%d %d", &pos , &value);
            insert_ele(arr, &n, pos, value);
            break; 

        case 3:
            printf("enter position(index) of element to be deleted: ");
            scanf("%d", &pos);
            delete_ele(arr, &n, pos);
            break;
        
        case 4:
            return 0;

        default:
            printf("select valid option\n");
            break;
        }
    }

    return 0;
}
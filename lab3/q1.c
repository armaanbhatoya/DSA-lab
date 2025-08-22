//insert/delete elements in an array like a stack;
#include <stdio.h>

void insert(int arr[], int *top)
{
    if (*top < 99)
    {
        printf("enter element to insert: ");
        scanf("%d", &arr[++(*top)]);
    }
    else printf("Space not available!");

    return;
}

void delete( int* top){
    if(*top>=0) --(*top);
    
    printf("element deleted successfully\n");
}

void display(int arr[], int top)
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

int main()
{
    int n = 100;
    int arr[n];
    int top = -1;
    int c;
    while (1)
    {
        printf("--Menu--\n1.insert element\n2.delete element\n3.display\n4.exit\nEnter choice: ");
        scanf("%d",&c);
        
        switch (c)
        {
        case 1:
            insert(arr,&top);
            break;
        case 2:
            delete(&top);
            break;
        case 3:
            display(arr,top);
            break;
        case 4:
            return 0;
        default:
            printf("Enter valid choice");
            break;
        }
    }
    
    return 0;
}
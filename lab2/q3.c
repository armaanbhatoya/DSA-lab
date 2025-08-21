//stock list deletion and insertiion
#include <stdio.h>
#include <string.h>
#define N 10

struct Stocks
{
    char name[20];
    int price;
};

void sort_arr(struct Stocks arr[], int n)
{
    struct Stocks temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j].price > arr[j + 1].price)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{

    struct Stocks arr[N];
    for (int i = 0; i < N; i++)
    {
        printf("\nEnter the Name of stock %d : ", i + 1);
        scanf("%s", &arr[i].name);
        printf("\nEnter the price : ");
        scanf("%d", &arr[i].price);
    }

    int choice;

    while (1)
    {
        printf("\n--Select Choice--\n");
        printf("1.Modify\n");
        printf("2.Print\n");
        printf("3.EXIT\n");

        scanf("%d", &choice);
        char oldname[20];
        char newname[20];
        int newprice;

        switch (choice)
        {
        case 1:
            printf("enter stock name to delete: ");
            scanf("%s", oldname);
            printf("enter new stock name to add: ");
            scanf("%s", newname);
            printf("enter new stock price: ");
            scanf("%d", &newprice);
            int found = 0;
            for (int i = 0; i < N; i++)
            {
                if (strcmp(arr[i].name, oldname) == 0)
                {
                    strcpy(arr[i].name, newname);
                    arr[i].price = newprice;
                    found = 1;
                    break;
                }
            }
            if (found == 0)
                printf("stock not found!\n");

            break;

        case 2:
            sort_arr(arr, N);
            printf("Stock list:->\n");
            for (int i = 0; i < N; i++)
            {
                printf("%s\t%d\n", arr[i].name, arr[i].price);
            }
            break;

        case 3:
            return 0;
            break;

        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}
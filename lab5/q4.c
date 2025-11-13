#include <stdio.h>
#include <stdlib.h>

struct page
{
    int name;
    struct page *next;
    struct page *prev;
};

int main()
{
    struct page *start = NULL;
    struct page *q, *temp;
    int n, cnt = 1;
    printf("Enter page in which you are : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        temp = (struct page *)malloc(sizeof(struct page));
        temp->prev = NULL;
        temp->next = NULL;
        temp->name = cnt++;
        if (start == NULL)
        {
            start = temp;
            q = temp;
        }
        else
        {
            temp->prev = q;
            q->next = temp;
            q = q->next;
        }
    }
    int choice;
    while (1)
    {
        printf("Select one option :\n1.Go Back\n2.Move next\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (q->prev)
            {
                q = q->prev;
                printf("Page %d\n", q->name);
                break;
            }
        case 2:
            if (q->next)
            {
                q = q->next;
                printf("Page %d\n", q->name);
                break;
            }
        default:
            printf("Sorry can't move.\nEither you are in first page or last page\n");
        }
    }
    return 0;
}
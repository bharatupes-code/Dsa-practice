#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, i, count = 0;
    scanf("%d", &n);

    struct node *head = NULL, *temp, *newnode;

    // Create linked list
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Traverse + Count + Print
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        count++;
        temp = temp->next;
    }

    // Print count
    printf("\n%d", count);

    return 0;
}
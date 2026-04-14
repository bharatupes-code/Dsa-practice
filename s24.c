#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insert(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

// Delete from beginning
void delete()
{
    if (head == NULL)
    {
        printf("List empty\n");
        return;
    }
    struct Node *temp = head;
    printf("Deleted: %d\n", head->data);
    head = head->next;
    free(temp);
}

// Traverse
void display()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int ch, x;

    while (1)
    {
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &x);
            insert(x);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        }
    }
}
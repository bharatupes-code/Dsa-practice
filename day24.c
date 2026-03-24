#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Create linked list
struct node *create(int n)
{
    struct node *head = NULL, *temp, *newnode;

    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

// Delete first occurrence
struct node *deleteKey(struct node *head, int key)
{
    struct node *temp = head, *prev = NULL;

    // If head itself has the key
    if (temp != NULL && temp->data == key)
    {
        head = temp->next;
        free(temp);
        return head;
    }

    // Search for key
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key found
    if (temp != NULL)
    {
        prev->next = temp->next;
        free(temp);
    }

    return head;
}

// Print list
void print(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n, key;

    scanf("%d", &n);
    struct node *head = create(n);

    scanf("%d", &key);

    head = deleteKey(head, key);

    print(head);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void delete_end()
{
    if (head == NULL)
    {
        printf("List empty\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

void display()
{
    struct Node *temp = head;
    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    display();
    delete_end();
    display();
}
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Front and Rear pointers
struct Node *front = NULL, *rear = NULL;

// Enqueue (insert)
void enqueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    { // empty queue
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

// Dequeue (delete)
void dequeue()
{
    if (front == NULL)
    {
        printf("-1\n");
        return;
    }

    struct Node *temp = front;
    printf("%d\n", temp->data);

    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    free(temp);
}

// Main function
int main()
{
    int n, value;
    char operation[10];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", operation);

        if (operation[0] == 'e')
        { // enqueue
            scanf("%d", &value);
            enqueue(value);
        }
        else if (operation[0] == 'd')
        { // dequeue
            dequeue();
        }
    }

    return 0;
}
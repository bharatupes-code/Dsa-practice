#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;
int stack[MAX], top = -1;

// Queue functions
void enqueue(int x)
{
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue()
{
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// Stack functions
void push(int x)
{
    if (top == MAX - 1)
        return;
    stack[++top] = x;
}

int pop()
{
    if (top == -1)
        return -1;
    return stack[top--];
}

int main()
{
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Queue → Stack
    while (front <= rear)
    {
        push(dequeue());
    }

    // Reset queue
    front = 0;
    rear = -1;

    // Step 2: Stack → Queue
    while (top != -1)
    {
        enqueue(pop());
    }

    // Print reversed queue
    printf("Reversed queue: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}
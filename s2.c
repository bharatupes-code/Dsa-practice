#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue Full\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = x;
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue Empty\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display()
{
    int i = front;
    if (front == -1)
        return;

    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    enqueue(4);

    display();
    return 0;
}
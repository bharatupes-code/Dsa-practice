#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isEmpty()
{
    return (front == -1);
}

int isFull()
{
    return (rear == MAX - 1);
}

void enqueue(int x)
{
    if (isFull())
    {
        printf("Queue is Full\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = x;
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Deleted: %d\n", queue[front]);
    front++;
    if (front > rear)
        front = rear = -1;
}

int getFront()
{
    if (isEmpty())
        return -1;
    return queue[front];
}

int getRear()
{
    if (isEmpty())
        return -1;
    return queue[rear];
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Front = %d\n", getFront());
    printf("Rear = %d\n", getRear());

    dequeue();
    printf("Front after delete = %d\n", getFront());

    return 0;
}
#include <stdio.h>
#define MAX 10

int arr[MAX];
int front1 = 0, rear1 = -1;
int front2 = MAX - 1, rear2 = MAX;

void enqueue1(int x)
{
    if (rear1 + 1 == rear2)
    {
        printf("Overflow\n");
        return;
    }
    arr[++rear1] = x;
}

void enqueue2(int x)
{
    if (rear2 - 1 == rear1)
    {
        printf("Overflow\n");
        return;
    }
    arr[--rear2] = x;
}

void display()
{
    int i;
    printf("Queue1: ");
    for (i = front1; i <= rear1; i++)
        printf("%d ", arr[i]);

    printf("\nQueue2: ");
    for (i = MAX - 1; i >= rear2; i--)
        printf("%d ", arr[i]);
}

int main()
{
    enqueue1(1);
    enqueue1(2);

    enqueue2(100);
    enqueue2(200);

    display();
    return 0;
}
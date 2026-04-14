#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void addJob(int x)
{
    if (rear == MAX - 1)
    {
        printf("Printer Queue Full\n");
        return;
    }
    if (front == -1)
        front = 0;

    queue[++rear] = x;
    printf("Job %d added\n", x);
}

void printJob()
{
    if (front == -1)
    {
        printf("No jobs\n");
        return;
    }

    printf("Printing job %d\n", queue[front]);
    front++;

    if (front > rear)
        front = rear = -1;
}

int main()
{
    addJob(101);
    addJob(102);
    addJob(103);

    printJob();
    printJob();

    return 0;
}
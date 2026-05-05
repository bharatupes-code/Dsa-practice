#include <stdio.h>
#define MAX 10
int adj[MAX][MAX], visited[MAX], queue[MAX];
int front = -1, rear = -1;
void enqueue(int v)
{
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}
int dequeue()
{
    return queue[front++];
}
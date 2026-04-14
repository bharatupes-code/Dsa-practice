#include <stdio.h>
#define MAX 10

int arr[MAX];
int top1 = -1, top2 = MAX;

void push1(int x)
{
    if (top1 + 1 == top2)
    {
        printf("Overflow\n");
        return;
    }
    arr[++top1] = x;
}

void push2(int x)
{
    if (top1 + 1 == top2)
    {
        printf("Overflow\n");
        return;
    }
    arr[--top2] = x;
}

void display()
{
    printf("Stack1: ");
    for (int i = 0; i <= top1; i++)
        printf("%d ", arr[i]);

    printf("\nStack2: ");
    for (int i = MAX - 1; i >= top2; i--)
        printf("%d ", arr[i]);
}

int main()
{
    push1(10);
    push1(20);
    push2(30);
    push2(40);
    display();
}
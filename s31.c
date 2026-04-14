#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push()
{
    int x;
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &x);
    stack[++top] = x;
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped: %d\n", stack[top--]);
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main()
{
    int ch;
    while (1)
    {
        printf("\n1.Push 2.Pop 3.Display 4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        }
    }
}
#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char x) { stack[++top] = x; }
char pop() { return stack[top--]; }

int main()
{
    char exp[100];
    printf("Enter expression: ");
    scanf("%s", exp);

    for (int i = 0; exp[i]; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else
        {
            if (top == -1)
            {
                printf("Not Balanced\n");
                return 0;
            }
            char c = pop();
        }
    }

    if (top == -1)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
}
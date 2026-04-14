#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }

int main()
{
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);

    for (int i = 0; str[i]; i++)
        push(str[i]);

    for (int i = 0; str[i]; i++)
        str[i] = pop();

    printf("Reversed: %s", str);
}
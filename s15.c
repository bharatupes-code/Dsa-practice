#include <stdio.h>

int main()
{
    char *cities[5] = {"Delhi", "Mumbai", "Chennai", "Kolkata", "Dehradun"};

    printf("Cities:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", cities[i]);
    }
}
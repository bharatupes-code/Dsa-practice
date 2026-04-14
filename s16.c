#include <stdio.h>

int main()
{
    int a[3][3];
    int (*p)[3] = a;

    printf("Enter 3x3 matrix:\n");

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &p[i][j]);

    printf("\nMatrix:\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", p[i][j]);
        printf("\n");
    }
}
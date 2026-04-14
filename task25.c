#include <stdio.h>

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5, i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

        printf("Pass %d: ", i + 1);
        for (j = 0; j < n; j++)
            printf("%d ", arr[j]);
        printf("\n");
    }

    return 0;
}
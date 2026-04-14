#include <stdio.h>

int main()
{
    int arr[] = {8, 3, 5, 2, 6};
    int n = 5, i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

        printf("Pass %d: ", i);
        for (j = 0; j < n; j++)
            printf("%d ", arr[j]);
        printf("\n");
    }

    return 0;
}
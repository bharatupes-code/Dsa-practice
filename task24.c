#include <stdio.h>

int main()
{
    int arr[] = {5, 8, 3, 2, 9, 4};
    int n = 6, i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] % 2 == 0 && arr[j + 1] % 2 == 0)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    printf("Result: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
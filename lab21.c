#include <stdio.h>
int main()
{
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j, temp, swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = 0; // optimization flag

        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // stop if already sorted
        if (swapped == 0)
            break;
    }
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
#include <stdio.h>

int main()
{
    int arr[100], n, key, i, count = 0, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        count++; // count comparison

        if (arr[i] == key)
        {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Element not found\n");
    }

    printf("Total comparisons = %d\n", count);

    return 0;
}
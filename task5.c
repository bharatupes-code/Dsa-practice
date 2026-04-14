#include <stdio.h>

int main()
{
    int arr[100], n, i, key;

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

    while (1)
    {
        printf("Enter element to search (-1 to exit): ");
        scanf("%d", &key);

        if (key == -1)
            break;

        int found = 0;

        for (i = 0; i < n; i++)
        {
            if (arr[i] == key)
            {
                printf("Found at position %d\n", i + 1);
                found = 1;
                break;
            }
        }

        if (!found)
            printf("Not found\n");
    }

    return 0;
}
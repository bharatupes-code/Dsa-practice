#include <stdio.h>
int main()
{
    int arr[100], n, i, key, found = 0;
    printf("Enter number of elements:");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int count = 0;
    printf("Enter element to search:");
    scanf("%d", &key);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            count++;
            break;
        }
        count++;
    }

    printf("Number of comparison :%d", count);
    if (!found)
    {
        printf("Element not found\n");
    }
    return 0;
}
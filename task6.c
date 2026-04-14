#include <stdio.h>

int firstOccurrence(int arr[], int n, int key)
{
    int low = 0, high = n - 1, res = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            res = mid;
            high = mid - 1; // go left
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return res;
}

int lastOccurrence(int arr[], int n, int key)
{
    int low = 0, high = n - 1, res = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            res = mid;
            low = mid + 1; // go right
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return res;
}

int main()
{
    int arr[] = {1, 2, 2, 2, 3, 4};
    int n = 6, key = 2;

    printf("First = %d\n", firstOccurrence(arr, n, key) + 1);
    printf("Last = %d\n", lastOccurrence(arr, n, key) + 1);

    return 0;
}
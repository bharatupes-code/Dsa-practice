#include <stdio.h>
#include <time.h>

// Linear Search
int linearSearch(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[100000], n = 10000, i, key = 999;

    // Fill array (sorted)
    for (i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    clock_t start, end;

    // Linear Search Time
    start = clock();
    linearSearch(arr, n, key);
    end = clock();
    double linearTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Binary Search Time
    start = clock();
    binarySearch(arr, n, key);
    end = clock();
    double binaryTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Linear Search Time = %lf seconds\n", linearTime);
    printf("Binary Search Time = %lf seconds\n", binaryTime);

    return 0;
}
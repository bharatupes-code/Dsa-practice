#include <stdio.h>

// Function to find maximum element
int findMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Counting Sort function
void countingSort(int arr[], int n)
{
    int max = findMax(arr, n);

    int count[max + 1];
    int output[n];

    // Initialize count array
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    // Step 1: Store frequency
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Step 2: Prefix sum (cumulative count)
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Step 3: Build output array (reverse for stability)
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 4: Copy back to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Function to print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

// Main function
int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter non-negative elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    countingSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
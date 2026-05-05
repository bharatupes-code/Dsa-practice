#include <stdio.h>
#include <stdlib.h>

// Structure to store value and original index
struct Node
{
    int val;
    int index;
};

// Merge function
void merge(struct Node arr[], int left, int mid, int right, int count[])
{
    int n = right - left + 1;
    struct Node temp[n];

    int i = left, j = mid + 1, k = 0;
    int rightCount = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i].val <= arr[j].val)
        {
            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
        else
        {
            rightCount++; // one smaller element from right side
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        count[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    // Copy back
    for (i = 0; i < k; i++)
    {
        arr[left + i] = temp[i];
    }
}

// Merge sort
void mergeSort(struct Node arr[], int left, int right, int count[])
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);

    merge(arr, left, mid, right, count);
}

// Main function
int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    struct Node nodes[n];
    int count[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        nodes[i].val = arr[i];
        nodes[i].index = i;
        count[i] = 0;
    }

    mergeSort(nodes, 0, n - 1, count);

    printf("Count of smaller elements on right:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", count[i]);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Structure for interval
struct Interval
{
    int start, end;
};

// Comparator for sorting by start time
int compare(const void *a, const void *b)
{
    struct Interval *i1 = (struct Interval *)a;
    struct Interval *i2 = (struct Interval *)b;
    return i1->start - i2->start;
}

// Function to merge intervals
void mergeIntervals(struct Interval arr[], int n)
{
    if (n <= 0)
        return;

    // Step 1: Sort intervals
    qsort(arr, n, sizeof(struct Interval), compare);

    struct Interval result[n];
    int index = 0;

    // Add first interval
    result[index] = arr[0];

    // Step 2: Merge
    for (int i = 1; i < n; i++)
    {
        // If overlapping
        if (arr[i].start <= result[index].end)
        {
            // Merge intervals
            if (arr[i].end > result[index].end)
                result[index].end = arr[i].end;
        }
        else
        {
            // No overlap → new interval
            index++;
            result[index] = arr[i];
        }
    }

    // Print merged intervals
    printf("Merged intervals:\n");
    for (int i = 0; i <= index; i++)
    {
        printf("[%d, %d] ", result[i].start, result[i].end);
    }
}

// Main function
int main()
{
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    struct Interval arr[n];

    printf("Enter intervals (start end):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    mergeIntervals(arr, n);

    return 0;
}
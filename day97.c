#include <stdio.h>
#include <stdlib.h>

// Structure for meeting
struct Meeting
{
    int start, end;
};

// Swap function
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Min-heapify
void heapify(int heap[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

// Insert into min-heap
void insertHeap(int heap[], int *size, int value)
{
    int i = (*size)++;
    heap[i] = value;

    // Fix upward
    while (i != 0 && heap[(i - 1) / 2] > heap[i])
    {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Extract min (root)
int extractMin(int heap[], int *size)
{
    int root = heap[0];
    heap[0] = heap[--(*size)];
    heapify(heap, *size, 0);
    return root;
}

// Comparator for sorting by start time
int compare(const void *a, const void *b)
{
    struct Meeting *m1 = (struct Meeting *)a;
    struct Meeting *m2 = (struct Meeting *)b;
    return m1->start - m2->start;
}

// Function to find minimum rooms
int minMeetingRooms(struct Meeting arr[], int n)
{
    // Step 1: Sort by start time
    qsort(arr, n, sizeof(struct Meeting), compare);

    int heap[n]; // min-heap of end times
    int size = 0;

    // Add first meeting end time
    insertHeap(heap, &size, arr[0].end);

    // Process remaining meetings
    for (int i = 1; i < n; i++)
    {
        // If room is free, reuse it
        if (arr[i].start >= heap[0])
        {
            extractMin(heap, &size);
        }
        // Allocate room (insert end time)
        insertHeap(heap, &size, arr[i].end);
    }

    return size; // number of rooms required
}

// Main function
int main()
{
    int n;
    printf("Enter number of meetings: ");
    scanf("%d", &n);

    struct Meeting arr[n];

    printf("Enter start and end times:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    int result = minMeetingRooms(arr, n);
    printf("Minimum number of rooms required: %d\n", result);

    return 0;
}
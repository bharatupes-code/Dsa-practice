#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list (bucket)
struct Node
{
    float data;
    struct Node *next;
};

// Insert node in sorted order (Insertion sort in bucket)
struct Node *insertSorted(struct Node *head, float value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // Insert at beginning or empty list
    if (head == NULL || value < head->data)
    {
        newNode->next = head;
        return newNode;
    }

    // Traverse and insert
    struct Node *temp = head;
    while (temp->next != NULL && temp->next->data <= value)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Bucket Sort function
void bucketSort(float arr[], int n)
{
    // Create n empty buckets
    struct Node *buckets[n];

    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    // Step 1: Distribute elements into buckets
    for (int i = 0; i < n; i++)
    {
        int index = n * arr[i]; // bucket index
        buckets[index] = insertSorted(buckets[index], arr[i]);
    }

    // Step 2: Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        struct Node *temp = buckets[i];
        while (temp != NULL)
        {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

// Print array
void printArray(float arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
}

// Main function
int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];

    printf("Enter elements (range [0,1)):\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
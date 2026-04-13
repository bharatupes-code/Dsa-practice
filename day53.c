#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Queue node (for BFS)
struct QNode
{
    struct Node *node;
    int hd;
};

// Create new node
struct Node *newNode(int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order
struct Node *buildTree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node **queue = (struct Node **)malloc(n * sizeof(struct Node *));
    int front = 0, rear = 0;

    struct Node *root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n)
    {
        struct Node *curr = queue[front++];

        if (arr[i] != -1)
        {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1)
        {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node *root, int n)
{
    if (!root)
        return;

    // Array of lists (HD range: -n to +n)
    int size = 2 * n + 1;
    int offset = n;

    int **result = (int **)malloc(size * sizeof(int *));
    int *count = (int *)calloc(size, sizeof(int));

    for (int i = 0; i < size; i++)
        result[i] = (int *)malloc(n * sizeof(int));

    // Queue for BFS
    struct QNode *queue = (struct QNode *)malloc(n * sizeof(struct QNode));
    int front = 0, rear = 0;

    queue[rear++] = (struct QNode){root, 0};

    int minHD = 0, maxHD = 0;

    while (front < rear)
    {
        struct QNode curr = queue[front++];
        struct Node *node = curr.node;
        int hd = curr.hd;

        int index = hd + offset;
        result[index][count[index]++] = node->data;

        if (hd < minHD)
            minHD = hd;
        if (hd > maxHD)
            maxHD = hd;

        if (node->left)
            queue[rear++] = (struct QNode){node->left, hd - 1};

        if (node->right)
            queue[rear++] = (struct QNode){node->right, hd + 1};
    }

    // Print vertical order
    for (int i = minHD; i <= maxHD; i++)
    {
        int index = i + offset;
        for (int j = 0; j < count[index]; j++)
        {
            printf("%d ", result[index][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node *root = buildTree(arr, n);

    verticalOrder(root, n);

    return 0;
}
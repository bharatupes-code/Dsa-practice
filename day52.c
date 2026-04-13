#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node
{
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node *newNode(int val)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
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

        // Left child
        if (arr[i] != -1)
        {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1)
        {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Find LCA in Binary Tree
struct Node *findLCA(struct Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    // If either node matches
    if (root->data == n1 || root->data == n2)
        return root;

    struct Node *left = findLCA(root->left, n1, n2);
    struct Node *right = findLCA(root->right, n1, n2);

    // If both sides return non-null → LCA
    if (left && right)
        return root;

    // Otherwise return non-null
    return (left != NULL) ? left : right;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    struct Node *root = buildTree(arr, n);

    struct Node *lca = findLCA(root, n1, n2);

    if (lca)
        printf("%d\n", lca->data);
    else
        printf("LCA not found\n");

    return 0;
}
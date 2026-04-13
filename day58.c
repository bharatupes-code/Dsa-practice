#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node *newNode(int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Find index in inorder
int search(int inorder[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
struct Node *buildTree(int preorder[], int inorder[], int start, int end, int *preIndex)
{
    if (start > end)
        return NULL;

    // Pick current node from preorder
    int curr = preorder[*preIndex];
    (*preIndex)++;

    struct Node *root = newNode(curr);

    // If leaf node
    if (start == end)
        return root;

    // Find index in inorder
    int inIndex = search(inorder, start, end, curr);

    // Build left and right subtree
    root->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

// Postorder traversal
void postorder(struct Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct Node *root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    // Print postorder
    postorder(root);

    return 0;
}
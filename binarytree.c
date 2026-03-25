#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create(); // function declaration

int main()
{
    struct node *root;
    root = 0;
    root = create();
}

struct node *create()
{
    int x;
    struct node *newnode;

    printf("Enter data: ");
    scanf("%d", &x);

    if (x == -1)
    {
        return 0;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;

    printf("Enter left child of %d: ", x);
    newnode->left = create();

    printf("Enter right child of %d: ", x);
    newnode->right = create(); // ✅ fixed

    return newnode;
}
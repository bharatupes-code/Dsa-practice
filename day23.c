#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Create list
struct node *create(int n)
{
    struct node *head = NULL, *temp, *newnode;

    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

// Merge two sorted lists
struct node *merge(struct node *l1, struct node *l2)
{
    struct node *result = NULL, *temp;

    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    // Set first node
    if (l1->data < l2->data)
    {
        result = temp = l1;
        l1 = l1->next;
    }
    else
    {
        result = temp = l2;
        l2 = l2->next;
    }

    // Merge
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data < l2->data)
        {
            temp->next = l1;
            l1 = l1->next;
        }
        else
        {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }

        if (l1 != NULL)
        temp->next = l1;
    if (l2 != NULL)
        temp->next = l2;

    return result;
}

// Print list
void print(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n, m;

    scanf("%d", &n);
    struct node *l1 = create(n);

    scanf("%d", &m);
    struct node *l2 = create(m);

    struct node *merged = merge(l1, l2);

    print(merged);

    return 0;
}
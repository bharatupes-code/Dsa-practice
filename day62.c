#include <stdio.h>
#include <stdlib.h>

// Node for linked list
struct Node
{
    int vertex;
    struct Node *next;
};

// Create new node
struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Array of linked lists
    struct Node *adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int u, v;
    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);

        // Add edge u → v (directed)
        struct Node *newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // For undirected graph, uncomment below:
        // struct Node* newNode2 = createNode(u);
        // newNode2->next = adj[v];
        // adj[v] = newNode2;
    }

    // Print adjacency list
    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d -> ", i);
        struct Node *temp = adj[i];
        while (temp)
        {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}
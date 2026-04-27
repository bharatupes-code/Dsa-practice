#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int n;

// Function for Topological Sort using Kahn's Algorithm
void topologicalSort()
{
    int front = 0, rear = 0;

    // Add all vertices with indegree 0 to queue
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            queue[rear++] = i;
        }
    }

    printf("Topological Order: ");

    while (front < rear)
    {
        int u = queue[front++];
        printf("%d ", u);

        // Reduce indegree of adjacent vertices
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] == 1)
            {
                indegree[v]--;

                if (indegree[v] == 0)
                {
                    queue[rear++] = v;
                }
            }
        }
    }
}

// Main function
int main()
{
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph and indegree
    for (int i = 0; i < n; i++)
    {
        indegree[i] = 0;
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        indegree[v]++; // increase indegree
    }

    topologicalSort();

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

// DFS function to detect cycle
int dfs(int node, int parent)
{
    visited[node] = 1;

    for (int i = 0; i < n; i++)
    {
        if (adj[node][i])
        {
            if (!visited[i])
            {
                if (dfs(i, node))
                    return 1;
            }
            else if (i != parent)
            {
                return 1; // cycle found
            }
        }
    }
    return 0;
}

// Function to check cycle in graph
int hasCycle()
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1))
                return 1;
        }
    }
    return 0;
}

int main()
{
    int edges, u, v;

    // Input number of vertices and edges
    scanf("%d %d", &n, &edges);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    // Check cycle
    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
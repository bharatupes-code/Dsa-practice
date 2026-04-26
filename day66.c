#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int n;

// DFS function to detect cycle
int dfs(int node)
{
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < n; i++)
    {
        if (adj[node][i])
        {
            if (!visited[i])
            {
                if (dfs(i))
                    return 1;
            }
            else if (recStack[i])
            {
                return 1; // cycle found
            }
        }
    }

    recStack[node] = 0; // remove from recursion stack
    return 0;
}

// Function to check cycle
int hasCycle()
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i))
                return 1;
        }
    }
    return 0;
}

int main()
{
    int edges, u, v;

    // Input vertices and edges
    scanf("%d %d", &n, &edges);

    // Initialize
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        recStack[i] = 0;
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    // Input directed edges
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // directed graph
    }

    // Check cycle
    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
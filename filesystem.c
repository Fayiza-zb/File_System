#include <stdio.h>
#include <string.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
char name[MAX][30];
int n;

// BFS traversal
void BFS(int start, char target[])
{
    int queue[MAX], front = 0, rear = 0;
    int found = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS Traversal: ");

    while (front < rear)
    {
        int v = queue[front++];

        printf("%s ", name[v]);

        if (strcmp(name[v], target) == 0)
            found = 1;

        for (int i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    if (found)
        printf("\nFile found using BFS.");
    else
        printf("\nFile not found using BFS.");
}

// DFS traversal
void DFS(int v, char target[], int *found)
{
    visited[v] = 1;

    printf("%s ", name[v]);

    if (strcmp(name[v], target) == 0)
        *found = 1;

    for (int i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
            DFS(i, target, found);
    }
}

int main()
{
    int edges, u, v, start;
    char target[30];

    printf("Enter number of files/directories: ");
    scanf("%d", &n);

    printf("\nEnter names of files/directories:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Node %d: ", i);
        scanf("%29s", name[i]);
    }

    printf("\nEnter number of connections: ");
    scanf("%d", &edges);

    printf("\nEnter connections (parent child indices):\n");

    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    printf("\nEnter starting node index: ");
    scanf("%d", &start);

    printf("Enter file name to search: ");
    scanf("%29s", target);

    BFS(start, target);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int found = 0;

    printf("\n\nDFS Traversal: ");
    DFS(start, target, &found);

    if (found)
        printf("\nFile found using DFS.");
    else
        printf("\nFile not found using DFS.");

    return 0;
}
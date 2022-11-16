#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int adj[MAX][MAX]; // Adjacency Matrix
int n;             // number of nodes

// 1 if there is an edge and 0 if there is no edge

int main(int argc, char const *argv[])
{
    int type, maxEdges;
    printf("Enter the number of edges: ");
    scanf("%d", &n);
    printf("Enter 1 for Undirected graph and 2 for directed graph: ");
    scanf("%d", &type);
    if (type == 1)
        maxEdges = (n * (n - 1)) / 2;
    else
        maxEdges = n * (n - 1);
    int origin, destination;
    for (int i = 1; i <= maxEdges; i++)
    {
        printf("Enter edge %d space separated: (-1 -1 to quit) ", i);
        scanf("%d %d", &origin, &destination);
        if (origin == -1 && destination == -1)
            break;
        if (origin >= n || destination >= n || origin < 0 || destination < 0)
        {
            printf("Invalid\n");
            i--;
        }
        else
        {
            adj[origin][destination] = 1;
            if (type == 1)
                adj[destination][origin] = 1;
        }
    }
    printf("Adjacency matrix is\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d", adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}

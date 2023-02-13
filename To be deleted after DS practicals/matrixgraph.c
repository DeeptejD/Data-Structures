// code for insertion and deleton od edges in directed as well as undirected graph as well as creating of a graph using adjacency matrix
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int adj[MAX][MAX];
int n, choice; // number of vertices

void create()
{
    int orig, dest, maxedges;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the type of graph\n1. Undirected\n2. Directed\n");
    scanf("%d", &choice);
    if (choice == 1)
        maxedges = n * (n - 1) / 2;
    else
        maxedges = n * (n - 1);
    for (int i = 1; i <= maxedges; i++)
    {
        printf("Enter origin and destination\n-1 -1 to quit\n");
        printf("Origin: ");
        scanf("%d", &orig);
        printf("Destination: ");
        scanf("%d", &dest);
        if (orig == -1 && dest == -1)
            return;
        else if (orig < 0 || dest < 0 || orig > n || dest > n)
        {
            printf("Invalid vertex\n");
            i--;
        }
        else
        {
            adj[orig][dest] = 1;
            if (choice == 1)
                adj[dest][orig] = 1;
        }
    }
    return;
}

void display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d", adj[i][j]);
        }
        printf("\n");
    }
}

void insertedge()
{
    int orig, dest;
    printf("Enter origin: ");
    scanf("%d", &orig);
    printf("Enter dest: ");
    scanf("%d", &dest);
    if (orig > n || orig < 0 || dest > n || dest < 0)
    {
        printf("Invalid vertex\n");
        return;
    }
    adj[orig][dest] = 1;
    if (choice == 1)
        adj[dest][orig] = 1;
}

void deledge()
{
    int orig, dest;
    printf("Enter origin: ");
    scanf("%d", &orig);
    printf("Enter dest: ");
    scanf("%d", &dest);
    if (orig > n || orig < 0 || dest > n || dest < 0)
    {
        printf("Invalid vertex\n");
        return;
    }
    adj[orig][dest] = 0;
    if (choice == 1)
        adj[dest][orig] = 0;
}

int main(int argc, char const *argv[])
{
    create();
    insertedge();
    insertedge();
    display();
    deledge();
    deledge();
    display();
    return 0;
}

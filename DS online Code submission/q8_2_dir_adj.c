// undirected graph using adjacency matrix

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int adj[MAX][MAX], state[MAX];
int n;
#define init 1
#define waiting 2
#define visited 3

void display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%3d", adj[i][j]);
        printf("\n");
    }
    printf("\n");
}

void create(int n)
{
    int orig, dest, maxedges = n * (n - 1);
    for (int i = 1; i <= maxedges; i++)
    {
        printf("Enter edge %d (-1, -1) to quit: ", i);
        scanf("%d%d", &orig, &dest);
        if (orig == -1 && dest == -1)
            return;
        if (orig < 0 || dest < 0 || orig >= n || dest >= n)
        {
            printf("Invalid vertex!\n");
            i--;
        }
        else
            adj[orig][dest] = 1;
    }
    display();
}

void insert_edge(int orig, int dest)
{
    if (orig < 0 || orig >= n)
    {
        printf("Origin vertex invalid!\n");
        return;
    }
    if (dest < 0 || dest >= n)
    {
        printf("Dest vertex invalid!\n");
        return;
    }
    adj[orig][dest] = 1;
    printf("Edge added from %d to %d\n", orig, dest);
}

void del_edge(int orig, int dest)
{
    if (orig < 0 || dest < 0 || orig >= n || dest >= n || adj[orig][dest] == 0)
    {
        printf("Edge doees not exist!\n");
        return;
    }
    adj[orig][dest] = 0;
}

int queue[MAX], front = -1, rear = -1;
void insert(int item)
{
    if (rear == MAX - 1)
        printf("Q overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        queue[++rear] = item;
    }
}

int delete()
{
    int item;
    if (front == -1 || front == rear + 1)
    {
        printf("Q underflow\n");
        return -99999;
    }
    else
    {
        item = queue[front++];
        return item;
    }
}

int isempty()
{
    return (front == -1 || front > rear);
}

// BFS IS HERE

void BFT()
{
    int v;
    for (v = 0; v < n; v++)
        state[v] = init;
    printf("Enter starting vertex: ");
    scanf("%d", &v);
    BFS(v);
}

void BFS(int v)
{
    int i;
    insert(v);
    state[v] = waiting;
    while (!isempty())
    {
        v = delete ();
        printf("%3d", v);
        state[v] = visited;
        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && state[i] == init)
            {
                insert(i), state[i] = waiting;
            }
        }
    }
    printf("\n");
}

#define dfs_init 1
#define dfs_vis 2
int stack[MAX], top = -1;

int stackempty()
{
    return top == -1;
}

void push(int item)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
    }
    else
        stack[++top] = item;
    return;
}

int pop()
{
    int item;
    if (top == -1)
    {
        printf("Stack underflow\n");
        return -999999;
    }
    else
    {
        item = stack[top--];
        return item;
    }
}

void DFT()
{
    int v;
    for (v = 0; v < n; v++)
        state[v] = init;
    printf("Enter starting vertex: ");
    scanf("%d", &v);
    DFS(v);
}

void DFS(int v)
{
    int i;
    push(v);
    while (!stackempty())
    {
        v = pop();
        if (state[v] == dfs_init)
        {
            printf("%3d", v);
            state[v] = dfs_vis;
        }
        for (i = n - 1; i >= 0; i--)
        {
            if (adj[v][i] == 1 && state[i] == dfs_init)
                push(i);
        }
    }
}

int main(int argc, char const *argv[])
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    create(n);
    while (1)
    {
        printf("Enter choice\n1. Insert Edge\n2. Delete Edge\n3. Display\n4. BFS\n5. DFS\n6. Exit\n");
        int choice, orig, dest;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter first node: ");
            scanf("%d", &orig);
            printf("Enter second node: ");
            scanf("%d", &dest);
            insert_edge(orig, dest);
            break;
        case 2:
            printf("Enter first node: ");
            scanf("%d", &orig);
            printf("Enter second node: ");
            scanf("%d", &dest);
            del_edge(orig, dest);
            break;
        case 3:
            display();
            break;
        case 4:
            BFT();
            break;
        case 5:
            DFT();
            break;
        }
    }

    return 0;
}

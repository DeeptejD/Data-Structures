#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int n, choice;
// number of vertices

void create()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int choice;
    printf("Enter\n1. Undirected graph\n2. Directed Graph\n");
    scanf("%d", &choice);
    int maxedges;
    if (choice == 1)
        maxedges = n * (n - 1) / 2;
    else
        maxedges = n * (n - 1);
    int orig, dest;
    printf("Enter orig and dest, -1 -1 to exit\n");
    for (int i = 1; i <= maxedges; i++)
    {
        printf("Enter Orig: ");
        scanf("%d", &orig);
        printf("Enter dest: ");
        scanf("%d", &dest);
        if (orig == -1 && dest == -1)
        {
            break;
        }
        else if (orig > n || dest > n || orig < 0 || dest < 0)
        {
            printf("Invalid orig or destination\n");
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
    return;
}

void insertedge()
{
    int orig, dest;
    printf("Enter orig and destination: ");
    scanf("%d %d", &orig, &dest);
    if (orig > n || dest > n || orig < 0 || dest < 0)
    {
        printf("Inavlid Origin or Destination!\n");
        return;
    }
    adj[orig][dest] = 1;
    if (choice == 1)
        adj[dest][orig] = 1;
}

void deledge()
{
    int orig, dest;
    printf("Enter orig and destination: ");
    scanf("%d %d", &orig, &dest);
    if (orig > n || dest > n || orig < 0 || dest < 0)
    {
        printf("Inavlid Origin or Destination!\n");
        return;
    }
    adj[orig][dest] = 0;
    if (choice == 1)
        adj[dest][orig] = 0;
}

int queue[MAX];
int front = -1, rear = -1;

int qisempty()
{
    return (front == -1 || front == rear + 1);
}

int qisfull()
{
    return (rear == MAX - 1);
}

void insert(int u)
{
    if (rear == MAX - 1)
    {
        printf("Q overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = u;
    return;
}

int delete()
{
    if (front == -1 || front == rear + 1)
    {
        printf("Q underflow\n");
        return;
    }
    return queue[front++];
}

int state[MAX];

#define intial 0
#define waiting 1
#define visited 2

void BFT()
{
    int v;
    for (int i = 0; i < n; i++)
        state[i] = intial;
    printf("Enter the starting vertex: ");
    scanf("%d", &v);
    BFS(v);
}

void BFS(int v)
{
    insert(v);
    state[v] = waiting;
    while (!qisempty())
    {
        v = delete ();
        printf("%d ", v);
        state[v] = visited;
        for (int i = 0; i < n; i++)
        {
            if (state[i] == intial && adj[v][i] == 1)
            {
                insert(i);
                state[i] = waiting;
            }
        }
    }
}

int stack[MAX];
int top = -1;

int stackfull()
{
    return (top == MAX - 1);
}

int stackempty()
{
    return top == -1;
}

void push(int v)
{
    if (stackfull())
    {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = v;
}

int pop()
{
    if (stackempty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// DFS
void DFT()
{
    int v;
    for (int i = 0; i < n; i++)
        state[i] = intial;
    printf("Enter the starting vertex: ");
    scanf("%d", &v);
    DFS(v);
}

void DFS(int v)
{
    push(v);
    while (!stackempty())
    {
        v = pop();
        if (state[v] == intial)
        {
            state[v] = visited;
            printf("%d ", v);
            for (int i = n - 1; i >= 0; i--)
            {
                if (state[i] == intial && adj[v][i] == 1)
                {
                    push(i);
                }
            }
        }
    }
}

#define finished 5
// recursive dfs
void recDFT()
{
    int v;
    for (int i = 0; i < n; i++)
        state[i] = 0;
    printf("Enter the starting vertex: ");
    scanf("%d", &v);
    recDFS(v);
    for (int i = 0; i < n; i++)
    {
        if (state[i] == intial)
            recDFS(i);
    }
}

void recDFS(int v)
{
    printf("%d", v);
    state[v] = visited;
    for (int i = 0; i < n; i++)
    {
        if (state[i] == intial && adj[v][i] == 1)
        {
            recDFS(i);
        }
    }
    state[v] = finished;
}

int main(int argc, char const *argv[])
{
    create();
    display();
    BFT();
    printf("\n");
    DFT();
    printf("\n");
    recDFT();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int n = 7; // no of vertices global

struct edge;

struct vertex
{
    int info;
    struct edge *firstedge;
    struct vertex *nextvertex;
};

struct edge
{
    struct vertex *destvertex;
    struct edge *nextedge;
};

struct vertex *start = NULL;

void addvertex(int v)
{
    struct vertex *temp = (struct vertex *)malloc(sizeof(struct vertex));
    temp->info = v;
    temp->nextvertex = NULL;
    temp->firstedge = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        struct vertex *ptr = start;
        while (ptr->nextvertex != NULL)
            ptr = ptr->nextvertex;
        ptr->nextvertex = temp;
    }
    n++; // DONT FORGET TO INCREASE THE TOTAL NUMBER OF VERTICES
}

struct vertex *findvertex(int v)
{
    struct vertex *ptr = start;
    while (ptr != NULL)
    {
        if (ptr->info == v)
            return ptr;
        ptr = ptr->nextvertex;
    }
    printf("Vertex not found\nReturning NULL instead\n");
    return NULL;
}

void addedge(int u, int v)
{
    // main idea: we use the finnd vertex functions to fid the orig and dest and the rest is pretty self explanatory
    struct vertex *orig = findvertex(u), *dest = findvertex(v);
    if (orig == NULL)
    {
        printf("Invalid orig\n");
        return;
    }
    if (dest == NULL)
    {
        printf("Invalid dest\n");
        return;
    }
    struct edge *ed = (struct edge *)malloc(sizeof(struct edge));
    ed->destvertex = dest, ed->nextedge = NULL;
    if (orig->firstedge == NULL)
    {
        orig->firstedge = ed;
    }
    else
    {
        struct edge *temped = orig->firstedge;
        while (temped->nextedge != NULL)
            temped = temped->nextedge;
        temped->nextedge = ed;
    }
    return;
}

void deleteIncomingEdges(int u)
{
    struct vertex *ptr = start;
    while (ptr != NULL)
    {
        if (ptr->firstedge == NULL)
        {
            ptr = ptr->nextvertex;
            continue;
        }
        if (ptr->firstedge->destvertex->info == u)
        {
            struct edge *temp = ptr->firstedge;
            ptr->firstedge = ptr->firstedge->nextedge;
            free(temp);
            continue;
        }
        struct edge *p = ptr->firstedge;
        while (p->nextedge != NULL)
        {
            if (p->nextedge->destvertex->info == u)
            {
                struct edge *temp = p->nextedge;
                p->nextedge = temp->nextedge;
                free(temp);
                continue;
            }
            p = p->nextedge;
        }
        ptr = ptr->nextvertex;
    }
}

void deletevertex(int v)
{
    struct vertex *temp;
    if (start == NULL)
    {
        printf("No vertices to be deleted\n");
        return;
    }
    if (start->info == v)
    {
        temp = start;
        start = start->nextvertex;
    }
    else
    {
        struct vertex *ptr = start;
        while (ptr->nextvertex != NULL)
        {
            if (ptr->nextvertex->info == v)
            {
                break;
            }
            ptr = ptr->nextvertex;
        }
        if (ptr->nextvertex == NULL)
        {
            printf("Not found\n");
            return;
        }
        else
        {
            temp = ptr->nextvertex;
            ptr->nextvertex = temp->nextvertex;
        }
    }
    struct edge *q = temp->firstedge, *temporary;
    while (q != NULL)
    {
        temporary = q;
        q = q->nextedge;
        free(q);
    }
    free(temp);
}

void deledge(int u, int v)
{
    struct vertex *orig = findvertex(u);
    if (orig == NULL)
    {
        printf("Origin not present\n");
        return;
    }
    if (orig->firstedge == NULL)
    {
        printf("Edge is not present\n");
        return;
    }
    struct edge *ed;
    if (orig->firstedge->destvertex->info == v)
    {
        ed = orig->firstedge;
        orig->firstedge = ed->nextedge;
        free(ed);
        return;
    }
    struct edge *q = orig->firstedge;
    while (q->nextedge != NULL)
    {
        if (q->nextedge->destvertex->info == v)
        {
            ed = q->nextedge;
            q->nextedge = ed->nextedge;
            free(ed);
            return;
        }
        q = q->nextedge;
    }
}

void display()
{
    if (start == NULL)
    {
        printf("The graph has no vertices or edges\n");
        return;
    }
    struct vertex *ptr = start;
    struct edge *ed;
    while (ptr != NULL)
    {
        ed = ptr->firstedge;
        printf(" %d --> ", ptr->info);
        while (ed != NULL)
        {
            printf(" %d --> ", ed->destvertex->info);
            ed = ed->nextedge;
        }
        printf("NULL");
        ptr = ptr->nextvertex;
        printf("\n");
        printf(" | \n");
        printf(" v ");
        printf("\n");
    }
    printf("NULL");
    printf("\n");
}

#define MAX 50
int queue[MAX];
int front = -1, rear = -1;

void insert(int v)
{
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

int delq()
{
    if (front == -1)
    {
        printf("Underflow\n");
        exit(1);
    }
    return queue[front++];
}

int isqempty()
{
    return (front == -1);
}

void BFT()
{
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = 0;
    struct vertex *ptr = start;
    struct edge *ed;
    int queue[n], front = -1, rear = -1;
    while (ptr != NULL)
    {
        if (arr[ptr->info] == 0) // not visited
        {
            printf("%d ", ptr->info);
            arr[ptr->info] = 1;
            insert(ptr->info);
            while (front != rear)
            {
                int temp = delq();
                ed = findvertex(temp)->firstedge;
                while (ed != NULL)
                {
                    if (arr[ed->destvertex->info] == 0)
                    {
                        printf("%d ", ed->destvertex->info);
                        arr[ed->destvertex->info] = 1;
                        insert(ed->destvertex->info);
                    }
                    ed = ed->nextedge;
                }
            }
        }
        ptr = ptr->nextvertex;
    }
}

int stack[MAX];
int top = -1;

void push(int v)
{
    if (top == MAX - 1)
    {
        printf("S overflow\n");
        return;
    }
    stack[++top] = v;
}

int pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
        exit(1);
    }
    return stack[top--];
}

void DFT()
{
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    struct vertex *ptr = start;
    struct edge *ed;
    while (ptr != NULL)
    {
        if (visited[ptr->info] == 0)
        {
            printf("%d ", ptr->info);
            visited[ptr->info] = 1;
            push(ptr->info);
            while (top != -1) // this is not is empty
            {
                int temp = stack[top]; // this is not pop
                ed = findvertex(temp)->firstedge;
                while (ed != NULL)
                {
                    if (visited[ed->destvertex->info] == 0)
                    {
                        printf("%d ", ed->destvertex->info);
                        visited[ed->destvertex->info] = 1;
                        push(ed->destvertex->info);
                        break;
                    }
                    ed = ed->nextedge;
                }
                if (ed == NULL)
                {
                    top--;
                }
            }
        }
        ptr = ptr->nextvertex;
    }
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 7; i++)
    {
        addvertex(i);
    }
    addedge(0, 1), addedge(0, 3), addedge(0, 4), addedge(1, 2), addedge(1, 4), addedge(2, 4), addedge(2, 5);
    addedge(3, 4), addedge(3, 6), addedge(4, 5), addedge(4, 6), addedge(5, 6);
    display();
    int choice;
    int v, sv, ev;
    do
    {
        printf("Choose an option\n1. Add a vertex\n2. Add an edgee\n3. BFS\n4. DFS\n5. Display\n6. Delete Vertex\n7. Delete Edge\nEnter -1 to Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter vertex: ");
            scanf("%d", &v);
            addvertex(v);
            break;
        case 2:
            printf("Enter starting vertex: ");
            scanf("%d", &sv);
            printf("Enter ending vertex: ");
            scanf("%d", &ev);
            addedge(sv, ev);
            break;
        case 3:
            BFT();
            break;
        case 4:
            DFT();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Enter vertex: ");
            scanf("%d", &v);
            deleteIncomingEdges(v);
            deletevertex(v);
            break;
        case 7:
            printf("Enter starting vertex: ");
            scanf("%d", &sv);
            printf("Enter ending vertex: ");
            scanf("%d", &ev);
            deledge(sv, ev);
            break;
        case -1:
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid option!\nTry again...\n");
            break;
        }
    } while (choice != -1);
    return 0;
}

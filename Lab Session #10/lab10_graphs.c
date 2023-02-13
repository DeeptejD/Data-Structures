#include <stdio.h>
#include <stdlib.h>

// ------------
int n = 7; // total vertices;
// ------------

struct vertex
{
    int info;
    struct edge *firstedge;
    struct vertex *nextvertex;
};

struct edge
{
    struct edge *nextedge;
    struct vertex *destvertex;
};

struct vertex *start = NULL;

void addvertex(int v)
{
    struct vertex *ptr = start;
    struct vertex *temp;
    if ((temp = (struct vertex *)malloc(sizeof(struct vertex))) == NULL)
    {
        printf("<memory overflow>\n");
        return;
    }
    temp->info = v, temp->nextvertex = temp->firstedge = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        while (ptr->nextvertex != NULL)
            ptr = ptr->nextvertex;
        ptr->nextvertex = temp;
    }
    n++;
}

struct vertex *findvertex(int v)
{
    struct vertex *ptr = start, *loc;
    while (ptr != NULL)
    {
        if (ptr->info == v)
        {
            loc = ptr;
            return loc;
        }
        else
        {
            ptr = ptr->nextvertex;
        }
    }
    printf("vertex %d not present\n", v);
}

void addedge(int u, int v)
{
    struct vertex *locu = findvertex(u), *locv = findvertex(v);
    if (locu == NULL)
    {
        printf("Start vertex not present\n");
        return;
    }
    if (locv == NULL)
    {
        printf("Destination vertex not present\n");
        return;
    }
    struct edge *ed;
    if ((ed = (struct edge *)malloc(sizeof(struct edge))) == NULL)
    {
        printf("<memory overflow>\n");
        return;
    }
    ed->destvertex = locv;
    ed->nextedge = NULL;
    if (locu->firstedge == NULL)
    {
        locu->firstedge = ed;
    }
    else
    {
        struct edge *tempedge = locu->firstedge;
        while (tempedge->nextedge != NULL)
            tempedge = tempedge->nextedge;
        tempedge->nextedge = ed;
    }
    return;
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

// bfs using adjacency list

void BFT()
{
    int visited[n]; // here n is the total vertices which in this case is 7
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    struct vertex *ptr = start;
    struct edge *ed;
    int queue[n], front = -1, rear = -1;
    while (ptr != NULL)
    {
        if (visited[ptr->info] == 0)
        {
            printf("%d ", ptr->info);
            visited[ptr->info] = 1;
            queue[++rear] = ptr->info;
            while (front != rear)
            {
                int temp = queue[++front];
                ed = findvertex(temp)->firstedge;
                while (ed != NULL)
                {
                    if (visited[ed->destvertex->info] == 0)
                    {
                        printf("%d ", ed->destvertex->info);
                        visited[ed->destvertex->info] = 1;
                        queue[++rear] = ed->destvertex->info;
                    }
                    ed = ed->nextedge;
                }
            }
        }
        ptr = ptr->nextvertex;
    }
}

// dfs using adjacency list

void DFT()
{
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    struct vertex *ptr = start;
    struct edge *ed;
    int stack[n], top = -1;
    while (ptr != NULL)
    {
        if (visited[ptr->info] == 0)
        {
            printf("%d ", ptr->info);
            visited[ptr->info] = 1;
            stack[++top] = ptr->info;
            while (top != -1)
            {
                int temp = stack[top];
                ed = findvertex(temp)->firstedge;
                while (ed != NULL)
                {
                    if (visited[ed->destvertex->info] == 0)
                    {
                        printf("%d ", ed->destvertex->info);
                        visited[ed->destvertex->info] = 1;
                        stack[++top] = ed->destvertex->info;
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

void deleteedge(int u, int v)
{
    struct vertex *locu = findvertex(u), *locv = findvertex(v);
    if (locu == NULL)
    {
        printf("Start vertex not present\n");
        return;
    }
    if (locv == NULL)
    {
        printf("Destination vertex not present\n");
        return;
    }
    struct edge *ed = locu->firstedge, *prev = NULL;
    while (ed != NULL)
    {
        if (ed->destvertex == locv)
        {
            if (prev == NULL)
            {
                locu->firstedge = ed->nextedge;
            }
            else
            {
                prev->nextedge = ed->nextedge;
            }
            free(ed);
            return;
        }
        prev = ed;
        ed = ed->nextedge;
    }
    printf("Edge not present\n");
}

void deletevertex(int v)
{
    struct vertex *vert = findvertex(v);
    if (vert == NULL)
    {
        printf("The vertex is not presnt\n");
        return NULL;
    }
    // first we delete all the incming edges
    struct vertex *ptr = start;
    while (ptr != NULL)
    {
        struct edge *temped = ptr->firstedge;
        while (temped != NULL)
        {
            if (temped->destvertex == vert)
            {
                struct edge *deled = temped;
                temped = temped->nextedge;
                free(deled);
            }
            else
            {
                temped = temped->nextedge;
            }
        }
        ptr = ptr->nextvertex;
    }
    // now we delete the outgoing edges
    ptr = vert;
    struct edge *temp = vert->firstedge;
    while (temp != NULL)
    {
        struct edge *deled = temp;
        temp = temp->nextedge;
        free(deled);
    }
    ptr = start;
    struct vertex *par = NULL;
    while (ptr != vert)
    {
        par = ptr;
        ptr = ptr->nextvertex;
    }
    par = ptr->nextvertex;
    free(ptr);
    return;
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
            deletevertex(v);
            break;
        case 7:
            printf("Enter starting vertex: ");
            scanf("%d", &sv);
            printf("Enter ending vertex: ");
            scanf("%d", &ev);
            deleteedge(sv, ev);
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

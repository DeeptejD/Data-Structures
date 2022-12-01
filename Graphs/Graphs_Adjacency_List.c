#include <stdio.h>
#include <stdlib.h>

struct Edge; // forward declaration

// structure of vertex Linked List
struct Vertex
{
    int info;                  // info of vertex
    struct Vertex *nextVertex; // next Vertex
    struct Edge *firstEdge;    // first edge from the vertex node (node)-->
} *start = NULL;

// Structure of Edge Linked List
struct Edge
{
    struct Vertex *destVertex; // destination vertex to which the vertex LL node points to
    struct Edge *nextEdge;     // next edge (destination)-->
};

// INSERT A VERTEX
void insertVertex(int v)
{
    struct Vertex *temp, *ptr;
    if ((temp = (struct Vertex *)malloc(sizeof(struct Vertex ))) == NULL)
    {
        printf("No memory\n");
        exit(1);
    }
    temp->info = v;
    temp->nextVertex = NULL, temp->firstEdge = NULL;
    if (start == NULL)
    {
        start = temp;
        return;
    }
    ptr = start;
    while (ptr->nextVertex != NULL)
        ptr = ptr->nextVertex;
    ptr->nextVertex = temp;
}

// DELETE A VERTEX
void deleteVertex(int v)
{
    // empty case
    if (start == NULL)
    {
        printf("No vertex to be deleted\n");
        return;
    }

    struct Vertex *temp, *q; // temp is what is abt to be deleted

    // first vertex to be deleted
    if (start->info == v)
    {
        temp = start;
        start = start->nextVertex;
    }
    else
    {
        q = start;
        while (q->nextVertex != NULL)
        {
            if (q->nextVertex->info == v)
                break;
            q = q->nextVertex;
        }
        if (q->nextVertex == NULL)
        {
            printf("The vertex is not present\n");
            return;
        }
        else
        {
            temp = q->nextVertex;
            q->nextVertex = q->nextVertex->nextVertex;
        }
    }
    // before freeing the node we free all the outgoing edges first
    struct Edge *p = temp->firstEdge;
    // freeing outgoing edges
    while (p != NULL)
    {
        struct Edge tempedge = p;
        p = p->nextEdge;
        free(tempedge);
    }
    free(temp);
}

void deleteIncoming(int v)
{
    struct Vertex *ptr = start;
    struct Edge *q;
    while (ptr != NULL)
    {
        if (ptr->firstEdge == NULL)
        {
            ptr = ptr->nextVertex;
            continue;
        }
        if (ptr->firstEdge->destVertex->info == v)
        {
            struct Edge *tmp = ptr->firstEdge;
            ptr->firstEdge = tmp->nextEdge;
            free(tmp);
            continue;
        }
        q = ptr->firstEdge;
        while (q->nextEdge != NULL)
        {
            if (q->nextEdge->destVertex->info == v)
            {
                struct Edge *tempedge = q->nextEdge;
                q->nextEdge = q->nextEdge->nextEdge;
                free(tempedge);
                continue;
            }
            q = q->nextEdge;
        }
        ptr = ptr->nextVertex;
    }
}

struct Vertex *findVertex(int v)
{
    struct Vertex *ptr = start, *loc;
    while (ptr != NULL)
    {
        if (ptr->info == v)
        {
            loc = ptr;
            return loc;
        }
        else
            ptr = ptr->nextVertex;
    }
    printf("The vertex wasnt found, returning NULL instead\n");
    loc = NULL;
    return loc;
}

void insertEdge(int u, int v)
{
    struct Vertex *locu, *locv;
    struct Vertex *ptr, *tmp;
    locu = findVertex(u);
    locv = findVertex(v);
    if (locu == NULL)
    {
        printf("Source Vertex is not present\n", u);
        return;
    }
    if (locv == NULL)
    {
        printf("%d is not present\n", v);
        return;
    }
    if ((tmp = (struct Edge *)malloc(sizeof(struct Vertex))) == NULL)
    {
        printf("No memory\n");
        return;
    }
    tmp->
    if (locu->firstEdge == NULL)
    {
        
    }
}

int main()
{
}

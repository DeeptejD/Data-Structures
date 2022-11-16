#include <stdio.h>
#include <stdlib.h>

struct Edge;
struct Vertex
{
    int info;
    struct Vertex *nextVertex;
    struct Edge *firstEdge;
} *start = NULL;

struct Edge
{
    struct Vertex *destVertex;
    struct Edge *nextEdge;
};

// INSERT A VERTEX
void insertVertex(int v)
{
    struct Vertex *temp, *ptr;
    if ((temp = (struct Vertex *)malloc(sizeof(struct Vertex))) == NULL)
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
    if (start == NULL)
    {
        printf("No vertex to be deleted\n");
        return;
    }
    struct Vertex *temp, *q;
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
    // before freeing the node we free all the edges first
    struct Edge *p = temp->firstEdge;
    // freeing outgoing edges
    while (p != NULL)
    {
        struct Edge *tempedge = p;
        p = p->nextEdge;
        free(tempedge);
    }
    free(temp);
}

void deleteIncomingEdges(int v)
{
    struct Vertex *ptr = start;
    while (ptr != NULL)
    {
        if (ptr->firstEdge == NULL)
        {
            ptr = ptr->nextVertex;
        }
        if (ptr->firstEdge->destVertex->info == v)
        {
        }
    }
}

int main()
{
}

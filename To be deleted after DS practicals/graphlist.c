#include <stdio.h>
#include <stdlib.h>

struct edge;

struct vertex
{
    int info;
    struct edge *firstedge;
    struct vertex *nextvertex;
} *start = NULL;

struct edge
{
    struct vertex *destvertex;
    struct edge *nextedge;
};

void insertvertex(int u)
{
    struct vertex *temp, *ptr = start;
    temp = (struct vertex *)malloc(sizeof(struct vertex));
    temp->info = u, temp->firstedge = temp->nextvertex = NULL;
    if (start == NULL)
    {
        start = temp;
        return;
    }
    ptr = start;
    while (ptr->nextvertex != NULL)
        ptr = ptr->nextvertex;
    ptr->nextvertex = temp;
    return;
}

void delincoming(int u)
{
    struct edge *temp, *q;
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
            temp = ptr->firstedge;
            ptr->firstedge = temp->nextedge;
            free(temp);
            continue;
        }
        q = ptr->firstedge;
        while (q->nextedge != NULL)
        {
            if (q->nextedge->destvertex->info == u)
            {
                temp = q->nextedge;
                q->nextedge = temp->nextedge;
                free(temp);
                continue;
            }
            q = q->nextedge;
        }
        ptr = ptr->nextvertex;
    }
}

struct vertex *findvertex(int u)
{
    struct vertex *ptr = start, *loc;
    while (ptr != NULL)
    {
        if (ptr->info == u)
        {
            loc = ptr;
            return loc;
        }
        else
        {
            ptr = ptr->nextvertex;
        }
    }
    return NULL;
}

void insertedge(int u, int v)
{
    struct vertex *orig = findvertex(u), *dest = findvertex(v);
    if (orig == NULL)
    {
        printf("The origin is invalid\n");
        return;
    }
    if (dest == NULL)
    {
        printf("The destination is invalid\n");
        return;
    }
    struct edge *temp, *ptr;
    temp = (struct edge *)malloc(sizeof(struct edge));
    temp->destvertex = dest;
    temp->nextedge = NULL;
    if (orig->firstedge == NULL)
    {
        orig->firstedge = temp;
        return;
    }
    else
    {
        ptr = orig->firstedge;
        while (ptr->nextedge != NULL)
            ptr = ptr->nextedge;
        ptr->nextedge = temp;
        return;
    }
}

void deledge(int u, int v)
{
    struct vertex *orig = findvertex(u);
    struct edge *temp, *q;
    if (orig == NULL)
    {
        printf("The origin vertex is not present\n");
        return;
    }
    if (orig->firstedge == NULL)
    {
        printf("The edge is not present\n");
        return;
    }
    if (orig->firstedge->destvertex->info == v)
    {
        temp = orig->firstedge;
        orig->firstedge = temp->nextedge;
        free(temp);
        return;
    }
    q = orig->firstedge;
    while (q->nextedge != NULL)
    {
        if (q->nextedge->destvertex->info == v)
            ;
        {
            temp = q->nextedge;
            q->nextedge = temp->nextedge;
            free(temp);
            return;
        }
        q = q->nextedge;
    }
}

void display()
{
    if (start == NULL)
        printf("NULL\n");
    else
    {
        struct edge *q;
        struct vertex *ptr = start;
        while (ptr != NULL)
        {
            printf("%d --> ", ptr->info);
            if (ptr->firstedge == NULL)
            {
                printf("NULL\n");
                printf("|\n");
                printf("\\/");
                printf("\n");
            }
            else
            {
                q = ptr->firstedge;
                while (q != NULL)
                {
                    printf("%d -->", q->destvertex->info);
                    q = q->nextedge;
                }
                printf("NULL\n");
                printf("|\n");
                printf("\\/");
                printf("\n");
            }
            ptr = ptr->nextvertex;
        }
        printf("NULL\n");
    }
}

void delvertex(int u)
{
    if (start == NULL)
    {
        printf("The graph has no vertices to be deleted\n");
        return;
    }
    struct vertex *temp, *ptr = start;
    if (start->info == u)
    {
        temp = start;
        start = start->nextvertex;
    }
    else
    {
        while (ptr->nextvertex != NULL)
        {
            if (ptr->nextvertex->info == u)
                break;
            else
                ptr = ptr->nextvertex;
        }
        if (ptr->nextvertex == NULL)
        {
            printf("Vertex to be deleted is not present\n");
            return;
        }
        else
        {
            temp = ptr->nextvertex;
            ptr->nextvertex = temp->nextvertex;
        }
    }

    // now temp has the vertex that is to be deleted
    // before deleting this vertex we deleted all its outgoing edges

    struct edge *p = temp->firstedge, *temporary;
    while (p != NULL)
    {
        temporary = p;
        p = p->nextedge;
        free(temporary);
    }
    free(temp);
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 7; i++)
    {
        insertvertex(i);
    }
    insertedge(0, 1), insertedge(1, 0), insertedge(0, 3), insertedge(3, 0), insertedge(0, 4), insertedge(4, 0), insertedge(1, 2), insertedge(2, 1), insertedge(1, 4), insertedge(4, 1), insertedge(2, 4), insertedge(4, 2), insertedge(2, 5), insertedge(5, 2);
    insertedge(3, 4), insertedge(4, 3), insertedge(3, 6), insertedge(6, 3), insertedge(4, 5), insertedge(5, 4), insertedge(4, 6), insertedge(6, 4), insertedge(5, 6), insertedge(6, 5);
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
            insertvertex(v);
            break;
        case 2:
            printf("Enter starting vertex: ");
            scanf("%d", &sv);
            printf("Enter ending vertex: ");
            scanf("%d", &ev);
            insertedge(sv, ev);
            insertedge(ev, sv);
            break;
        case 3:
            // BFT();
            break;
        case 4:
            // DFT();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Enter vertex: ");
            scanf("%d", &v);
            delvertex(v);
            break;
        case 7:
            printf("Enter starting vertex: ");
            scanf("%d", &sv);
            printf("Enter ending vertex: ");
            scanf("%d", &ev);
            deledge(sv, ev);
            deledge(ev, sv);
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

    return 0;
}

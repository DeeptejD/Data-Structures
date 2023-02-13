#include <stdio.h>
#include <stdlib.h>
#define sint(x) scanf("%d", &x)

/*
TEST CASE:
PS C:\Users\joshu\Desktop\School\Data Structures> g++ .\LS6A.c
PS C:\Users\joshu\Desktop\School\Data Structures> .\a.exe
enter the number of nodes in the doubly linked list
5
enter value of node 1 1
enter value of node 2 2
enter value of node 3 3
enter value of node 4 6
enter value of node 5 9
1 -> perform swap
2 -> display
3 -> exit
1
enter the node number to be swapped with its left neighbour 3
1 -> perform swap
2-> display
3 -> exit
2
doubly linked list : 1 3 2 6 9
1 -> perform swap
2 -> display
3 -> exit
3
PS C:\Users\joshu\Desktop\School\Data Structures>
*/

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// add new node
struct node *add_at_end(struct node *start, int value);

// display
void display(struct node *start);

// swap
struct node *perform_swap(struct node *start, int l, int r)
{
    if (r == 1)
        printf("invalid index\n");
    else
    {
        struct node *n1 = start, *n2 = start;

        // find n1
        while (n1 != NULL && l != 1)
            n1 = n1->next, l--;

        if (n1 == NULL || n1->next == NULL)
        {
            printf("invalid index\n");
            return start;
        }

        // find n2
        n2 = n1->next;
        struct node *prev_n1 = n1->prev, *next_n2 = n2->next;
        if (prev_n1 == NULL && next_n2 == NULL)
        {
            n1->next = NULL, n1->prev = n2;
            n2->next = n1, n2->prev = NULL;
            start = n2;
        }
        else if (prev_n1 == NULL)
        {
            n1->next = next_n2, next_n2->prev = n1, n1->prev = n2,
            n2->prev = NULL, n2->next = n1;
            start = n2;
        }
        else if (next_n2 == NULL)
        {
            n1->next = NULL, n1->prev = n2,
            n2->prev = prev_n1, prev_n1->next = n2, n2->next = n1;
        }
        else
        {
            n1->next = next_n2, next_n2->prev = n1, n1->prev = n2,
            n2->prev = prev_n1, prev_n1->next = n2, n2->next = n1;
        }
    }

    return start;
}

int main()
{
    int value, target, n;
    struct node *start = NULL;

    // creation
    printf("enter the number of nodes in the doubly linked list\n"), sint(n);
    for (int i = 0; i < n; i++)
        printf("enter value of node %d", i + 1), sint(value), start = add_at_end(start, value);

    while (1)
    {
        int sw;
        printf("1 -> perform swap\n2 -> display\n3 -> exit\n"), sint(sw);

        switch (sw)
        {
        case 1:
            printf("enter the node number to be swapped with its left neighbour ");
            sint(target), start = perform_swap(start, target - 1, target);
            break;

        case 2:
            display(start);
            break;

        case 3:
            exit(0);
            break;

        default:
            exit(1);
            break;
        }
    }

    return 0;
}

struct node *add_at_end(struct node *start, int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value, temp->next = NULL, temp->prev = NULL;

    if (start == NULL) // add in empty
        return temp;
    else // add at end
    {
        struct node *p = start;
        while (p->next != NULL)
            p = p->next;

        p->next = temp;
        temp->prev = p;
        return start;
    }
}
void display(struct node *start)
{
    printf("doubly linked list : ");
    while (start != NULL)
        printf("%d ", start->data),
            start = start->next;
    printf("\n");
}
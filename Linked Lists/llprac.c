#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;

} *start = NULL;

struct node *createnode(int info)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = info, temp->next = NULL;
    return temp;
}

void addatend(int info)
{
    if (start == NULL)
        start = createnode(info);
    else
    {
        struct node *ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = createnode(info);
    }
}

void disp()
{
    struct node *ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

void rev()
{
    struct node *prev = NULL, *curr = start, *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    start = prev;
}

int main(int argc, char const *argv[])
{
    addatend(10);
    addatend(20);
    addatend(30);
    addatend(40);
    addatend(50);
    disp();
    rev();
    disp();
    return 0;
}

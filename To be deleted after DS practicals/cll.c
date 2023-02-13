#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
} *last = NULL;

void display()
{
    if (last != NULL)
    {
        struct node *ptr = last->next;
        do
        {
            printf("%d ", ptr->info);
            ptr->next;
        } while (ptr != last->next);
    }
}

void *addtoempty(int info)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = info, temp->next = temp, last = temp;
}

void addatbeg(int info)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = info, temp->next = last->next, last->next = temp;
}

void addatend(int info)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = info, temp->next = last->next, last->next = temp, last = temp;
}



int main(int argc, char const *argv[])
{

    return 0;
}

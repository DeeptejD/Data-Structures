#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *prev, *next;
};

struct node *start = NULL;

struct node *addtoempty(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item, temp->next = NULL, temp->prev = NULL;
    start = temp;
    return start;
}

struct node *addatbeg(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item, temp->next = start, temp->prev = NULL, start->prev = temp, start = temp;
    return start;
}

struct node *addbefore(int item, int info)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = info;
    struct node *ptr = start;
    if (start->info == item)
    {
        addatbeg(info);
        return;
    }
    while (ptr != NULL)
    {
        if (ptr->info == item)
        {
            temp->prev = ptr->prev, temp->next = ptr;
            ptr->prev->next = temp, ptr->prev = temp;
            return;
        }
        ptr = ptr->next;
    }
}

struct node *addafter(int info, int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node)), *ptr = start;
    temp->info = info;
    while (ptr != NULL)
    {
        if (ptr->info == item)
        {
            temp->next = ptr->prev, temp->next = ptr->next;
            if (ptr->next != NULL)
                ptr->next->prev = temp;
            ptr->next = temp;
            return;
        }
        ptr = ptr->next;
    }
}

void del(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node)), *ptr = start;
    if (start->info == item)
    {
        if (start->next == NULL)
        {
            temp = start, start = NULL;
            free(temp);
            return;
        }
        else
        {
            temp = start, start->next->prev = NULL, start = start->next;
            free(temp);
            return;
        }
    }
    while (ptr->next != NULL)
    {
        if (ptr->info == item)
        {
            temp = ptr, ptr->next->prev = ptr->prev, ptr->prev->next = ptr->next;
            free(temp);
            return;
        }
        ptr = ptr->next;
    }
    if (ptr->info == item)
    {
        temp = ptr;
        ptr->prev->next = NULL;
        free(temp);
        return;
    }
    printf("Not found\n");
}

int main(int argc, char const *argv[])
{

    return 0;
}

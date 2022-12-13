#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *addatbeg(struct node *start, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->info = data;
    ptr->next = start->next,
    start = ptr;
    return start;
}

struct node *addatend(struct node *start, int data)
{
    struct node *p, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data, tmp->next = NULL;
    p = start;
    while (p->next != NULL)
        p = p->next;

    p->next = tmp;
    return start;
}

struct node *addafter(struct node *start, int data, int item)
{
    struct node *tmp, *p;
    p = start;
    while (p != NULL)
    {
        if (p->info == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->next = p->next;
            p->next = tmp;
            return start;
        }
        p = p->next;
    }
    printf("%d not present in the list\n", item);
    return start;
}

struct node *addbefore(struct node *start, int data, int item)
{
    struct node *tmp, *p;
    if (start == NULL)
    {
        printf("Empty\n");
        return start;
    }
    if (item == start->info)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data;
        tmp->next = start;
        start = tmp;
        return start;
    }
    p = start;
    while (p != NULL)
    {
        if (p->next->info == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->next = p->next;
            p->next = tmp;
            return start;
        }
        p = p->next;
    }
    printf("%d not present in the list\n", item);
}

struct node *create(struct node *start)
{
    struct node *tmp, *ptr;
    int num, i;
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the info: ");
        scanf("%d", &tmp->info);
        tmp->next = NULL;
        if (start == NULL)
            start = tmp;
        else
        {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = tmp;
        }
    }
    return start;
}

int search(struct node *ptr, int item)
{
    if (ptr == NULL)
        return -1;
    else if (ptr->info == item)
        return 1;
    else
        search(ptr->next, item);
}

int count(struct node *start)
{
    struct node *ptr = start;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

struct node *delete(struct node *start, int item)
{
    struct node *temp, *p;
    if (start == NULL)
    {
        printf("Empty\n");
        return start;
    }
    if (start->info == item)
    {
        temp = start;
        start = start->next;
        free(temp);
        return start;
    }
    p = start;
    while (p->next != NULL)
    {
        if (p->next->info == item)
        {
            temp = p->next;
            p->next = temp->next;
            free(temp);
            return start;
        }
        p = p->next;
    }
    printf("Element not found\n");
    return start;
}

struct node *reverse(struct node *start)
{
    struct node *prev, *ptr, *next;
    prev = NULL, ptr = start;
    while (ptr != NULL)
    {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr, ptr = next;
    }
    start = prev;
    return start;
}

void display(struct node *start)
{
    if (start == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct node *p = start;
    while (p != NULL)
    {
        if (p->next == NULL)
        {
            printf("%d\n", p->info);
            return;
        }
        printf("%d --> ", p->info);
        p = p->next;
    }
}

struct node *addatpos(struct node *start, int data, int item)
{
    struct node *tmp, *p;
    int i;
    p = start;
    for (i = 1; i < item - 1 && p != NULL; i++)
        p = p->next;
    if (p == NULL)
        printf("There are less than %d elements\n", item);
    else
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data;
        tmp->next = p->next;
        p->next = tmp;
    }
    return start;
}

int main(int argc, char const *argv[])
{
    struct node *start = NULL;
    while (1)
    {
        printf("Choose\n1.create\n2.search\n3.count\n4.delete\n5.display\n6.before\n7.end\n8.atbeg\n9.after\n10.rev\n11.pos\n");
        int choice;
        scanf("%d", &choice);
        int item, data;
        switch (choice)
        {
        case 1:
            start = create(start);
            break;
        case 2:
            scanf("%d", &item);
            if (search(start, item))
                printf("found\n");
            else
                printf("not found\n");
            break;
        case 3:
            printf("%d elements in the list\n", count(start));
            break;
        case 4:
            printf("Enter item to be deleted: ");
            scanf("%d", &item);
            start = delete (start, item);
            break;
        case 5:
            display(start);
            break;
        case 6:
            printf("Enter: ");
            scanf("%d", &data);
            printf("before? ");
            scanf("%d", &item);
            start = addbefore(start, data, item);
            break;
        case 7:
            printf("Enter: ");
            scanf("%d", &data);
            start = addatend(start, data);
            break;
        case 8:
            printf("Enter: ");
            scanf("%d", &data);
            start = addatbeg(start, data);
            break;
        case 9:
            printf("Enter: ");
            scanf("%d", &data);
            printf("after? ");
            scanf("%d", &item);
            start = addafter(start, data, item);
            break;
        case 10:
            start = reverse(start);
            display(start);
            break;
        case 11:
            printf("Enter: ");
            scanf("%d", &data);
            printf("at pos? ");
            scanf("%d", &item);
            start = addatpos(start, data, item);
            break;
        case 12:
            exit(1);
        default:
            break;
        }
    }

    return 0;
}

// doubly linked lists

#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int info;
    struct node *next;
};

struct node *addatbeg(struct node *start, int n)
{
    struct node *tmp;
    if ((tmp = (struct node *)malloc(sizeof(struct node))) == NULL)
    {
        printf("NO mem");
        exit(1);
    }
    tmp->info = n;
    tmp->next = start;
    tmp->prev = NULL;
    start = tmp;
    return start;
}

struct node *addatend(struct node *start, int n)
{
    struct node *ptr = start, *tmp;
    if (start == NULL)
        addatbeg(start, n);
    while (ptr->next != NULL)
        ptr = ptr->next;
    if ((tmp = (struct node *)malloc(sizeof(struct node))) == NULL)
    {
        printf("no mem");
        exit(1);
    }
    tmp->info = n;
    tmp->next = ptr->next;
    tmp->prev = ptr;
    ptr->next = tmp;
    return start;
}

struct node *addatempty(struct node *start, int n)
{
    struct node *tmp;
    if ((tmp = (struct node *)malloc(sizeof(struct node))) == NULL)
    {
        printf("no mem");
        exit(1);
    }
    tmp->info = n;
    tmp->next = NULL;
    tmp->prev = NULL;
    start = tmp;
    return start;
}

struct node *addbefore(struct node *start, int n, int x)
{
    struct node *ptr = start, *tmp;
    if (start == NULL)
    {
        printf("list is empty");
        return start;
    }
    while (ptr->info != x)
    {
        ptr = ptr->next;
        if (ptr == NULL)
        {
            printf("no such element");
            return start;
        }
    }
    if (ptr->prev == NULL)
        start = addatbeg(start, n);
    else
    {
        if ((tmp = (struct node *)malloc(sizeof(struct node))) == NULL)
        {
            printf("no mem");
            exit(1);
        }
        tmp->info = n;
        tmp->next = ptr;
        tmp->prev = ptr->prev;
        ptr->prev->next = tmp;
        ptr->prev = tmp;
    }
    return start;
}

struct node *addafter(struct node *start, int n, int x)
{
    struct node *ptr = start, *tmp;
    if (start == NULL)
    {
        printf("list is empty");
        return start;
    }
    while (ptr->info != x)
    {
        ptr = ptr->next;
        if (ptr == NULL)
        {
            printf("no such element");
            return start;
        }
    }
    if (ptr->next == NULL)
        start = addatend(start, n);
    else
    {
        if ((tmp = (struct node *)malloc(sizeof(struct node))) == NULL)
        {
            printf("no mem");
            exit(1);
        }
        tmp->info = n;
        tmp->next = ptr->next;
        tmp->prev = ptr;
        ptr->next->prev = tmp;
        ptr->next = tmp;
    }
    return start;
}

struct node *addatpos(struct node *start, int n, int pos)
{
    struct node *ptr = start, *tmp;
    if (start == NULL)
    {
        printf("list is empty");
        return start;
    }
    if (pos == 1)
        start = addatbeg(start, n);
    else
    {
        while (pos > 2)
        {
            ptr = ptr->next;
            if (ptr == NULL)
            {
                printf("no such element");
                return start;
            }
            pos--;
        }
        if (ptr->next == NULL)
            start = addatend(start, n);
        else
        {
            if ((tmp = (struct node *)malloc(sizeof(struct node))) == NULL)
            {
                printf("no mem");
                exit(1);
            }
            tmp->info = n;
            tmp->next = ptr->next;
            tmp->prev = ptr;
            ptr->next->prev = tmp;
            ptr->next = tmp;
        }
    }
    return start;
}

struct node *create_list(struct node *start)
{
    int n, i;
    printf("enter no of nodes");
    scanf("%d", &n);
    if (n == 0)
        return start;
    printf("enter element to be inserted");
    scanf("%d", &i);
    start = addatempty(start, i);
    for (int j = 2; j <= n; j++)
    {
        printf("enter element to be inserted");
        scanf("%d", &i);
        start = addatend(start, i);
    }
    return start;
}

struct node *delete(struct node *start, int n)
{
    struct node *ptr = start;
    if (start == NULL)
    {
        printf("list is empty");
        return start;
    }
    while (ptr->info != n)
    {
        ptr = ptr->next;
        if (ptr == NULL)
        {
            printf("no such element");
            return start;
        }
    }
    if (ptr->prev == NULL)
        start = ptr->next;
    else
        ptr->prev->next = ptr->next;
    if (ptr->next != NULL)
        ptr->next->prev = ptr->prev;
    free(ptr);
    return start;
}

struct node *reverse(struct node *start)
{
    struct node *ptr = start, *tmp;
    while (ptr != NULL)
    {
        tmp = ptr->next;
        ptr->next = ptr->prev;
        ptr->prev = tmp;
        ptr = ptr->prev;
        if (ptr != NULL && ptr->next == NULL)
            start = ptr;
    }
    return start;
}

void display(struct node *start)
{
    struct node *ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
}

void search(struct node *start, int n)
{
    struct node *ptr = start;
    int pos = 1;
    while (ptr != NULL)
    {
        if (ptr->info == n)
        {
            printf("element found at %d\n", pos);
            return;
        }
        pos++;
        ptr = ptr->next;
    }
    printf("no such element\n");
    return;
}

int count(struct node *start)
{
    struct node *ptr = start;
    int c = 0;
    while (ptr != NULL)
    {
        c++;
        ptr = ptr->next;
    }
    return c;
}

int main()
{
    struct node *start = NULL;
    int n, ch, pos, x;
    while (1)
    {
        printf("\n1.create list\n2.display\n3.count\n4.search\n5.addatbeg\n6.addatend\n7.addatpos\n8.addbefore\n9.addafter\n10.delete\n11.reverse\n12.quit\n");
        printf("enter choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            start = create_list(start);
            break;
        case 2:
            display(start);
            break;

        case 3:
            n = count(start);
            printf("no of nodes = %d", n);
            break;
        case 4:
            printf("enter element to be searched");
            scanf("%d", &x);
            search(start, x);
            break;
        case 5:
            printf("enter element to be inserted");
            scanf("%d", &x);
            start = addatbeg(start, x);
            break;
        case 6:
            printf("enter element to be inserted");
            scanf("%d", &x);
            start = addatend(start, x);
            break;
        case 7:
            printf("enter element to be inserted");
            scanf("%d", &x);
            printf("enter position");
            scanf("%d", &pos);
            start = addatpos(start, x, pos);
            break;
        case 8:
            printf("enter element to be inserted");
            scanf("%d", &x);
            printf("enter element before which to be inserted");
            scanf("%d", &n);
            start = addbefore(start, x, n);
            break;
        case 9:
            printf("enter element to be inserted");
            scanf("%d", &x);
            printf("enter element after which to be inserted");
            scanf("%d", &n);
            start = addafter(start, x, n);
            break;
        case 10:
            printf("enter element to be deleted");
            scanf("%d", &x);
            start = delete (start, x);
            break;
        case 11:
            start = reverse(start);
            break;
        case 12:
            exit(1);
        default:
            printf("wrong choice");
        }
    }
    return 0;
}

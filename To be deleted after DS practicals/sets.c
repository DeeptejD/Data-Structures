#include <stdio.h>
#include <stdlib.h>
#define sint(x) scanf("%d", &x);

struct node
{
    int info;
    struct node *next;
};

struct node *addatend(struct node *start, int info)
{
    struct node *ptr = start;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = info;
    if (start == NULL)
    {
        temp->next = NULL;
        start = temp;
        return start;
    }
    while (ptr->next != NULL)
        ptr = ptr->next;
    temp->next = ptr->next;
    ptr->next = temp;
    return start;
}

struct node *create(struct node *start)
{
    start = NULL;
    int n;
    printf("Enter the number of elements: ");
    sint(n);
    while (n--)
    {
        int info;
        printf("Enter the element: ");
        sint(info);
        start = addatend(start, info);
    }
    return start;
}

int search(struct node *start, int item)
{
    struct node *ptr = start;
    while (ptr != NULL)
    {
        if (ptr->info == item)
            return 1;
        ptr = ptr->next;
    }
    return 0;
}

struct node *setunion(struct node *set1, struct node *set2)
{
    struct node *ptr1 = set1, *ptr2 = set2;
    struct node *result = NULL;
    while (ptr1 != NULL)
    {
        result = addatend(result, ptr1->info);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        if (!search(set1, ptr2->info))
        {
            result = addatend(result, ptr2->info);
        }
        ptr2 = ptr2->next;
    }
    return result;
}

void display(struct node *start)
{
    struct node *ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *setintersect(struct node *s1, struct node *s2)
{
    struct node *result = NULL, *ptr1 = s1, *ptr2 = s2;
    while (ptr1 != NULL)
    {
        ptr2 = s2;
        while (ptr2 != NULL)
        {

            if (ptr2->info == ptr1->info)
            {
                result = addatend(result, ptr1->info);
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return result;
}

struct node *del(struct node *start, int item)
{
    struct node *ptr = start;
    struct node *temp;
    if (start->info == item)
    {
        temp = start;
        start = start->next;
        free(temp);
        return start;
    }
    else
    {
        while (ptr->next != NULL)
        {
            if (ptr->next->info == item)
            {
                temp = ptr->next;
                ptr->next = temp->next;
                free(temp);
                return start;
            }
            ptr = ptr->next;
        }
    }
    printf("Item not present\n");
    return start;
}

struct node *setdiff(struct node *s1, struct node *s2)
{
    struct node *s3 = NULL, *ptr1 = s1, *ptr2 = s2;
    while (ptr1 != NULL)
    {
        s3 = addatend(s3, ptr1->info);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        if (search(s3, ptr2->info) == 1)
            del(s3, ptr2->info);
        ptr2 = ptr2->next;
    }
    return s3;
}

int main(int argc, char const *argv[])
{
    struct node *set1 = NULL, *set2 = NULL;
    set1 = create(set1);
    display(set1);
    set2 = create(set2);
    display(set2);
    struct node *setun = setunion(set1, set2);
    display(setun);
    struct ndoe *inter = setintersect(set1, set2);
    display(inter);
    struct node *diff = setdiff(set1, set2);
    display(diff);
    return 0;
}

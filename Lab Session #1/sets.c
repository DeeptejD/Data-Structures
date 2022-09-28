#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *create(struct node *);

int search(struct node *, int);

void display(struct node *);

struct node *setunion(struct node *, struct node *);

struct node *setintersect(struct node *, struct node *);

struct node *del(struct node *, int);

struct node *setdifference(struct node *, struct node *);

int main()
{
    struct node *set1 = NULL, *set2 = NULL;
    int choice;
    while (1)
    {
        printf("Enter your choice.\n");
        printf("1. Enter elements of set 1 and 2.\n2. Display elements of set 1 and 2.\n3. Perform set union.\n4. Perform set intersection.\n5. Perform set difference.\n6. Exit.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            set1 = create(set1);
            set2 = create(set2);
            break;
        case 2:
            display(set1);
            display(set2);
            break;
        case 3:
            display(setunion(set1, set2));
            break;
        case 4:
            display(setintersect(set1, set2));
            break;
        case 5:
            display(setdifference(set1, set2));
            break;
        case 6:
            exit(1);
        default:
            printf("Invalid input.\n");
        }
    }
}

struct node *setdifference(struct node *s1, struct node *s2)
{
    {
        struct node *s3 = NULL, *temp;
        while (s1 != NULL)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->info = s1->info;
            temp->next = NULL;
            if (s3 == NULL)
                s3 = temp;
            else
            {
                struct node *q = s3;
                while (q->next != NULL)
                    q = q->next;
                q->next = temp;
            }
            s1 = s1->next;
        }
        while (s2 != NULL)
        {
            if (search(s3, s2->info))
            {
                del(s3, s2->info);
            }
            s2 = s2->next;
        }
        return s3;
    }
}

struct node *del(struct node *start, int data)
{
    {

        struct node *tmp, *p;
        if (start == NULL)
        {
            printf("List is empty\n");
            return start;
        }
        if (start->info == data)
        {
            tmp = start;
            start = start->next;
            free(tmp);
            return start;
        }
        p = start;
        while (p->next != NULL)
        {
            if (p->next->info == data)
            {
                tmp = p->next;
                p->next = tmp->next;
                free(tmp);
                return start;
            }
            p = p->next;
        }
        printf("Element not found.\n");
        return start;
    }
}

struct node *setintersect(struct node *s1, struct node *s2){
    {
        struct node *s3 = NULL, *p, *q, *temp;
        p = s1;
        while (p != NULL)
        {
            q = s2;
            while (q != NULL)
            {
                temp = (struct node *)malloc(sizeof(struct node));
                if (p->info == q->info)
                {
                    temp->info = q->info;
                    temp->next = NULL;
                    if (s3 == NULL)
                        s3 = temp;
                    else
                    {
                        struct node *r = s3;
                        while (r->next != NULL)
                            r = r->next;
                        r->next = temp;
                    }
                }
                q = q->next;
            }
            p = p->next;
        }
        return s3;
    }
}

struct node *setunion(struct node *s1, struct node *s2)
{
    {
        struct node *s3 = NULL;
        struct node *p = s1;
        struct node *temp;
        while (s1 != NULL)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->info = s1->info;
            temp->next = NULL;
            if (s3 == NULL)
                s3 = temp;
            else
            {
                struct node *q = s3;
                while (q->next != NULL)
                    q = q->next;
                q->next = temp;
            }
            s1 = s1->next;
        }
        while (s2 != NULL)
        {
            if (!search(p, s2->info))
            {
                temp = (struct node *)malloc(sizeof(struct node));
                temp->info = s2->info;
                temp->next = NULL;
                struct node *r = s3;
                while (r->next != NULL)
                    r = r->next;
                r->next = temp;
            }
            s2 = s2->next;
        }
        return s3;
    }
}

void display(struct node *start)
{
    {
        struct node *p = start;
        printf("The elements of set are : ");
        while (p != NULL)
        {
            printf("%d ", p->info);
            p = p->next;
        }
        printf("\n");
    }
}

int search(struct node *s, int num)
{
    {
        while (s != NULL)
        {
            if (s->info == num)
            {
                return 1;
            }
            s = s->next;
        }
        return 0;
    }
}

struct node *create(struct node *start)
{
    {
        struct node *temp, *p;
        int num = 0;
        printf("Enter the number of elements.\n");
        scanf("%d", &num);
        printf("Enter the elements\n");
        for (int i = 0; i < num; i++)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &temp->info);
            temp->next = NULL;
            if (start == NULL)
                start = temp;
            else
            {
                p = start;
                while (p->next != NULL)
                    p = p->next;
                p->next = temp;
            }
        }
        return start;
    }
}
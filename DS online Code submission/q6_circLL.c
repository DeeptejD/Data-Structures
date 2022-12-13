// circular Linked lists

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};

struct node *last = NULL;

struct node *addatbeg(struct node *last, int n)
{
    struct node *tmp;
    if ((tmp = (struct node *)malloc(sizeof(struct node))) == NULL)
    {
        printf("NO mem");
        exit(1);
    }
    tmp->info = n;
    if (last == NULL)
    {
        tmp->link = tmp;
        last = tmp;
        return last;
    }
    tmp->link = last->link;
    last->link = tmp;
    return last;
}

struct node *addatend(struct node *last, int n)
{
    struct node *tmp;
    if ((tmp = (struct node *)malloc(sizeof(struct node))) == NULL)
    {
        printf("NO mem");
        exit(1);
    }
    tmp->info = n;
    if (last == NULL)
    {
        tmp->link = tmp;
        last = tmp;
        return last;
    }
    tmp->link = last->link;
    last->link = tmp;
    last = tmp;
    return last;
}

struct node *create(struct node *last)
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        last = addatend(last, data);
    }
    return last;
}

void display(struct node *last)
{
    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    struct node *p = last->link;
    do
    {
        printf("%d ", p->info);
        p = p->link;
    } while (p != last->link);
}

struct node *addtoempty(struct node *last, int n)
{
    struct node *tmp;
    if ((tmp = (struct node *)malloc(sizeof(struct node))) == NULL)
    {
        printf("NO mem");
        exit(1);
    }
    tmp->info = n;
    tmp->link = tmp;
    last = tmp;
    return last;
}

struct node *list1 = NULL, *list2 = NULL;
void split1(struct node *last)
{
    struct node *ptr = last->link;
    if (ptr != NULL)
    {
        if (ptr->info % 2 == 0)
        {
            list1 = addtoempty(list1, ptr->info);
        }
        else
        {
            list2 = addtoempty(list2, ptr->info);
        }
        ptr = ptr->link;
    }
    if (ptr != last->link)
    {
        do
        {
            if (ptr->info % 2 == 0)
            {
                list1 = addatend(list1, ptr->info);
            }
            else
            {
                list2 = addatend(list2, ptr->info);
            }
            ptr = ptr->link;
        } while (ptr != last->link);
    }

    printf("List 1 (Even nodes): ");
    display(list1);
    printf("\n");
    printf("List 2 (Odd nodes): ");
    display(list2);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int ch;
    while (1)
    {
        printf("\n\n1. Create\n2. Display\n3. Add at beginning\n4. Add at end\n5. Split-1");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            last = create(last);
            break;
        case 2:
            display(last);
            break;
        case 3:
        {
            printf("Enter data: ");
            int data;
            scanf("%d", &data);
            last = addatbeg(last, data);
            break;
        }
        case 4:
            printf("Enter data: ");
            int data;
            scanf("%d", &data);
            last = addatend(last, data);
            break;
        case 5:
            split1(last);
            break;
        default:
            printf("Invalid choice");
            break;
        }
    }

    return 0;
}

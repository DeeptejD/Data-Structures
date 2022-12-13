#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};

struct node *front = NULL;

struct node *insertatRear()
{
    struct node *tmp, *p = front;
    if ((tmp = (struct node *)malloc(sizeof(struct node))) == NULL)
    {
        printf("overflow\n");
        exit(1);
    }
    int data;
    printf("ENter data to be inserted: ");
    scanf("%d", &data);
    tmp->info = data;
    if (front == NULL)
    {
        tmp->link = NULL;
        front = tmp;
        return front;
    }
    while (p->link != NULL)
        p = p->link;
    p->link = tmp;
    tmp->link = NULL;
    return front;
}

struct node *deletefront()
{
    if (front == NULL)
    {
        printf("Empty list\n");
        exit(1);
    }
    struct node *tmp = front;
    front = front->link;
    free(tmp);
    return front;
}

void display()
{
    if (front == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    struct node *p = front;
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->link;
    }
}

int peek()
{
    if (front == NULL)
    {
        printf("List is empty\n");
        return;
    }
    int item = front->info;
    printf("Peeked item: %d\n", item);
    return item;
}

int main(int argc, char const *argv[])
{
    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Peek\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertatRear();
            break;
        case 2:
            deletefront();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    }
    return 0;
}

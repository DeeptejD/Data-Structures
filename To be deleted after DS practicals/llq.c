#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
} *front = NULL, *rear = NULL;

void insert(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item;
    temp->next = NULL;

    if (front == NULL)
        front = temp;
    else
        rear->next = temp;
    rear = temp;
}

int del()
{
    struct node *temp;
    if (rear == NULL)
    {
        printf("Q underflow\n");
        exit(1);
    }
    temp = front;

    int item = temp->info;
    front = front->next;
    free(temp);
    return item;
}

void display()
{
    struct node *ptr = front;
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
}

int main(int argc, char const *argv[])
{
    insert(5);
    insert(4);
    insert(3);
    insert(2);
    display();
    del();
    del();
    del();
    display();
    return 0;
}

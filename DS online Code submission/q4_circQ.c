#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX] = {11, 12, 13, 14, 15};
int front = 0, rear = 4;

int isfull();
int isempty();
void insert();
int delete();
void display();
int peek();

int main(int argc, char const *argv[])
{
    display();

    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Peek\n5. Exit\n");
        int choice, item;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            insert(item);
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}

void insert(int item)
{
    if (isfull())
    {
        printf("Queue is full\n");
        return;
    }
    if (front == -1)
        front = 0;
    if (rear == MAX - 1)
        rear = 0;
    else
        rear++;
    queue[rear] = item;
}

int delete()
{
    if (isempty())
    {
        printf("Queue is empty\n");
        return;
    }
    int item = queue[front];
    if (front == rear)
        front = rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else
        front++;
    return item;
}

void display()
{
    if (isempty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else
    {
        for (int i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}

int isfull()
{
    if (front == 0 && rear == MAX - 1)
        return 1;
    if (front == rear + 1)
        return 1;
    return 0;
}

int isempty()
{
    if (front == -1)
        return 1;
    return 0;
}

int peek()
{
    if (isempty())
    {
        printf("Queue is empty\n");
        return;
    }
    int item = queue[front];
    printf("Peeked item: %d\n", item);
    return item;
}

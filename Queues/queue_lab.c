#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int isEmpty(int front, int rear)
{
    if (front == -1)
        return 1;
    return 0;
}

int isFull(int rear)
{
    if (rear == MAX - 1)
        return 1;
    return 0;
}

void insert(int queue[], int *front, int *rear, int item)
{
    if (isFull(*rear))
    {
        printf("Q' overflow\n");
        return;
    }
    if (*front == -1)
    {
        (*front)++;
        (*rear)++;
        queue[*rear] = item;
        return;
    }
    queue[++(*rear)] = item;
}

int delete (int queue[], int *front, int rear)
{
    if (isEmpty(*front, rear))
    {
        printf("Q underflow");
        exit(1);
    }
    return queue[(*front)++];
}

int peek(int queue[], int front, int rear)
{
    if (isEmpty(front, rear))
    {
        printf("Q underflow");
        exit(1);
    }
    return queue[front];
}

void display(int queue[], int front, int rear)
{
    if (isEmpty(front, rear))
    {
        printf("Q underflow\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d, ", queue[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int queue[MAX], front = -1, rear = -1, choice, item;
    while (1)
    {
        printf("Choose\n1.Insert\n2.Delete\n3.Peek\n4.Display\n5.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter item: ");
            scanf("%d", &item);
            insert(queue, &front, &rear, item);
            break;
        case 2:
            printf("%d was deleted\n", delete (queue, &front, rear));
            break;
        case 3:
            printf("%d is int he front of the stack\n", peek(queue, front, rear));
            break;
        case 4:
            display(queue, front, rear);
            break;
        case 5:
            exit(1);
        default:
            printf("INVALID OPTION\n");
        }
    }

    return 0;
}

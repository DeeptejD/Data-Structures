#include <stdio.h>
#include<stdlib.h>
#define MAX 20
int queue[MAX], rear = -1, front = -1;

void insert(int);
int del();
int peek();
void display();
int isFull();
int isEmpty();

int main(int argc, char const *argv[])
{
    int choice, item;
    while (1)
    {
        printf("Enter choice\n1.1.insert\n2.delete\n3.peek\n4.display\n5.quit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter: ");
            scanf("%d", &item);
            insert(item);
            break;

        case 2:
            item = del();
            printf("%d removed from the queue\n", item);
            break;

        case 3:
            printf("%d is in front of the queue\n", peek());
            break;

        case 4:
            display();
            break;

        case 5:
            exit(1);

        default:
            printf("inavlid\n");
        }
    }
    return 0;
}

void insert(int item)
{
    if (isFull())
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front++;
    rear += 1;
    queue[rear] = item;
}

int del()
{
    if (isEmpty())
    {
        printf("Queue underflow\n");
        exit(1);
    }
    int item = queue[front];
    front++;
    return item;
}

int isFull()
{
    if (rear == MAX - 1)
        return 1;
    return 0;
}

int isEmpty()
{
    if (front == -1 || front == rear + 1)
        return 1;
    return 0;
}

void display()
{
    if(isEmpty())
    {
        printf("Queue underflow\n");
        return;
    }
    printf("Queue is: ");
    for(int i=front;i<=rear;i++)
        printf("%d, ", queue[i]);
}

int peek()
{
    if(isEmpty())
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return queue[front];
}

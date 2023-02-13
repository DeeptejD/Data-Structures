#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
} *top = NULL;

void push(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Stack overflow\n");
        return;
    }
    temp->info = item;
    temp->next = top, top = temp;
}

int pop()
{
    struct node *temp;
    if (top == NULL)
    {
        printf("under\n");
        exit(1);
    }
    int item = top->info;
    temp = top;
    top = top->next;
    free(temp);
    return item;
}

void display()
{
    if (top == NULL)
        printf("Empty\n");
    else
    {
        struct node *ptr = top;
        while (ptr != NULL)
        {
            printf("%d ", ptr->info);
            ptr = ptr->next;
        }
    }
}

int main(int argc, char const *argv[])
{
    push(5);
    push(4);
    push(3);
    push(2);
    display();
    pop();
    pop();
    pop();
    display();
    return 0;
}

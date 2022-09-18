#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
}*top=NULL;

void push(int);
int pop();
int peek();
int isEmpty();
void display();
int main(int argc, char const *argv[])
{
    int item, choice;
    while(1)
    {
        printf("1.Push\n2.pop\n3.peek\n4.disaplay\n5.exit\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            printf("Enter item: ");
            scanf("%d", &item);
            push(item);
            break;
        
        case 2:
            printf("%d popped from the stack\n", pop());
            break;
        
        case 3:
            printf("%d at the top of the stack\n", peek());
            break;
        
        case 4:
            display();
            break;
        
        case 5:
            exit(1);
        
        default:
            printf("invalid\n");
    }
    }
    return 0;
}

void push(int item)
{
    struct node *tmp;
    if((tmp=malloc(sizeof(struct node)))==NULL)
    {
        printf("Stack overflow\n");
        return;
    }
    tmp->info=item;
    tmp->link=top;
    top=tmp;
}

int pop()
{
    if(isEmpty())
    {
        printf("Stack underflow\n");
        exit(1);
    }

    struct node *tmp=top;
    int item=tmp->info;
    top=top->link;
    free(tmp);
    return item;
}

int peek()
{
    if(isEmpty())
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return top->info;
}

int isEmpty()
{
    if(top==NULL)
        return 1;
    return 0;
}

void display()
{
    struct node *p=top;
    if(isEmpty())
    {
        printf("Stack underflow\n");
        exit(1);
    }

    while(p!=NULL)
    {
        printf("%2d", p->info);
        p=p->link;
    }
}

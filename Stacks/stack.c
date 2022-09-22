#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int stack[MAX], top=-1;

void push(int);
void pop();
void peek();
void display();
int isEmpty();
int isFull();
int takeInput();
int main(int argc, char const *argv[])
{
    while(1){
        int choice;
        printf("Stack Operations\nEnter th number corresponding to the choice\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Quit\n");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
            {
                push(takeInput());
                break;
            }
            case 2:
                pop();
                break;
            
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            
            case 5:
                exit(1);
                break;
            default:
                printf("Invalid option\n");

        }
    }
    return 0;
}

int isEmpty()
{
    if (top==-1)
        return 1;
    return 0;
}

int isFull()
{
    if (top==MAX-1)
        return 1;
    return 0;
}

void push(int item){
    if(isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=item;
    printf("Push sucessfull\n");
}
void pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d was popped out of the stack!\n", stack[top]);
    top--;
}

void peek()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Item at top of the stack is: %d\n", stack[top]);
}

void display()
{
    if(isEmpty()){
        printf("Stack underflow\n");
        return;
    }
    for(int i=top;i>=0;i--)
    {
        printf("%2d", stack[top]);
    }
}

int takeInput()
{
    int n;
    printf("Enter the number to be pushed: ");
    scanf("%d", &n);
    return n;
}

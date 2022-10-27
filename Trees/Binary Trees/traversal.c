#include <stdio.h>

struct node
{
    struct node *LC; // Left Child
    int info;
    struct node *RC; // Right Child
} *root = NULL;

// recursive traversals START

void preorder(struct node *ptr)
{
    if (ptr == NULL)
        return; // base case
    printf("%3d", ptr->info);
    preorder(ptr->LC);
    preorder(ptr->RC);
}

void inorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    inorder(ptr->LC);
    printf("%3d", ptr->info);
    inorder(ptr->RC);
}

void postorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    postorder(ptr->LC);
    postorder(ptr->RC);
    printf("%3d", ptr->info);
}

// recursive traversals END

// NON recursive traversals START
// points: we have to use an explicit stack
#define MAX 100
struct node *stack[MAX];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == MAX - 1;
}

void push(struct node *item)
{
    if (isFull())
    {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = item;
}

struct node *pop()
{
    if (isEmpty())
    {
        printf("Stack underflow\n");
        return;
    }
    struct node *item = stack[top--];
    return item;
}

// PREORDER
void nrec_pre(struct node *root)
{
    struct node *ptr = root;
    if (root == NULL)
    {
        printf("The tree is empty\n");
        return;
    }
    push(ptr);
    while (!isEmpty())
    {
        ptr = pop();
        printf("%3d", ptr->info);
        if (ptr->LC != NULL)
            push(ptr->LC);
        if (ptr->RC != NULL)
            push(ptr->RC);
    }
}

void nrec_in(struct node *root)
{
    if (root == NULL)
    {
        printf("The tree is empty\n");
        return;
    }
    struct node *ptr = root;
    while (1)
    {
        while(ptr->LC!=NULL)
        {
            push(ptr);
            ptr=ptr->LC;
        }
        while(ptr->RC==NULL)
        {
            printf("%3d", ptr->info);
            if(isEmpty())
                return;
            ptr=pop();
        }
        printf("%3d", ptr->info);
        ptr=ptr->RC;
    }
}
// NON recursive traversals END

int main(int argc, char const *argv[])
{

    return 0;
}

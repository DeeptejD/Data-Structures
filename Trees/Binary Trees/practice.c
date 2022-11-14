#include <stdio.h>
#define MAX 100

struct node
{
    int data;
    struct node *l, *r;
};

struct node *stack[MAX];
int top = -1;

void push(struct node *ptr)
{
    if (top == MAX - 1)
    {
        printf("Overflow\n");
        exit(1);
    }
    stack[++top] = ptr;
}

struct node *pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
        exit(1);
    }
    struct node *temp = stack[top--];
    return temp;
}

int isempty()
{
    return top == -1;
}

void preorder(struct node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    struct node *ptr = root;
    push(ptr);
    while (!isempty())
    {
        ptr = pop();
        printf("%3d", ptr->data);
        if (ptr->r != NULL)
            push(ptr->r);
        if (ptr->l != NULL)
            push(ptr->l);
    }
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        printf("The tree isempty\n");
        exit(1);
    }
    struct node *ptr = root;
    while (1)
    {
        while (ptr->l != NULL)
        {
            push(ptr);
            ptr = ptr->l;
        }
        while (ptr->r == NULL)
        {
            printf("%3d", ptr->data);
            if (isempty())
                return;
            ptr = pop();
        }
        printf("%3d", ptr->data);
        ptr = ptr->r;
    }
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        printf("The tree is empty\n");
        exit(1);
    }
    struct node *ptr = root, *q = root;
    while (1)
    {
        while (ptr->l != NULL)
        {
            push(ptr);
            ptr = ptr->l;
        }
        while (ptr->r == NULL || ptr->r == q)
        {
            printf("%3d", ptr->data);
            q = ptr;
            if (isempty())
                return;
            ptr = pop();
        }
        push(ptr);
        ptr = ptr->r;
    }
    printf("\n");
}

struct node *queue[MAX];
int front = -1, rear = -1;

int fullQ()
{
    return (rear == MAX - 1);
}

int emptyQ()
{
    return (front == rear + 1 || rear == -1);
}

void enqueue(struct node *ptr)
{
    if (fullQ())
    {
        printf("Q oveflow\n");
        exit(1);
    }
    if (front == -1)
        front++;
    queue[++rear] = ptr;
}

struct node *dequeue()
{
    if (emptyQ())
    {
        printf("Q underflow\n");
        exit(1);
    }
    struct node *temp = queue[front++];
    return temp;
}

void levelorder(struct node *root)
{
    if (root == NULL)
    {
        printf("Empty tree\n");
        exit(1);
    }
    struct node *ptr = root;
    enqueue(ptr);
    while (!emptyQ())
    {
        ptr = dequeue();
        printf("%3d", ptr->data);
        if (ptr->l != NULL)
            enqueue(ptr->l);
        if (ptr->r != NULL)
            enqueue(ptr->r);
    }
    printf("\n");
}

struct listnode
{
    int info;
    struct listnode *next;
};

struct node *fromPREIN(struct listnode *preptr, struct listnode *inptr, int num)
{
    if (num == 0)
        return NULL;
    struct node *temp;
    if ((temp = (struct node *)malloc(sizeof(struct node))) == NULL)
    {
        printf("No memory\n");
        exit(1);
    }
    temp->data = preptr->info;
    temp->r = NULL, temp->l = NULL;
    if (num == 1)
        return temp;
    struct listnode *q = inptr;
    int i, j;
    for (i = 0; q->info != preptr->info; i++)
        q = q->next;
    temp->l = fromPREIN(preptr->next, inptr, i);
    for (j = 0; j <= i; j++)
        preptr = preptr->next;
    temp->r = fromPREIN(preptr, q->next, num - i - 1);
    return temp;
}

struct node *fromPOSTIN(struct listnode *inptr, struct listnode *postptr, int num)
{
    int i, j;
    if (num == 0)
        return NULL;
    struct node *temp;
    struct listnode *ptr = postptr;
    for (i = 1; i < num; i++)
        ptr = ptr->next;
    if ((temp = (struct node *)malloc(sizeof(struct node))) == NULL)
    {
        printf("no memory\n");
        exit(1);
    }
    temp->data = ptr->info;
    temp->l = NULL;
    temp->r = NULL;
    if (num == 1)
        return temp;
    struct listnode *q = inptr;
    int i, j;
    for (i = 0; q->info != ptr->info; i++)
        q = q->next;
    temp->l = fromPOSTIN(inptr, postptr, i);
    for (int j = 1; j <= i; j++)
        postptr = postptr->next;
    temp->r = fromPOSTIN(q->next, postptr, num - i - 1);
    return temp;
}

int height(struct node *ptr)
{
    if (ptr == NULL)
        return 0;
    int hl, hr;
    hl = height(ptr->l);
    hr = height(ptr->r);
    if (hl > hr)
        return 1 + hl;
    return 1 + hr;
}

int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    return 0;
}

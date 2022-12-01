#include <stdio.h>

struct node
{
    struct node *left, *right;
    int info;
};

void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%3d", root->info);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%3d", root->info);
    inorder(root->right);
}

void postorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    postorder(ptr->left);
    postorder(ptr->right);
    printf("%3d", ptr->info);
}

#define MAX 100
struct node *stack[MAX];
int top = -1;
int isempty()
{
    return (top == -1);
}

void push(struct node *ptr)
{
    if (top == MAX - 1)
        return;
    stack[++top] = ptr;
}

struct node *pop()
{
    if (isempty())
        exit(1);
    struct node *temp = stack[top--];
    return temp;
}

void nrec_pre(struct node *root)
{
    if (root == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct node *ptr = root;
    push(ptr);
    while (!isempty())
    {
        struct node *temp = pop();
        printf("%3d", temp->info);
        if (temp->right != NULL)
            push(temp->right);
        if (temp->left != NULL)
            push(temp->left);
    }
    printf("\n");
}

void nrec_inorder(struct node *root)
{
    if (root == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct node *ptr = root, *temp;
    while (1)
    {
        while (ptr->left != NULL)
        {
            push(push);
            ptr = ptr->left;
        }
        while (ptr->right == NULL)
        {
            printf("%3d", ptr->info);
            if (!isempty())
                temp = pop();
        }
        printf("%3d", ptr->info);
        ptr = ptr->right;
    }
    printf("\n");
}

void nrec_postorder(struct node *root)
{
    if (root == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct node *ptr = root, *q = root;
    while (1)
    {
        while (ptr->left != NULL)
        {
            push(ptr);
            ptr = ptr->left;
        }
        while (ptr->right == NULL || ptr->right == q)
        {
            printf("%3d", ptr->info);
            q = ptr;
            if (isempty())
                return;
            else
                ptr = pop();
        }
        push(ptr);
        ptr = ptr->right;
    }
    printf("\n");
}

struct node *queue[MAX];
int front = -1, rear = -1;

void insert(struct node *ptr)
{
    if (rear == MAX - 1)
    {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = ptr;
}

struct node *del()
{
    if (front == -1 || front == rear + 1)
    {
        printf("Q underflow\n");
        exit(1);
    }
    struct node *temp = queue[front++];
    return temp;
}

int Qempty()
{
    return (front == -1 || front == rear + 1);
}

void levelorder(struct node *root)
{
    if (root == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct node *ptr = root;
    insert(ptr);
    while (!Qempty())
    {
        ptr = del();
        printf("%3d", ptr = ptr->right);
        if (ptr->left != NULL)
            insert(ptr->left);
        if (ptr->right != NULL)
            insert(ptr->right);
    }
    printf("\n");
}

struct listnode
{
    struct listnode *next;
    int info;
};

struct node *inpreconstruct(struct listnode *inorder, struct listnode *preptr, int num)
{
    if (num == 0)
        return NULL;
    struct node *temp;
    if (temp = (struct node *)malloc(sizeof(struct node)) == NULL)
    {
        printf("NO MEM\n");
        exit(1);
    }
    temp->info = preptr->info;
    temp->left = NULL, temp->right = NULL;
    if (num == 1)
        return temp;
    int i, j;
    struct listnode *q = inorder;
    for (i = 0; q->info != preptr->info; i++)
        q = q->next;
    temp->left = inpreconstruct(inorder, preptr->next, i);
    for (j = 1; j <= i + 1; j++)
        preptr = preptr->next;
    temp->right = inpreconstruct(q->next, preptr, num - i - 1);
    return temp;
}

struct node *inpostconstruct(struct listnode *inptr, struct listnode *postptr, int num)
{
    if (num == 0)
        return NULL;
    struct node *temp;
    struct listnode *ptr = postptr;
    int i;
    for (i = 1; i < num; i++)
        ptr = ptr->next;
    if ((temp = (struct node *)malloc(sizeof(struct node))) == NULL)
    {
        printf("NO MEM\n");
        exit(1);
    }
    temp->info = ptr->info;
    temp->left = NULL, temp->right = NULL;
    if (num == 1)
        return temp;
    struct listnode *q = inptr;
    for (i = 0; q->info != ptr->info; i++)
        q = q->next;
    temp->left = inpostconstruct(inptr, postptr, i);
    for (int j = 1; j <= i; i++)
        postptr = postptr->next;
    temp->right = (q->next, postptr, num - i - 1);
    return temp;
}

int height(struct node *root)
{
    int h_left, h_right;
    if (root == NULL)
        return 0;
    h_left = height(root->left);
    h_right = height(root->right);
    if (h_left > h_right)
        return 1 + h_left;
    else
        return 1 + h_right;
}

int main(int argc, char const *argv[])
{

    return 0;
}

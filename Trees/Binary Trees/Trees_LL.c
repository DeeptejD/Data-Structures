// *****************//
// Preorder : NLR   //
// Postorder: LRN   //
// Inorder  : LNR   //
// Level Order      //
// *****************//

#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct node
{
    struct node *lchild;
    char data;
    struct node *rchild;
};

struct node *root;

// Recursive Traversals

// PREORDER
void preorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    printf("%3c", ptr->data);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}

// POSTORDER
void postorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%3c", ptr->data);
}

// INORDER
void inorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    inorder(ptr->lchild);
    printf("%3c", ptr->data);
    inorder(ptr->rchild);
}

// Recursive Traversals End ---

// Non-Recursive Traversals Start---

#define MAX 100          // max for explicit stack
struct node *stack[MAX]; // Explicit Stack
int top = -1;

// PUSH FUNCTION FOR EXPLICIT STACK
void *push(struct node *node)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = node;
}

// POP FUNCTION FOR EXPLICIT STACK
struct node *pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct node *temp = stack[top--];
    return temp;
}

// NON RECURSIVE PREORDER
void nrec_preorder(struct node *root)
{
    struct node *ptr = root;
    if (root == NULL)
    {
        printf("The tree is empty\n");
        return;
    }
    push(ptr);
    while (top != NULL)
    {
        ptr = pop();
        printf("%3c", ptr->data);
        push(ptr->rchild);
        push(ptr->lchild);
    }
    printf("\n");
}

// NON-RECURSIVE INORDER
void nrec_inorder(struct node *root)
{
    if (root == NULL)
    {
        printf("The tree is empty\n");
        return;
    }
    struct node *ptr = root;
    while (1)
    {
        while (ptr->lchild != NULL)
        {
            push(ptr);
            ptr = ptr->lchild;
        }
        while (ptr->rchild == NULL) // Watch out for the equal to condition
        {
            printf("%3c", ptr->data); // visiting the popped node
            // check if stack is empty
            if (top == -1)
                return;  // RETURN STMT
            ptr = pop(); // POP next node
        }
        printf("%3c", ptr->data); // Visit popped node
        ptr = ptr->rchild;        // Go to Right child
    }
    printf("\n");
}

// NON RECURSIVE POSTORDER
void nrec_post(struct node *root)
{
    if (root == NULL)
    {
        printf("The tree is empty\n");
        return;
    }
    struct node *ptr = root, *p = root;
    while (1)
    {
        while (ptr->lchild != NULL)
        {
            push(ptr->lchild); // push left child
            ptr = ptr->lchild; // move left
        }
        while (ptr->rchild == NULL || ptr->rchild == p /*checks if the right child has been traversed*/)
        {
            printf("%3c", ptr->data); // visit popped node
            p = ptr;                  // keep track of traversed node
            if (top == -1)            // check if stack is empty
                return;
            ptr = pop(); // pop next node in the stack
        }
        push(ptr);         // push popped node back in the stack
        ptr = ptr->rchild; // move right
    }
    printf("\n");
}

// Non-Recursive Traversals End---

// Level Order Traversal---

struct node *queue[MAX];
int front = -1, rear = -1;

void insert(struct node *ptr)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) // initial state
        front = 0;
    queue[++rear] = ptr;
}

struct node *del()
{
    if (front == -1 || front == rear + 1)
    {
        printf("Queue underflow\n");
        exit(EXIT_FAILURE);
    }
    struct node *item = queue[front++];
    return item;
}

int Q_empty()
{
    return (front == -1 || front == rear + 1);
}

void level_order(struct node *root)
{
    if (root == NULL)
    {
        printf("Tree is Empty\n");
        return;
    }
    struct node *ptr = root;
    insert(ptr);
    while (!Q_empty())
    {
        ptr = del();
        printf("%3c", ptr->data);
        if (ptr->lchild != NULL)
            insert(ptr->lchild);
        if (ptr->rchild != NULL)
            insert(ptr->rchild);
    }
    printf("\n");
}

// Level Order Traversal End---

int main(int argc, char const *argv[])
{
    return 0;
}

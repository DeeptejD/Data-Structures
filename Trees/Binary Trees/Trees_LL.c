// *****************//
// Preorder : NLR   //
// Postorder: LRN   //
// Inorder  : LNR   //
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
void *preorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    printf("%3c", ptr->data);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}

// POSTORDER
void *postorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%3c", ptr->data);
}

// INORDER
void *inorder(struct node *ptr)
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

// Non-Recursive Traversals End---

int main(int argc, char const *argv[])
{
    return 0;
}

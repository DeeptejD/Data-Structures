#include <stdio.h>
#include <stdlib.h>

struct listnode
{
    int info;
    struct listnode *next;
};

struct treenode
{
    int info;
    struct node *left, *right;
};

struct treenode *inpre(struct listnode *inptr, struct listnode *preptr, int num)
{
    if (num == 0)
        return NULL;
    struct treenode *temp = (struct treenode *)malloc(sizeof(struct treenode));
    struct listnode *p = inptr;
    // make first node it will have the value of preptr
    temp->info = preptr->info, temp->left = temp->right = NULL;
    if (num == 1)
        return temp;
    int i;
    for (i = 0; p->info != preptr->info; i++)
        p = p->next;
    // now i is the number of nodes in the left subtree
    temp->left = inpre(inptr, preptr->next, i);
    int j;
    for (j = 1; j <= i; j++)
        preptr = preptr->next;
    temp->right = inpre(p->next, preptr, num - i - 1);
    return temp;
}

struct treenode *inpost(struct listnode *inptr, struct listnode *postptr, int num)
{
    if (num == 0)
        return NULL;
    struct treenode *temp = (struct treenode *)malloc(sizeof(struct treenode));
    struct listnode *ptr = postptr, *q = inptr;
    for (int i = 1; i < num; i++)
        ptr = ptr->next;
    temp->info = ptr->info, temp->left = temp->right = NULL;
    if (num == 1)
        return temp;
    int i, j;
    for (i = 0; q->info != ptr->info; i++)
        q = q->next;
    // now i is the number of nodes in the left subtree
    temp->left = inpost(inptr, postptr, i);
    for (j = 1; j <= i; j++)
        postptr = postptr->next;
    temp->right = inpost(q->next, postptr, num - i - 1);
    return temp;
}

int height(struct treenode *root)
{
    if (root == NULL)
        return 0;
    int hl, hr;
    hl = height(root->left);
    hr = height(root->right);
    return (hl > hr ? hl : hr);
}

int depth(struct treenode *root, int u)
{
    if (root == NULL)
        return 0;
    int d = 0;
    if (root->info == u || (d = depth(root->left, u)) > 0 || (d = depth(root->right, u)) > 0)
        return d + 1;
}

#define MAX 100
int front = -1, rear = -1;
struct treenode *queue[MAX];

void ins(struct treenode *ptr)
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

int qempty()
{
    return (front == -1 || front == rear + 1);
}

struct treenode *del()
{
    if (qempty())
    {
        printf("Queue underflow\n");
        return NULL;
    }
    return queue[front++];
}

void level(struct treenode *root)
{
    if (root == NULL)
    {
        printf("Empty\n");
        return;
    }
    insert(root);
    while (!qempty())
    {
        struct treenode *temp = del();
        printf("%d ", temp->info);
        if (temp->left != NULL)
            ins(temp->left);
        if (temp->right != NULL)
            ins(temp->right);
    }
}

void ltr(struct treenode *root, int level)
{
    // if root is not equal to NULL
    if (root != NULL)
    {
        if (level == 1)
            printf("%d ", root->info);
        else if (level > 1)
        {
            ltr(root->left, level - 1);
            ltr(root->right, level - 1);
        }
    }
}

void rtl(struct treenode *root, int level)
{
    if (root != NULL)
    {
        if (level == 1)
            printf("%d ", root->info);
        else if (level > 1)
        {
            rtl(root->right, level - 1);
            rtl(root->left, level - 1);
        }
    }
}

void spiral(struct treenode *root)
{
    // based on the heights, first we get the total height and then for all odd heights we call ltr and rtl for even height
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        if (i % 2 != 0) // odd
            ltr(root, i);
        else
            rtl(root, i);
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}

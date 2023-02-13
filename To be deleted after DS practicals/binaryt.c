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
    struct treenode *left, *right;
};

struct listnode *create(int info)
{
    struct listnode *start;
    start = (struct listnode *)malloc(sizeof(struct listnode));
    start->info = info, start->next = NULL;
    return start;
}

struct listnode *addatend(struct listnode *start, int info)
{
    struct listnode *ptr = start, *temp = (struct listnode *)malloc(sizeof(struct listnode));
    while (ptr->next != NULL)
        ptr = ptr->next;
    temp->info = info, temp->next = NULL;
    ptr->next = temp;
    return start;
}

void displaylist(struct listnode *start)
{
    struct listnode *ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
}

struct treenode *construct_inpost(struct listnode *inptr, struct listnode *postptr, int num)
{
    struct listnode *ptr = postptr, *q = inptr;
    struct treenode *temp;
    if (num == 0)
        return NULL;
    for (int i = 1; i < num; i++)
        ptr = ptr->next;
    temp = (struct treenode *)malloc(sizeof(struct treenode));
    temp->info = ptr->info, temp->left = temp->right = NULL;
    if (num == 1)
        return temp;
    int i, j;
    for (i = 0; q->info != ptr->info; i++)
        q = q->next;
    temp->left = construct_inpost(inptr, postptr, i);
    for (j = 1; j <= 1; j++)
        postptr = postptr->next;
    temp->right = construct_inpost(q->next, postptr, num - i - 1);
    return temp;
}

void showpre(struct treenode *ptr)
{
    if (ptr == NULL)
        return;
    printf("%d ", ptr->info);
    showpre(ptr->left);
    showpre(ptr->right);
}

struct treenode *construct_inpre(struct listnode *inptr, struct listnode *preptr, int num)
{
    struct treenode *temp;
    struct listnode *q = inptr;
    if (num == 0)
        return NULL;
    temp = (struct treenode *)malloc(sizeof(struct treenode));
    temp->info = preptr->info, temp->left = temp->right = NULL;
    if (num == 1)
        return temp;
    int i;
    for (i = 0; q->info != preptr->info; i++)
        q = q->next;
    // now i is the number of nodes in the left subtree and q points to the root in the inorder list
    temp->left = construct_inpre(inptr, preptr->next, i);
    int j;
    for (j = 1; j <= i + 1; j++)
        preptr = preptr->next;
    temp->right = construct_inpre(q->next, preptr, num - i - 1);
    return temp;
}

void showpost(struct treenode *ptr)
{
    if (ptr == NULL)
        return;
    showpost(ptr->left);
    showpost(ptr->right);
    printf("%d ", ptr->info);
}

int height(struct treenode *root)
{
    if (root == NULL)
        return 0;
    int hl, hr;
    hl = height(root->left);
    hr = height(root->right);
    return hl > hr ? hl + 1 : hr + 1;
}

int depth(struct treenode *root, int key)
{
    if (root == NULL)
        return 0;
    int d = 0;
    if (root->info == key || (d = depth(root->left, key)) > 0 || (d = depth(root->right, key)) > 0)
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
    ins(root);
    while (!qempty())
    {
        struct treenode *temp = del();
        printf("%d ", temp->info);
        if (temp->left != NULL)
            ins(temp->left);
        if (temp->right != NULL)
            ins(temp->right);
    }
    printf("\n");
}

void ltr(struct treenode *root, int level)
{
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
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        if (i % 2 == 0)
            rtl(root, i);
        else
            ltr(root, i);
    }
}

int main(int argc, char const *argv[])
{
    struct listnode *inorder, *preorder, *postorder;
    int in[7] = {4, 2, 6, 5, 7, 1, 3};
    int pre[7] = {1, 2, 4, 5, 6, 7, 3};
    int post[7] = {4, 6, 7, 5, 2, 3, 1};

    inorder = create(in[0]);
    preorder = create(pre[0]);
    postorder = create(post[0]);
    for (int i = 1; i < 7; i++)
    {
        // inorder
        inorder = addatend(inorder, in[i]);
    }
    for (int i = 1; i < 7; i++)
    {
        // preorder
        preorder = addatend(preorder, pre[i]);
    }
    for (int i = 1; i < 7; i++)
    {
        // postorder
        postorder = addatend(postorder, post[i]);
    }
    printf("Inorder: ");
    displaylist(inorder);
    printf("Preorder: ");
    displaylist(preorder);
    printf("Postorder: ");
    displaylist(postorder);
    struct treenode *start;
    printf("\n");
    start = construct_inpost(inorder, postorder, 7);
    showpre(start);
    struct treenode *start2 = construct_inpre(inorder, preorder, 7);
    printf("\n");
    showpost(start2);
    printf("Height of the tree is: %d\nDepth of node 5 is: %d\nDepth of ndoe 100 is %d\n", height(start2), depth(start2, 5), depth(start2, 100));
    printf("\nLevel order traversal: ");
    level(start2);
    printf("Spiral Order Traversal: ");
    spiral(start2);
    printf("\n");
    return 0;
}

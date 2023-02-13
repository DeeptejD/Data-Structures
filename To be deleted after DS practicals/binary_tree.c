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

struct listnode *addtoempty(struct listnode *start, int data)
{
    start = NULL;
    struct listnode *temp;
    if ((temp = (struct listnode *)malloc(sizeof(struct listnode))) == NULL)
    {
        printf("Not enough memory\n");
        return NULL;
    }
    temp->info = data, temp->next = NULL, start = temp;
    return start;
}

struct listnode *addatend(struct listnode *start, int data)
{
    struct listnode *temp;
    if ((temp = (struct listnode *)malloc(sizeof(struct listnode))) == NULL)
    {
        printf("Not enough memory\n");
        return start;
    }
    struct listnode *ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    temp->info = data, temp->next = NULL, ptr->next = temp;
    return start;
}

struct listnode *create(struct listnode *start, int num)
{
    if (!num)
        return 0;
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);
    start = addtoempty(start, data);
    while (--num)
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        start = addatend(start, data);
    }
    return start;
}

void display(struct listnode *start)
{
    struct listnode *ptr = start;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->info);
        ptr = ptr->next;
    }
}

struct treenode *postConstruct(struct listnode *inorder, struct listnode *postorder, int num)
{
    if (!num)
        return NULL;
    struct listnode *ptr = postorder;
    for (int i = 1; i < num; i++)
        ptr = ptr->next;
    struct treenode *temp;
    if ((temp = (struct treenode *)malloc(sizeof(struct treenode))) == NULL)
    {
        printf("Not enough memory\n");
        return NULL;
    }
    temp->info = ptr->info, temp->left = temp->right = NULL;
    if (num == 1)
        return temp;
    int i, j;
    struct listnode *q = inorder;
    for (i = 0; q->info != ptr->info; i++)
        q = q->next;
    temp->left = postConstruct(inorder, postorder, i);
    for (j = 1; j <= i; j++)
        postorder = postorder->next;
    temp->right = postConstruct(q->next, postorder, num - i - 1);
    return temp;
}

void intrav(struct treenode *ptr)
{
    if (ptr == NULL)
        return;
    intrav(ptr->left);
    printf("%3d", ptr->info);
    intrav(ptr->right);
}

void pretrav(struct treenode *root)
{
    if (root == NULL)
        return;
    printf("%3d", root->info);
    pretrav(root->left);
    pretrav(root->right);
}

void posttrav(struct treenode *root)
{
    if (root == NULL)
        return;
    posttrav(root->left);
    posttrav(root->right);
    printf("%3d", root->info);
}

int findheight(struct treenode *root)
{
    int left, right;
    if (root == NULL)
        return 0;
    left = findheight(root->left);
    right = findheight(root->right);
    if (left > right)
        return left + 1;
    return right + 1;
}

int finddepth(struct treenode *root, int x)
{
    if (root == NULL)
        return -1;
    int depth = -1;
    if (root->info == x || (depth = finddepth(root->left, x)) >= 0 || (depth = finddepth(root->right, x) >= 0))
        return depth + 1;
}

void treeDisplay(struct treenode *root)
{
    printf("The inorder traversal for the tree is: ");
    intrav(root);
    printf("\n");
    printf("The preorder traversal for the tree is: ");
    pretrav(root);
    printf("\n");
    printf("The postorder traversal for the tree is: ");
    posttrav(root);
    printf("\n");
}

#define MAX 100

struct treenode *queue[MAX];
int front = -1, rear = -1;

void insert(struct treenode *ptr)
{
    if (rear == MAX - 1)
    {
        printf("Q overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = ptr;
}

struct treenode *delete()
{
    if (front == -1)
    {
        printf("Q underflow\n");
        return NULL;
    }
    return queue[front++];
}

int isqempty()
{
    return (front == -1 || front == rear + 1);
}

void levelOrder(struct treenode *root)
{
    if (root == NULL)
    {
        printf("The tree is empty\n");
        return;
    }
    insert(root);
    printf("The level order traversal for the tree is\n");
    while (!isqempty())
    {
        struct treenode *temp = delete ();
        printf("%d ", temp->info);
        if (temp->left != NULL)
            insert(temp->left);
        if (temp->right != NULL)
            insert(temp->right);
    }
}

void ltr(struct treenode *root, int i)
{
    if (root != NULL)
    {
        if (i == 1)
            printf("%3d", root->info);
        else
        {
            ltr(root->left, i - 1);
            ltr(root->right, i - 1);
        }
    }
}

void rtl(struct treenode *root, int i)
{
    if (root != NULL)
    {
        if (i == 1)
            printf("%3d", root->info);
        else
        {
            rtl(root->right, i - 1);
            rtl(root->left, i - 1);
        }
    }
}

void spiral_order(struct treenode *root)
{
    if (root == NULL)
    {
        printf("The tree is empty you borzo\n");
        return;
    }
    printf("The Spiral order traversal for the tree is: ");
    int h = findheight(root);
    for (int i = 1; i <= h; i++)
    {
        if (i % 2 == 0) // even
            rtl(root, i);
        else
            ltr(root, i);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int num;
    printf("Enter the number of nodes: ");
    scanf("%d", &num);
    struct listnode *inptr, *postptr;
    printf("Enter the inorder of the tree\n");
    inptr = create(inptr, num);
    printf("Enter the postorder for the tree\n");
    postptr = create(postptr, num);
    printf("Constructing the tree...\n");
    struct treenode *root = postConstruct(inptr, postptr, num);
    printf("The tree has been constructed!\n");
    treeDisplay(root);
    printf("The height of the tree is: %d\n", findheight(root));
    int x;
    printf("Enter the node whose depth you need to find: ");
    scanf("%d", &x);
    if (finddepth(root, x) > 0)
        printf("The depth of the node %d is: %d\n", x, finddepth(root, x));
    else
        printf("The node %d is not present in the tree\n", x);
    levelOrder(root);
    spiral_order(root);
    return 0;
}

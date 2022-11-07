// ******************************************************************
// DACP to construct a binary tree given postorder and inorder
// provide the foll options
// 1. To find height
// 2. To find the depth of a given node
// 3. To perform level order traversal
// 4. Spiral Traversal
// ******************************************************************

#include <stdio.h>
#include <stdlib.h>

struct treenode
{
    struct treenode *lchild;
    int info;
    struct treenode *rchild;
};

struct listnode
{
    int info;
    struct listnode *next;
};

struct listnode *addatbeg(struct listnode *start, int data)
{
    struct listnode *temp;
    if ((temp = (struct listnode *)malloc(sizeof(struct listnode))) == NULL)
    {
        printf("No memory\n");
        exit(EXIT_FAILURE);
    }
    temp->info = data;
    temp->next = NULL;
    start = temp;
    return start;
}

struct listnode *addatend(struct listnode *start, int data)
{
    struct listnode *temp, *ptr = start;
    if ((temp = (struct listnode *)malloc(sizeof(struct listnode))) == NULL)
    {
        printf("No memory\n");
        exit(EXIT_FAILURE);
    }
    temp->info = data;
    while (ptr->next != NULL)
        ptr = ptr->next;
    temp->next = ptr->next;
    ptr->next = temp;
    return start;
}

struct listnode *create(struct listnode *start, int num)
{
    int data;
    printf("Enter the data to be inserted: ");
    scanf("%d", &data);
    start = addatbeg(start, data);
    for (int i = 2; i <= num; i++)
    {
        printf("Enter the data to be inserted: ");
        scanf("%d", &data);
        start = addatend(start, data);
    }
    return start;
}

struct treenode *construct_in_post(struct listnode *inptr, struct listnode *postptr, int num)
{
    if (num == 0)
        return NULL;
    struct treenode *temp;
    struct listnode *ptr = postptr, *q = inptr;
    for (int i = 1; i < num; i++)
    {
        ptr = ptr->next;
    }
    if ((temp = (struct treenode *)malloc(sizeof(struct treenode))) == NULL)
    {
        printf("Not enough memory\n");
        exit(EXIT_FAILURE);
    }
    temp->info = ptr->info;
    temp->lchild = NULL, temp->rchild = NULL;
    if (num == 1)
        return temp;
    int i, j;
    for (i = 0; q->info != ptr->info; i++)
        q = q->next;
    temp->lchild = construct_in_post(inptr, postptr, i);
    for (j = 1; j <= i; j++)
        postptr = postptr->next;
    temp->rchild = construct_in_post(q->next, postptr, num - i - 1);
    return temp;
}

void preorder(struct treenode *ptr)
{
    if (ptr == NULL)
        return;
    printf("%3d", ptr->info);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}

void display(struct listnode *inorder, struct listnode *postorder, struct treenode *ptr)
{
    printf("\nThe Inorder of the Tree is: ");
    struct listnode *p = inorder;
    while (p != NULL)
    {
        printf("%3d", p->info);
        p = p->next;
    }
    printf("\n");
    p = postorder;
    printf("The Post-order for the tree is: ");
    while (p != NULL)
    {
        printf("%3d", p->info);
        p = p->next;
    }
    printf("\n");
    printf("The preorder traversal for the tree is: ");
    preorder(ptr);
    printf("\n");
}

int height(struct treenode *ptr)
{
    int left, right;
    if (ptr == NULL)
        return 0;
    left = height(ptr->lchild);
    right = height(ptr->rchild);
    if (left > right)
        return left + 1;
    return right + 1;
}

int main(int argc, char const *argv[])
{
    int num;
    struct listnode *inorder = NULL, *postorder = NULL;
    struct treenode *root = NULL;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &num);
    printf("Enter INORDER: ");
    inorder = create(inorder, num);
    printf("Enter POSTORDER: ");
    postorder = create(postorder, num);
    root = construct_in_post(inorder, postorder, num);
    display(inorder, postorder, root);
    while (1)
    {
        printf("Choose from the options below\n1. Find height of the tree\n2. Find the depth of a given node\n3. Perform Level Order Traversal\n4. Perform Spiral Traversal\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("The height of the tree is: %d\n", height(root));
            break;

        default:
            break;
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
};

struct node *root;

// Creation of a Binary Tree from Inorder and Predorder

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

// CONSTRUCT A NODE USING INORDER AND PREORDER
struct treenode *construct(struct listnode *inptr, struct listnode *preptr, int num)
{
    if (num == 0)    // if we have no nodes remaining u=in the list
        return NULL; // return NULL
    struct treenode *temp;
    if ((temp = (struct treenode *)malloc(sizeof(struct treenode))) == NULL)
    {
        printf("No memory\n");
        exit(EXIT_FAILURE);
    }
    temp->info = preptr->info; // Assigns preptr->info to our node
    temp->rchild = NULL;
    temp->lchild = NULL;          // Initially Rchild and Lchild are both NULL
    if (num == 1)                 // if only 1 node is to be created
        return temp;              // we return the only created node
    struct listnode *ptr = inptr; // now we try to search for the node the we just created in the inorder
    int i, j;                     // i will basically hold the number of nodes in the left subtree of the current root node
    for (i = 0; ptr->info != preptr->info; i++)
        ptr = ptr->next; // we move next in the inorder until we find the node that we just created
    // i is now the number of nodes on the left
    temp->lchild = construct(inptr, preptr->next, i); // we send original inorder list, the next node in preorder and the number of nodes on the left subtree

    for (j = 1; j <= i + 1; j++)
        preptr = preptr->next;                                // we move preptr so it only points to the portion that has the preorder of the right subtree
    temp->rchild = construct(ptr->next, preptr, num - i - 1); // we use num-i-1 because we need to exclude all the nodes on the left and the root node
}

//---

int main(int argc, char const *argv[])
{
    return 0;
}

// To implement AVL trees and perform the listed operations on such trees.

#include <stdio.h>
#define TRUE 1
#define FALSE 0
struct node
{
    struct ndoe *left, *right;
    int info, balance;
};

struct node *rightrotate(struct node *pptr)
{
    struct node *aptr = pptr->left;
    pptr->left = aptr->right;
    aptr->right = pptr;
    return aptr;
}

struct node *leftrotate(struct node *pptr)
{
    struct node *aptr = pptr->right;
    pptr->right = aptr->left;
    aptr->left = pptr;
    return aptr;
}

struct node *insert(struct node *ptr, int key)
{
    static int taller;
    if (ptr == NULL) // base case
    {
        if (ptr = (struct node *)malloc(sizeof(struct node)) == NULL)
        {
            printf("Not enough memory\n"), exit(1);
        }
        ptr->info = key, ptr->left = ptr->right = NULL, ptr->balance = 0;
        taller = TRUE;
    }
    else if (key < ptr->info)
    {
        ptr->left = insert(ptr->left, key);
        if (taller == TRUE)
            ptr = left_check(ptr, &taller);
    }
    else if (key > ptr->info)
    {
        ptr->right = insert(ptr->right, key);
        if (taller == TRUE)
            ptr = right_check(ptr, key);
    }
    else
    {
        printf("Duplicate key found\n");
        taller = FALSE;
    }
    return ptr;
}

int main(int argc, char const *argv[])
{

    return 0;
}

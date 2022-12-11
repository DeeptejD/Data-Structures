#include<stdio.h>
#include<stdlib.h>

struct node
{
    int balance, info;
    struct node *left, *right;
};

struct node *rightRotate(struct node *pptr)
{
    struct node *aptr;
    aptr = pptr->left;
    pptr->left = aptr->right;
    aptr->right = pptr;
    return aptr;
}

struct node *leftRotate(struct node *pptr)
{
    struct node *aptr;
    aptr=pptr->right;
    pptr->right = aptr->left;
    aptr->left = pptr;
    return aptr;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}

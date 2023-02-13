#include <stdio.h>
#include <stdlib.h>

struct node
{
    int height;
    int info;
    struct node *left, *right;
};

int maxof(int a, int b)
{
    return (a > b ? a : b);
}

int height(struct node *ptr)
{
    if (ptr == NULL)
        return 0;
    return ptr->height;
}

int getbal(struct node *ptr)
{
    if (ptr->left == NULL && ptr->right == NULL)
        return 0;
    else
        return (height(ptr->left) - height(ptr->right));
}

struct node *newnode(int info)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = info, temp->left = temp->right = NULL;
    temp->height = 1;
    return temp;
}

struct node *rightrot(struct node *ptr)
{
    struct node *lptr = ptr->left, *lrptr = lptr->right;
    lptr->right = ptr, ptr->left = lrptr;
    ptr->height = 1 + (maxof(height(ptr->left), height(ptr->right)));
    lptr->height = 1 + (maxof(height(lptr->left), height(lptr->right)));
    return lptr;
}

struct node *leftrot(struct node *ptr)
{
    struct node *rptr = ptr->right, *rlptr = rptr->left;
    rptr->left = ptr, ptr->right = rlptr;
    ptr->height = 1 + (maxof(height(ptr->left), height(ptr->right)));
    rptr->height = 1 + maxof(height(rptr->left), height(rptr->right));
    return rptr;
}

struct node *insert(struct node *root, int info)
{
    if (root == NULL)
        return newnode(info);
    if (info < root->info)
        root->left = insert(root->left, info);
    else if (info > root->info)
        root->right = insert(root->right, info);
    else
        return root;

    root->height = 1 + (maxof(height(root->left), height(root->right)));

    int bal = getbal(root);
    if (bal > 1 && info < root->left->info)
        return rightrot(root);
    if (bal < -1 && info > root->right->info)
        return leftrot(root);
    if (bal > 1 && info > root->left->info)
    {
        root->left = leftrot(root->left);
        return rightrot(root);
    }
    if (bal < -1 && info < root->right->info)
    {
        root->right = rightrot(root->right);
        return leftrot(root);
    }

    return root;
}

struct node *insucc(struct node *ptr)
{
    struct node *temp = ptr;
    while (ptr->left != NULL)
        ptr = ptr->left;
    return ptr;
}

struct node *delete(struct node *root, int info)
{
    if (root == NULL)
        return root;
    if (info < root->info)
        root->left = delete (root->left, info);
    else if (info > root->info)
        root->right = delete (root->right, info);
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            struct node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            struct node *temp = insucc(root->right);
            *root = *temp;
            root->right = delete (root->right, temp->info);
        }
        return root;
    }
}

struct node *preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->info);
    preorder(root->left);
    preorder(root->right);
}

int main(int argc, char const *argv[])
{
    struct node *root = NULL;

    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 7);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);

    preorder(root);
    return 0;
}

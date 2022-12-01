#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    false,
    true
} boolean;

struct node
{
    struct node *left, *right;
    int info;
    boolean lthread, rthread;
};

struct node *in_succ(struct node *ptr)
{
    if (ptr->rthread == true)
        return ptr->right;
    else
    {
        ptr = ptr->right;
        while (ptr->lthread == false)
            ptr = ptr->left;
        return ptr;
    }
}

struct node *in_pred(struct node *ptr)
{
    if (ptr->lthread == true)
        return ptr->left;
    else
    {
        ptr = ptr->left;
        while (ptr->rthread == false)
            ptr = ptr->right;
        return ptr;
    }
}

void inorder(struct node *root)
{
    struct node *ptr = root;
    while (ptr->lthread == false)
        ptr = ptr->left;
    while (ptr != NULL)
    {
        printf("%3d", ptr->info);
        ptr = in_succ(ptr);
    }
    printf("\n");
}

void preorder(struct node *root)
{
    struct node *ptr = root;
    while (ptr != NULL)
    {
        printf("%3d", ptr->info);
        if (ptr->rthread == false)
            ptr = ptr->right;
        else if (ptr->lthread == false)
            ptr = ptr->left;
        else
        {
            while (ptr != NULL && ptr->rthread == true)
                ptr = ptr->right;
            if (ptr != NULL)
                ptr = ptr->right;
        }
    }
}

struct node *insert(struct node *root, int ikey)
{
    struct node *par, *ptr, *temp;
    int found = 0;
    par = NULL, ptr = root;
    while (ptr != NULL)
    {
        if (ptr->info == ikey)
        {
            found = 1;
            break;
        }
        par = ptr;
        if (ikey < ptr->info)
        {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        else if (ikey > ptr->info)
        {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }
    if (found)
    {
        printf("Duplicate key\n");
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = ikey, temp->lthread = true, temp->rthread = true;
        if (par == NULL)
        {
            root = temp;
            temp->left = NULL, temp->right = NULL;
        }
        else if (ikey < par->info)
        {
            ptr->left = par->left, ptr->right = par;
            par->lthread = false, par->left = temp;
        }
        else if (ikey > par->info)
        {
            ptr->right = par->right, ptr->left = par;
            par->rthread = false, par->right = temp;
        }
        return root;
    }
}

// deletion
struct node *case_a(struct node *root, struct node *par, struct node *ptr)
{
    if(par==NULL)
        root=NULL;
    else if(ptr==par->left)
    {
        par->lthread == true, par->left = ptr->left;
    } else if(par->right==ptr)
    {
        par->rthread == true, par->right = ptr->right;
    }
    free(ptr);
    return root;
}

struct node *case_b(struct node *root, struct node *par, struct node *ptr)
{
    
}
struct node *case_c(struct node *root, struct node *par, struct node *ptr)
{

}

struct node *del(struct node *root, int dkey)
{
    struct node *ptr, *par, *temp;
    par = NULL, ptr = root;
    int found = 0;
    while (ptr != NULL)
    {
        if (ptr->info == dkey)
        {
            found = 1;
            break;
        }
        par = ptr;
        if (dkey < ptr->info)
        {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        else if (dkey > ptr->info)
        {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }
    if (found == 0)
    {
        printf("Key not found\n");
    }
    else if (ptr->lthread == false && ptr->rthread == false)
        root = case_c(root, par, ptr);
    else if (ptr->rthread == false)
        root = case_b(root, par, ptr);
    else if (ptr->lthread == false)
        root = case_b(root, par, ptr);
    else
        root = case_a(root, par, ptr);
    return root;
}

int main(int argc, char const *argv[])
{

    return 0;
}

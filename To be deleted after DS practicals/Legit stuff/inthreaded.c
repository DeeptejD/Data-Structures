#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} boolean;

struct node
{
    int info;
    boolean lthread, rthread;
    struct node *left, *right;
};

struct node *insert(struct node *root, int ikey)
{
    int found = 0;
    struct node *ptr = root, *par = NULL;
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
        else
        {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }
    if (found)
        printf("Duplicate\n");
    else
    {
        struct node *temp;
        if ((temp = (struct node *)malloc(sizeof(struct node))) == NULL)
        {
            printf("Not enough memory\n");
            return root;
        }
        temp->info = ikey;
        temp->lthread = temp->rthread = true;
        if (par == NULL)
        {
            temp->left = temp->right = NULL;
            root = temp;
        }
        else if (ikey < par->info)
        {
            temp->left = par->left;
            temp->right = par;
            par->lthread = false;
            par->left = temp;
        }
        else
        {
            temp->right = par->right;
            temp->left = par;
            par->rthread = false;
            par->right = temp;
        }
    }
    return root;
}

struct node *insucc(struct node *ptr)
{
    if (ptr->rthread == true)
        return ptr->right;
    else
    {
        struct node *temp = ptr->right;
        while (temp->lthread == false)
            temp = temp->left;
        return temp;
    }
}

struct node *inpred(struct node *ptr)
{
    if (ptr->lthread == true)
        return ptr->left;
    else
    {
        struct node *temp = ptr->left;
        while (temp->rthread == false)
            temp = temp->right;
        return temp;
    }
}

void inorder(struct node *root)
{
    struct node *ptr = root;
    while (ptr->lthread == false)
        ptr = ptr->left;
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = insucc(ptr);
    }
}

struct node *case_a(struct node *root, struct node *par, struct node *ptr)
{
    struct node *temp = ptr;
    if (par == NULL)
    {
        root = NULL;
        free(temp);
        return root;
    }
    else
    {
        if (ptr == par->left)
        {
            par->lthread = true;
            par->left = ptr->left;
        }
        else
        {
            par->rthread = true;
            par->right = ptr->right;
        }
    }
    free(temp);
    return root;
}

struct node *case_b(struct node *root, struct node *par, struct node *ptr)
{
    struct node *temp = ptr;
    struct node *p = inpred(ptr), *s = insucc(ptr);
    // we first find the child;
    struct node *child;
    if (ptr->lthread == false)
        child = ptr->left;
    else
        child = ptr->right;
    if (par == NULL)
    {
        root = child;
    }
    else if (ptr == par->left)
    {
        par->left = child;
    }
    else if (ptr == par->right)
    {
        par->right = child;
    }
    // now we fix the threads
    if (ptr->lthread == false) // the node to be deleted has a left subtree
    {
        p->right = s;
    }
    else if (ptr->rthread == false)
    {
        s->left = p;
    }
    free(temp);
    return root;
}

struct node *case_c(struct node *root, struct node *par, struct node *ptr)
{
    struct node *parsucc = ptr, *succ = ptr->right, *temp = ptr;
    while (succ->lthread == false)
    {
        parsucc = succ;
        succ = succ->left;
    }
    ptr->info = succ->info;
    if (succ->lthread == true && succ->rthread == true)
        root = case_a(root, parsucc, succ);
    else
        root = case_b(root, parsucc, succ);
    return root;
}

struct node *delete(struct node *root, int info)
{
    struct node *par = NULL, *ptr = root;
    int found = 0;
    while (ptr != NULL)
    {
        if (ptr->info == info)
        {
            found = 1;
            break;
        }
        par = ptr;
        if (info < ptr->info)
        {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        else if (info > ptr->info)
        {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }
    if (!found)
        printf("The node to be deleted is not found\n");
    else
    {
        if (ptr->lthread == false && ptr->rthread == false)
            root = case_c(root, par, ptr);
        else if (ptr->lthread == false) // MAKE SURE THESE ARE FALSE HERE
            root = case_b(root, par, ptr);
        else if (ptr->rthread == false) // MAKE SURE THESE ARE FALSE HERE
            root = case_b(root, par, ptr);
        else
            root = case_a(root, par, ptr);
    }
    return root;
}

int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    int arr[11] = {19, 84, 64, 66, 58, 83, 26, 23, 69, 88, 70};
    printf("The tree contains the following nodes\n");
    for (int i = 0; i < 11; i++)
    {
        root = insert(root, arr[i]);
        printf("%d, ", arr[i]);
    }
    printf("\nThe inorder traversal for the tree is: ");
    inorder(root);
    printf("\n");
    printf("Enter the number of nodes you want to delete: ");
    int delnum;
    scanf("%d", &delnum);
    while (delnum--)
    {
        printf("Enter the node you want to delete: ");
        int node;
        scanf("%d", &node);
        root = delete (root, node);
        printf("The inorder traversal after the deletion is: ");
        inorder(root);
        printf("\n");
    }
    return 0;
}

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
    struct node *left, *right;
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
    if (root == NULL)
    {
        printf("Empty tree\n");
        return;
    }
    struct node *ptr = root;
    while (ptr->lthread == false)
        ptr = ptr->left;
    while (ptr != NULL)
    {
        printf("%d", ptr->info);
        ptr = in_succ(ptr);
    }
}

// Non recursive insertion
struct node *insert(struct node *root, int ikey)
{
    int found = 0;
    struct node *par = NULL, *ptr = root, *temp;
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
        printf("Duplicate key present in the tree\n");
    else
    {
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
        if (ikey < par->info)
        {
            temp->left = par->left, temp->right = par, par->lthread = false, par->left = temp;
        }
        else
        {
            temp->right = par->right, temp->left = par, par->rthread = false, par->right = temp;
        }
    }
    return root;
}

struct node *case_a(struct node *root, struct node *par, struct node *ptr)
{
    // CASE_A: NO CHILDREN
    struct node *temp = ptr;
    if (par == NULL)
    {
        // that means there is only one node in the tree
        root = NULL;
    }
    else
    {
        if (ptr == par->left)
        {
            par->left = ptr->left;
            par->lthread == true;
        }
        else
        {
            par->right = ptr->right;
            par->rthread == true;
        }
    }
    free(temp);
    return root;
}

struct node *case_b(struct node *root, struct node *par, struct node *ptr)
{
    struct node *temp = ptr, *p = in_pred(ptr), *s = in_succ(ptr), *child;
    // we find where the child is
    if (ptr->lthread == false)
        child = ptr->left;
    else
        child = ptr->right;
    if (ptr == par->left)
        par->left = child;
    else
        par->right = child;
    // now we fix the threads
    if (ptr->lthread == false)
        p->right = s;
    else
        s->left = p;
    // now we free temp;
    free(temp);
    return root;
}

struct node *case_c(struct node *root, struct node *par, struct node *ptr)
{
    struct node *parsucc = ptr, *succ = ptr->right;
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

struct node *delete(struct node *root, int dkey)
{
    int found = 0;
    struct node *par = NULL, *ptr = root, *temp;
    while (ptr != NULL)
    {
        if (ptr->info == dkey)
        {
            found = 1;
            break;
        }
        else
        {
            par = ptr;
            if (dkey > ptr->info)
            {
                if (ptr->rthread == false)
                    ptr = ptr->right;
                break;
            }
            else if (dkey < ptr->info)
            {
                if (ptr->lthread == false)
                    ptr = ptr->left;
                break;
            }
        }
    }
    if (!found)
        printf("The key to be deleted is not present in the tree\n");
    else
    {
        if (ptr->lthread == false && ptr->rthread == false)
            root = case_c(root, par, ptr);
        else if (ptr->lthread == true)
            root = case_b(root, par, ptr);
        else if (ptr->rthread == true)
            root = case_b(root, par, ptr);
        else
            root = case_a(root, par, ptr);
    }
}

struct node *search(struct node *root, int skey)
{
    if (root == NULL)
    {
        printf("The tree is empty\n");
        return NULL;
    }
    struct node *ptr = root;
    while (ptr != NULL)
    {
        if (ptr->info == skey)
            return ptr;
        if (skey < ptr->info)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    printf("%d is not a node present in the tree\n", skey);
    return NULL;
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
    int choice, ikey, dkey, skey;
    do
    {
        printf("Select an option\n");
        printf("1. Insert a new node\n2. Delete an existing node\n3. Search for a node\n4. Inorder Traversal\n-1. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number: ");
            scanf("%d", &ikey);
            root = insert(root, ikey);
            break;
        case 2:
            printf("Enter the term to be deleted: ");
            scanf("%d", &dkey);
            root = delete (root, dkey);
            break;
        case 3:
            printf("Enter an element to be searched: ");
            scanf("%d", &skey);
            search(root, skey);
            break;
        case 4:
            inorder(root);
            break;
        default:
            printf("Invalid option!\nTry again\n");
            break;
        }
    } while (choice != -1);

    return 0;
}

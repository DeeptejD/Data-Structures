#include <stdio.h>

struct node
{
    int info;
    struct node *leftchild, *rightchild;
};

void search(struct node *root, int key)
{
    if (root == NULL)
    {
        printf("The tree is empty\n");
        return;
    }
    struct node *ptr = root;
    while (ptr != NULL)
    {
        if (key < ptr->info)
            ptr = ptr->leftchild;
        else if (key > ptr->info)
            ptr = ptr->rightchild;
        else
        {
            printf("Key found\n");
            return;
        }
    }
    printf("Key not found\n");
}

struct node *recursive_search(struct node *root, int key)
{
    if (root == NULL)
    {
        printf("The tree is empty\n");
        exit(1);
    }
    if (root == NULL)
    {
        printf("Not found\n");
        return NULL;
    }
    if (key < root->info)
        return recursive_search(root->leftchild, key);
    if (key > root->info)
        return recursive_search(root->rightchild, key);
    else
        return root;
}

struct node *min_non_recursive(struct node *root)
{
    if (root == NULL)
    {
        printf("The tree is empty\n");
        return NULL;
    }
    struct node *ptr = root;
    while (ptr->leftchild != NULL)
        ptr = ptr->leftchild;
    return ptr;
}

struct node *minrec(struct node *ptr)
{
    if (ptr == NULL)
        return NULL;
    if (ptr->leftchild == NULL)
        return ptr;
    return minrec(ptr->leftchild);
}

struct node *nrecmax(struct node *root)
{
    if (root == NULL)
        return NULL;
    struct node *ptr = root;
    while (ptr->rightchild != NULL)
        ptr = ptr->rightchild;
    return ptr;
}

struct node *maxrec(struct node *ptr)
{
    if (ptr == NULL)
        return NULL;
    if (ptr->rightchild == NULL)
        return ptr;
    return maxrec(ptr->rightchild);
}

// both searching and max min take a time of O(h), where h is the height of the tree

struct node *insert_nrec(struct node *root, int key)
{
    struct node *par = NULL, *ptr = root, *temp;
    while (ptr != NULL)
    {
        par = ptr;
        if (key < ptr->info)
            ptr = ptr->leftchild;
        else if (key > ptr->info)
            ptr = ptr->rightchild;
        else
        {
            printf("Duplicate keys\n");
            return root;
        }
    }
    if ((temp = (struct node *)malloc(sizeof(struct node))) == NULL)
    {
        printf("No memory\n");
        exit(1);
    }
    temp->info = key;
    if (par == NULL)
        root = temp;
    else if (key < par->info)
        par->leftchild = temp;
    else
        par->rightchild = temp;
    return root;
}

struct node *insert_recursive(struct node *ptr, int key)
{
    if (ptr == NULL) // base case 1
    {
        if ((ptr = (struct node *)malloc(sizeof(struct node))) == NULL)
        {
            printf("No memory\n");
            exit(1);
        }
        ptr->info = key;
        ptr->rightchild = NULL;
        ptr->leftchild = NULL;
    }
    else if (key < ptr->info)
        ptr->leftchild = insert_recursive(ptr->leftchild, key);
    else if (key > ptr->info)
        ptr->rightchild = insert_recursive(ptr->rightchild, key);
    else
        printf("Duplicate key\n");
    return ptr;
}

// deletion

struct node *case_a(struct node *root, struct node *par, struct node *ptr)
{
    if (par == NULL)
        root = NULL;
    else if (ptr == ptr->leftchild)
        par->leftchild = NULL;
    else
        par->rightchild = NULL;
    free(ptr);
    return root;
}

struct node *case_b(struct node *root, struct node *par, struct node *ptr)
{
    struct node *child;
    if (ptr->leftchild != NULL)
        child = ptr->leftchild;
    else
        child = ptr->rightchild;
    if (par == NULL)
        root = child;
    else if (ptr == par->leftchild)
        par->leftchild = child;
    else
        par->rightchild = child;
    free(ptr);
    return root;
}

struct node *case_c(struct node *root, struct node *par, struct node *ptr)
{
    // node to be deleted has 2 kids
    // inorder successor
    struct node *succ = ptr->rightchild, *parsucc = ptr;
    while (succ != NULL)
        parsucc = succ;
    succ = succ->leftchild;
    ptr->info = succ->info;
    if (succ->leftchild != NULL && succ->rightchild != NULL)
        root = case_a(root, parsucc, succ);
    else
        root = case_b(root, parsucc, succ);
    return root;
};

struct node *del_nrec(struct node *root, int dkey)
{
    if (root == NULL)
    {
        printf("The tree is empty\n");
        return root;
    }
    struct node *ptr = root, *par = NULL;
    while (ptr != NULL)
    {

        if (dkey == ptr->info)
            break;
        par = ptr;
        if (dkey < ptr->info)
            ptr = ptr->leftchild;
        else if (dkey > ptr->info)
            ptr = ptr->rightchild;
    }
    if (ptr == NULL)
        printf("The key to be deleted is not found\n");
    else if (ptr->rightchild != NULL && ptr->leftchild != NULL)
        root = case_c(root, par, ptr);
    else if (ptr->rightchild != NULL)
        root = case_b(root, par, ptr);
    else if (ptr->leftchild != NULL)
        root = case_b(root, par, ptr);
    else
        root = case_a(root, par, ptr);
    return root;
}

struct node *del_rec(struct node *ptr, int dkey)
{
    if (ptr == NULL)
    {
        printf("Key not found\n");
        return ptr;
    }
    if (dkey < ptr->info)
        ptr->leftchild = del_rec(ptr->leftchild, dkey);
    else if (dkey > ptr->info)
        ptr->rightchild = del_rec(ptr->rightchild, dkey);
    else
    {
        // key found
        if (ptr->rightchild != NULL && ptr->leftchild != NULL)
        {
            struct node *succ = ptr->rightchild;
            while (succ->leftchild)
                succ = succ->leftchild;
            ptr->info = succ->info;
            ptr->rightchild = del_rec(ptr->rightchild, succ->info);
        }
        struct node *temp = ptr;
        if (ptr->rightchild != NULL)
            ptr = ptr->rightchild;
        else if (ptr->leftchild != NULL)
            ptr = ptr->leftchild;
        else
            ptr = NULL;
        free(ptr);
    }
    return ptr;
}

int main(int argc, char const *argv[])
{

    return 0;
}

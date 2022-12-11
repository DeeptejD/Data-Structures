#include <stdio.h>

struct node
{
    int info;
    struct node *left, *right;
};

struct node *search(struct node *root, int skey)
{
    struct node *ptr = root;
    while (ptr != NULL)
    {
        if (skey < ptr->info)
            ptr = ptr->left;
        else if (skey > ptr->info)
            ptr = ptr->right;
        else
        {
            printf("Key found\n");
            return ptr;
        }
    }
    printf("The key is  not found\n");
    return NULL;
}

struct node *search_rec(struct node *ptr, int skey)
{
    if (ptr == NULL)
    {
        printf("Key not found\n");
        return NULL;
    }
    if (skey < ptr->info)
        return search(ptr->left, skey);
    else if (skey > ptr->info)
        return search(ptr->right, skey);
    else
    {
        printf("Key found\n");
        return ptr;
    }
}

struct node *insert_nrec(struct node *root, int ikey)
{
    struct node *par, *ptr, *temp;
    ptr = root, par = NULL;
    while (ptr != NULL)
    {
        par = ptr;
        if (ikey < ptr->info)
            ptr = ptr->left;
        else if (ikey > ptr->info)
            ptr = ptr->right;
        else
        {
            printf("Duplicate key\n");
            return;
        }
    }
    if ((temp = (struct node *)malloc(sizeof(struct node))) == NULL)
    {
        printf("NO MEM\n");
        exit(1);
    }
    temp->info = ikey, temp->left = NULL, temp->right = NULL;
    if (par == NULL)
        root = temp;
    else if (ikey < par->info)
        par->left = temp;
    else if (ikey > par->info)
        par->right = temp;
    return root;
}

struct node *insert_rec(struct node *ptr, int ikey)
{
    if(ptr==NULL)
    {
        struct node *temp;
        if((temp=(struct node *)malloc(sizeof(struct node)))==NULL)
        {
            printf("NO MEM\n");
            exit(1);
        }
        temp->info=ikey;
        temp->left = NULL, temp->right = NULL;
    }
    if(ikey<ptr->info)
        ptr->left=insert_rec(ptr->left, ikey);
    else if (ikey>ptr->info)
        ptr->right = insert_rec(ptr->right, ikey);
    else{
        pritnf("Duplicate  key\n");
    }
    return ptr;
}

// case a: no kids :(
struct node *case_a(struct node *root, struct node *par, struct node *ptr)
{
    struct node *temp=ptr;
    if(par==NULL)
        root = NULL;
    else if(ptr==par->right)
        par->right=NULL;
    else if(ptr==par->left)
        par->left=NULL;
    free(temp);
    return root;
}

// case_b: 1 kid :|

struct node *case_b(struct node *root, struct node *par, struct node *ptr)
{
    struct node *temp, *child;
    if(ptr->right!=NULL)
        child = ptr->right;
    else if(ptr->left!=NULL)
        child=ptr->left;
    temp=ptr;
    if(par==NULL)
        root = child;
    else if(ptr==par->left)
        par->left=child;
    else 
        par->right=child;
    free(temp);
    return root;
}

// case c: 2 kids :)

struct node *case_c(struct node *root, struct node *par, struct node *ptr)
{
    struct node *succ, *parsucc;
    succ=ptr->right, parsucc=ptr;
    while(succ->left!=NULL)
    {
        parsucc = ptr, ptr = ptr->left;
    }
    ptr->info=succ->info;
    if(succ->left==NULL && ptr->right==NULL)
        root=case_a(root, parsucc, succ);
    else
        root = case_a(root, parsucc, succ);
    return root;
}

struct node *del_rec(struct node *root, int dkey)
{
    struct node *par, *ptr;
    par=NULL, ptr=root;
    while(ptr!=NULL)
    {
        if(dkey==ptr->info)
            break;
        par=ptr;
        if(dkey<ptr->info)
            ptr = ptr->left;
        else if(dkey>ptr->info)
            ptr = ptr->right;
    }
    if(ptr==NULL)
        printf("The key is not present\n");
    else if(ptr->left!=NULL && ptr->right!=NULL)
        root=case_c(root, par, ptr);
    else if(ptr->left!=NULL)
        root=case_b(root, par, ptr);
    else if(ptr->right!=NULL)
        root=case_b(root, par ,ptr);
    else
        root=case_a(root, par, ptr);
    return root;
}

int main(int argc, char const *argv[])
{

    return 0;
}

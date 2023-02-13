#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *left, *right;
    int height;
};

int maxof(int a, int b)
{
    return (a > b ? a : b);
}

int height(struct node *ptr)
{
    if (ptr == NULL)
        return 0; // no tree so no height
    return ptr->height;
}

int getbalance(struct node *ptr)
{
    if (ptr->left == NULL && ptr->right == NULL)
        return 0; // balanced node
    else
        return (height(ptr->left) - height(ptr->right)); // difference of the heights
}

struct node *newnode(int info)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("No mem\n");
        return NULL;
    }
    temp->info = info, temp->height = 1, temp->left = temp->right = NULL; // new node is always added as a leaf node with height 1 and bf 0
}

struct node *rightrotate(struct node *ptr)
{
    struct node *lptr = ptr->left, *lrptr = lptr->right;
    lptr->right = ptr, ptr->left = lrptr;

    // balance the heights
    ptr->height = maxof(height(ptr->left), height(ptr->right)) + 1;
    lptr->height = maxof(height(lptr->left), height(lptr->right)) + 1;

    return lptr; // return the new node
}

struct node *leftrotate(struct node *ptr)
{
    struct node *rptr = ptr->right, *rlptr = rptr->left;
    rptr->left = ptr, ptr->right = rlptr;

    // balance the heights
    ptr->height = maxof(height(ptr->left), height(ptr->right));
    rptr->height = maxof(height(rptr->left), height(rptr->right));
}

// struct node *insertnode(struct node *root, int info)
// {
//     if (root == NULL)
//         return (newnode(info));
//     if (info < root->info)
//         root->left = insertnode(root->left, info);
//     else if (info > root->info)
//         root->right = insertnode(root->right, info);
//     else
//         return root;
//     // change the height of the root
//     root->height = 1 + maxof(height(root->left), height(root->right));
//     int balance = getbalance(root);
//     if (balance > 1 && info < root->left->info)
//         return rightrotate(root);
//     if (balance < -1 && info > root->right->info)
//         return leftrotate(root);
//     if (balance > 1 && info > root->left->info)
//     {
//         root->left = leftrotate(root->left);
//         return rightrotate(root);
//     }
//     else if (balance < -1 && info < root->right->info)
//     {
//         root->right = rightrotate(root->right);
//         return leftrotate(root);
//     }
//     return root; // if the balance factors are not invalid we simply return the root
// }

struct node *insertnode(struct node *root, int info)
{
    // first we insert the node
    if (root == NULL) // the tree is empty
        return (newnode(info));
    if (info < root->info)
        root->left = insertnode(root->left, info);
    else if (info > root->info)
        root->right = insertnode(root->right, info);
    else
        return root; // duplicate node condition

    // now we change the height of root
    root->height = 1 + (maxof(height(root->left), height(root->right)));

    // now we find the balance factor
    int balance = getbalance(root);

    // now we perform rotations
    if (balance > 1 /*Left heavy*/ && info < root->left->info)
        return rightrotate(root);
    if (balance < -1 && info > root->right->info)
        return leftrotate(root);
    if (balance > 1 && info > root->left->info)
    {
        // left right rotation is required
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (balance < -1 && info < root->right->info)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    // if the tree has not become unbalanced then we simply return the root
    return root;
}

void printPreOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->info);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

int search(struct node *root, int skey)
{
    if (root == NULL)
        return 0;
    if (skey < root->info)
        return search(root->left, skey);
    else if (skey > root->info)
        return search(root->right, skey);
    else
        return 1;
    return 0;
}

int totalheight(struct node *root)
{
    if (root == NULL)
        return 0;
    int hl = totalheight(root->left), hr = totalheight(root->right);
    return 1 + (hl > hr ? hl : hr);
}

int level_nodes(struct node *root, int level)
{
    if (root == NULL || level <= 0)
        return 0;
    if (level == 1)
        return 1;
    else
    {
        int nl = level_nodes(root->left, level - 1);
        int nr = level_nodes(root->right, level - 1);
        return nl + nr;
    }
}

int width(struct node *root)
{
    int h = totalheight(root), ans = 0;
    int temp;
    for (int i = 1; i <= h; i++)
    {
        temp = level_nodes(root, i);
    }
    return temp > ans ? temp : ans;
}

void decreasing(struct node *root)
{
    if (root == NULL)
        return;
    decreasing(root->right);
    printf("%d ", root->info);
    decreasing(root->left);
}

int main(int argc, char const *argv[])
{
    struct node *root = NULL;

    root = insertnode(root, 2);
    root = insertnode(root, 1);
    root = insertnode(root, 7);
    root = insertnode(root, 4);
    root = insertnode(root, 5);
    root = insertnode(root, 3);
    root = insertnode(root, 8);
    if (search(root, 1))
        printf("found\n");
    else
        printf("not found\n");
    if (search(root, 20))
        printf("found\n");
    else
        printf("not found\n");
    if (search(root, 5))
        printf("found\n");
    else
        printf("not found\n");
    printPreOrder(root);
    printf("Total height of the tree is: %d\n", totalheight(root));
    printf("Width of the tree is: %d\n", width(root));
    printf("Decreasing order: ");
    decreasing(root);
    printf("\n");
    return 0;
}

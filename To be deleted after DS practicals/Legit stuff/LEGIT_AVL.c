#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info, height;

    struct node *left, *right;
};

int maxof(int a, int b)
{
    return (a > b ? a : b);
}

int height(struct node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

int getbalance(struct node *root)
{
    if (root->left == NULL && root->right == NULL)
        return 0;
    else
        return (height(root->left) - height(root->right));
}

struct node *newnode(int u)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = u, temp->left = temp->right = NULL;
    temp->height = 1;
    return temp;
}

struct node *rightrotate(struct node *ptr)
{
    struct node *lptr = ptr->left, *lrptr = lptr->right;
    lptr->right = ptr, ptr->left = lrptr;
    ptr->height = 1 + maxof(height(ptr->left), height(ptr->right));
    lptr->height = 1 + maxof(height(lptr->left), height(lptr->right));
    return lptr;
}

struct node *leftrotate(struct node *ptr)
{
    struct node *rptr = ptr->right, *rlptr = rptr->left;
    rptr->left = ptr, ptr->right = rlptr;
    ptr->height = 1 + maxof(height(ptr->left), height(ptr->right));
    rptr->height = 1 + maxof(height(rptr->left), height(rptr->right));
    return rptr;
}

// struct node *insert(struct node *root, int u)
// {
//     // idea: first insert like a normal bst then adjust height of node. then get balance factor for the node and do your rotations

//     if (root == NULL)
//         return (newnode(u));
//     if (u < root->info)
//         root->left = insert(root->left, u);
//     else if (u > root->info)
//         root->right = insert(root->right, u);
//     else
//         return root;

//     // adjust height
//     root->height = 1 + (maxof(height(root->left), height(root->right)));

//     int bal = getbalance(root);

//     if (bal > 1 && u < root->left->info)
//         return rightrotate(root);
//     if (bal < -1 && u > root->right->info)
//         return leftrotate(root);
//     if (bal > 1 && u > root->left->info)
//     {
//         root->left = leftrotate(root->left);
//         return rightrotate(root);
//     }
//     if (bal < -1 && u < root->right->info)
//     {
//         root->right = rightrotate(root->right);
//         return leftrotate(root);
//     }
// }

struct node *insert(struct node *node, int info)
{
    // Find the correct position to insert the node and insert it
    if (node == NULL)
        return (newnode(info));

    if (info < node->info)
        node->left = insert(node->left, info);
    else if (info > node->info)
        node->right = insert(node->right, info);
    else
        return node;

    // Update the balance factor of each node and
    // Balance the tree
    node->height = 1 + maxof(height(node->left),
                           height(node->right));

    int bal = getbalance(node);
        if (bal > 1 && info < node->left->info)
            return rightrotate(node);
        if (bal < -1 && info > node->right->info)
            return leftrotate(node);
        if (bal > 1 && info > node->left->info)
        {
            node->left = leftrotate(node->left);
            return rightrotate(node);
        }
        if (bal < -1 && info < node->right->info)
        {
            node->right = rightrotate(node->right);
            return leftrotate(node);
        }

    return node;
}

struct node *insucc(struct node *ptr)
{
    struct node *curr = ptr;
    while (curr->left != NULL)
        curr = curr->left;
    return curr;
}

struct node *delnode(struct node *root, int u)
{
    if (root == NULL)
        return NULL;
    struct node *temp;
    // find the node
    if (u < root->info)
        root->left = delnode(root->left, u);
    else if (u > root->info)
        root->right = delnode(root->right, u);
    else
    {
        // we foudn the node
        if (temp->left == NULL || temp->right == NULL)
        {
            struct node *ptr = temp->left ? temp->left : temp->right;
            if (ptr == NULL)
            {
                // no children
                ptr = temp;
                temp = NULL;
            }
            else
            {
                *temp = *ptr; // swap actual contents
            }
            free(ptr);
        }
        else
        {
            // two kids
            struct node *ptr = insucc(temp->right);
            temp->info = ptr->info;
            temp->right = delnode(temp->right, ptr->info);
        }
    }
    // after deleting if root becomes null we dimply return it or else we will have to adjust the height and the balance factors
    if (root == NULL)
        return root;

    root->height = 1 + (maxof(height(root->left), height(root->right)));

    int bal = getbalance(root);

    // the rotations are same as in insertion but in this case we check the balance of root->left and root->right

    if (bal > 1 && getbalance(root->left) >= 0)
        return rightrotate(root);
    if (bal > 1 && getbalance(root->left) < 0)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (bal < -1 && getbalance(root->right) <= 0)
        return leftrotate(root);
    if (bal < -1 && getbalance(root->right) > 0)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
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

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}

int main()
{

    struct node *root = NULL;

    root = insert(root, 2);

    root = insert(root, 1);
    root = insert(root, 7);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);

    printPreOrder(root);

    root = delnode(root, 3);

    printf("\nAfter deletion: ");
    printPreOrder(root);
    printf("Inorder for the tree: ");
    inorder(root);
    printf("postorder for the tree: ");
    postorder(root);

    return 0;
}
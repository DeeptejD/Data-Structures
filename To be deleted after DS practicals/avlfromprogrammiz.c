// AVL tree implementation in C

#include <stdio.h>
#include <stdlib.h>

// Create node
struct node
{
    int info;
    struct node *left, *right;
    int height;
};

int max(int a, int b);

// Calculate height
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Create a node
struct node *newnode(int info)
{
    struct node *node = (struct node *)
        malloc(sizeof(struct node));
    node->info = info;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

// Right rotate
struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get the balance factor
int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Insert node
struct node *insertnode(struct node *node, int info)
{
    // Find the correct position to insertnode the node and insertnode it
    if (node == NULL)
        return (newnode(info));

    if (info < node->info)
        node->left = insertnode(node->left, info);
    else if (info > node->info)
        node->right = insertnode(node->right, info);
    else
        return node;

    // Update the balance factor of each node and
    // Balance the tree
    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);
    if (balance > 1 && info < node->left->info)
        return rightRotate(node);

    if (balance < -1 && info > node->right->info)
        return leftRotate(node);

    if (balance > 1 && info > node->left->info)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    else if (balance < -1 && info < node->right->info)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct node *minValuenode(struct node *node)
{
    struct node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

// Delete a nodes
struct node *deletenode(struct node *root, int info)
{
    // Find the node and delete it
    if (root == NULL)
        return root;

    if (info < root->info)
        root->left = deletenode(root->left, info);

    else if (info > root->info)
        root->right = deletenode(root->right, info);

    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            struct node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            struct node *temp = minValuenode(root->right);

            root->info = temp->info;

            root->right = deletenode(root->right, temp->info);
        }
    }

    if (root == NULL)
        return root;

    // Update the balance factor of each node and
    // balance the tree
    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Print the tree
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

    root = insertnode(root, 2);
    root = insertnode(root, 1);
    root = insertnode(root, 7);
    root = insertnode(root, 4);
    root = insertnode(root, 5);
    root = insertnode(root, 3);
    root = insertnode(root, 8);

    printPreOrder(root);

    root = deletenode(root, 3);

    printf("\nAfter deletion: ");
    printPreOrder(root);
    printf("Inorder for the tree: ");
    inorder(root);
    printf("postorder for the tree: ");
    postorder(root);

    return 0;
}
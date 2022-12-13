// binary search tree

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root, int n)
{
    if (root == NULL)
    {
        struct node *tmp;
        if ((tmp = (struct node *)malloc(sizeof(struct node))) == NULL)
        {
            printf("NO mem");
            exit(1);
        }
        tmp->info = n;
        tmp->left = NULL;
        tmp->right = NULL;
        root = tmp;
        return root;
    }
    if (n < root->info)
        root->left = insert(root->left, n);
    else if (n > root->info)
        root->right = insert(root->right, n);
    return root;
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->info);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->info);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->info);
}

struct node *delete(struct node *root, int n)
{
    if (root == NULL)
    {
        printf("Not found");
        return root;
    }
    if (n < root->info)
        root->left = delete (root->left, n);
    else if (n > root->info)
        root->right = delete (root->right, n);
    else
    {
        if (root->left == NULL)
        {
            struct node *tmp = root->right;
            free(root);
            return tmp;
        }
        else if (root->right == NULL)
        {
            struct node *tmp = root->left;
            free(root);
            return tmp;
        }
        struct node *tmp = root->right;
        while (tmp->left != NULL)
            tmp = tmp->left;
        root->info = tmp->info;
        root->right = delete (root->right, tmp->info);
    }
    return root;
}

struct node *search(struct node *root, int n)
{
    if (root == NULL)
    {
        printf("Not found");
        return root;
    }
    if (n < root->info)
        root->left = search(root->left, n);
    else if (n > root->info)
        root->right = search(root->right, n);
    else
    {
        printf("Found");
        return root;
    }
    return root;
}

void display(struct node *root)
{
    int ch;
    printf("1. Inorder\n2. Preorder\n3. Postorder\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        inorder(root);
        break;
    case 2:
        preorder(root);
        break;
    case 3:

        postorder(root);
        break;
    default:
        printf("Invalid choice");
        break;
    }
}

int main()
{
    struct node *root = NULL;
    int ch, n;
    int arr[] = {12, 23, 45, 6, 67, 92, 99, 50};
    for (int i = 0; i < 8; i++)
        root = insert(root, arr[i]);
    display(root);
    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number to be inserted: ");
            scanf("%d", &n);
            root = insert(root, n);
            break;
        case 2:
            printf("Enter the number to be deleted: ");
            scanf("%d", &n);
            root = delete (root, n);
            break;
        case 3:

            printf("Enter the number to be searched: ");
            scanf("%d", &n);
            root = search(root, n);
            break;
        case 4:

            display(root);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice");
            break;
        }
    }
    return 0;
}

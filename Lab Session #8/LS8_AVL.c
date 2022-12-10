#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct node
{
    struct node *left;
    int info;
    struct node *right;
    int balance;
};

struct node *RotateRight(struct node *pptr);
struct node *RotateLeft(struct node *pptr);
struct node *insert_left_check(struct node *pptr, int *ptaller);
struct node *insert_LeftBalance(struct node *pptr);
struct node *insert_right_check(struct node *pptr, int *ptaller);
struct node *insert_RightBalance(struct node *pptr);
struct node *insert(struct node *pptr, int ikey);
struct node *del_left_check(struct node *pptr, int *pshorter);
struct node *del_RightBalance(struct node *pptr, int *pshorter);
struct node *del_right_check(struct node *pptr, int *pshorter);
struct node *del_LeftBalance(struct node *pptr, int *pshorter);
struct node *del(struct node *pptr, int dkey);

struct node *search(struct node *root, int skey);

int height(struct node *root);
int width(struct node *root);

void visit_all(struct node *root, int *maximum, int *minimum);
void max_min(struct node *root);

void decreasing(struct node *root);

int main()
{
    struct node *root = NULL, *ptr;
    int nodes[] = {40, 28, 30, 72, 92, 36, 23, 88, 45, 32, 15, 63, 86, 11, 85, 70};
    printf("List of nodes in the tree: ");
    for (int i = 0; i < 16; i++)
    {
        root = insert(root, nodes[i]);
        printf("%3d,", nodes[i]);
    }
    while (1)
    {
        printf("\n1. insertion\n2. deletion\n3. search\n4. width\n5. max and min\n6. decreasing\n7. exit\n");
        int sc, val;
        scanf("%d", &sc);

        switch (sc)
        {
        case 1:
            scanf("%d", &val), root = insert(root, val);
            break;

        case 2:
            scanf("%d", &val), root = del(root, val);
            break;

        case 3:
            scanf("%d", &val), ptr = search(root, val);
            break;

        case 4:
            printf("the width is %d \n", width(root));
            break;

        case 5:
            max_min(root);
            break;

        case 6:
            decreasing(root), printf("\n");
            break;

        case 7:
            exit(0);

        default:
            exit(1);
        }
    }

    return 0;
}

struct node *RotateRight(struct node *pptr)
{
    struct node *aptr;
    aptr = pptr->left;
    pptr->left = aptr->right;
    aptr->right = pptr;
    return aptr;
}

struct node *RotateLeft(struct node *pptr)
{
    struct node *aptr;
    aptr = pptr->right;
    pptr->right = aptr->left;
    aptr->left = pptr;
    return aptr;
}

struct node *insert_left_check(struct node *pptr, int *ptaller)
{
    switch (pptr->balance)
    {
    case 0:

        pptr->balance = 1;
        break;

    case -1:

        pptr->balance = 0;
        *ptaller = FALSE;
        break;

    case 1:

        pptr = insert_LeftBalance(pptr);
        *ptaller = FALSE;
    }
    return pptr;
}

struct node *insert_LeftBalance(struct node *pptr)
{
    struct node *aptr, *bptr;
    aptr = pptr->left;
    if (aptr->balance == 1)
    {
        pptr->balance = 0;
        aptr->balance = 0;
        pptr = RotateRight(pptr);
    }
    else
    {

        bptr = aptr->right;
        switch (bptr->balance)
        {
        case -1:

            pptr->balance = 0;
            aptr->balance = 1;
            break;

        case 1:

            pptr->balance = -1;
            aptr->balance = 0;
            break;

        case 0:

            pptr->balance = 0;
            aptr->balance = 0;
        }
        bptr->balance = 0;
        pptr->left = RotateLeft(aptr);
        pptr = RotateRight(pptr);
    }
    return pptr;
}

struct node *insert_right_check(struct node *pptr, int *ptaller)
{
    switch (pptr->balance)
    {
    case 0:

        pptr->balance = -1;
        break;

    case 1:

        pptr->balance = 0;
        *ptaller = FALSE;
        break;

    case -1:

        pptr = insert_RightBalance(pptr);
        *ptaller = FALSE;
    }
    return pptr;
}

struct node *insert_RightBalance(struct node *pptr)
{
    struct node *aptr, *bptr;
    aptr = pptr->right;
    if (aptr->balance == -1)
    {
        pptr->balance = 0;
        aptr->balance = 0;
        pptr = RotateLeft(pptr);
    }
    else
    {

        bptr = aptr->left;
        switch (bptr->balance)
        {
        case -1:

            pptr->balance = 1;
            aptr->balance = 0;
            break;

        case 1:

            pptr->balance = 0;
            aptr->balance = -1;
            break;

        case 0:

            pptr->balance = 0;
            aptr->balance = 0;
        }
        bptr->balance = 0;
        pptr->right = RotateRight(aptr);
        pptr = RotateLeft(pptr);
    }
    return pptr;
}

struct node *insert(struct node *pptr, int ikey)
{
    static int taller;
    if (pptr == NULL)
    {

        pptr = (struct node *)malloc(sizeof(struct node));
        pptr->info = ikey;
        pptr->left = NULL;
        pptr->right = NULL;
        pptr->balance = 0;
        taller = TRUE;
    }
    else if (ikey < pptr->info)
    {

        pptr->left = insert(pptr->left, ikey);
        if (taller == TRUE)

            pptr = insert_left_check(pptr, &taller);
    }
    else if (ikey > pptr->info)
    {

        pptr->right = insert(pptr->right, ikey);
        if (taller == TRUE)

            pptr = insert_right_check(pptr, &taller);
    }
    else
    {

        printf("Duplicate key\n");
        taller = FALSE;
    }
    return pptr;
}

struct node *del_left_check(struct node *pptr, int *pshorter)
{

    switch (pptr->balance)
    {
    case 0:

        pptr->balance = -1;
        *pshorter = FALSE;
        break;

    case 1:

        pptr->balance = 0;
        break;

    case -1:

        pptr = del_RightBalance(pptr, pshorter);
    }
    return pptr;
}

struct node *del_RightBalance(struct node *pptr, int *pshorter)
{

    struct node *aptr, *bptr;
    aptr = pptr->right;
    if (aptr->balance == 0)
    {
        pptr->balance = -1;
        aptr->balance = 1;
        *pshorter = FALSE;
        pptr = RotateLeft(pptr);
    }
    else if (aptr->balance == -1)
    {

        pptr->balance = 0;
        aptr->balance = 0;
        pptr = RotateLeft(pptr);
    }
    else
    {

        bptr = aptr->left;
        switch (bptr->balance)
        {
        case 0:

            pptr->balance = 0;
            aptr->balance = 0;
            break;

        case 1:

            pptr->balance = 0;
            aptr->balance = -1;
            break;

        case -1:

            pptr->balance = 1;
            aptr->balance = 0;
        }
        bptr->balance = 0;
        pptr->right = RotateRight(aptr);
        pptr = RotateLeft(pptr);
    }
    return pptr;
}

struct node *del_right_check(struct node *pptr, int *pshorter)
{

    switch (pptr->balance)
    {
    case 0:

        pptr->balance = 1;
        *pshorter = FALSE;
        break;

    case -1:

        pptr->balance = 0;
        break;

    case 1:

        pptr = del_LeftBalance(pptr, pshorter);
    }
    return pptr;
}

struct node *del_LeftBalance(struct node *pptr, int *pshorter)
{

    struct node *aptr, *bptr;
    aptr = pptr->left;
    if (aptr->balance == 0)
    {
        pptr->balance = 1;
        aptr->balance = -1;
        *pshorter = FALSE;
        pptr = RotateRight(pptr);
    }
    else if (aptr->balance == 1)
    {

        pptr->balance = 0;
        aptr->balance = 0;
        pptr = RotateRight(pptr);
    }
    else
    {

        bptr = aptr->right;
        switch (bptr->balance)
        {
        case 0:

            pptr->balance = 0;
            aptr->balance = 0;
            break;

        case 1:

            pptr->balance = -1;
            aptr->balance = 0;
            break;

        case -1:

            pptr->balance = 0;
            aptr->balance = 1;
        }
        bptr->balance = 0;
        pptr->left = RotateLeft(aptr);
        pptr = RotateRight(pptr);
    }
    return pptr;
}

struct node *del(struct node *pptr, int dkey)
{
    static int shorter;
    struct node *tmp, *succ;
    if (pptr == NULL)
    {

        printf("Duplicate key\n");
        shorter = FALSE;
        return pptr;
    }
    else if (dkey < pptr->info)
    {

        pptr->left = del(pptr->left, dkey);
        if (shorter == TRUE)

            pptr = del_left_check(pptr, &shorter);
    }
    else if (dkey > pptr->info)
    {

        pptr->right = del(pptr->right, dkey);
        if (shorter == TRUE)

            pptr = del_right_check(pptr, &shorter);
    }
    else
    {

        if (pptr->left != NULL && pptr->right != NULL)
        {

            succ = pptr->right;
            while (succ->left != NULL)
                succ = succ->left;
            pptr->info = succ->info;
            pptr->right = del(pptr->right, succ->info);
            if (shorter == TRUE)

                pptr = del_right_check(pptr, &shorter);
        }
        else
        {

            tmp = pptr;
            if (pptr->left != NULL)
                pptr = pptr->left;
            else if (pptr->right != NULL)
                pptr = pptr->right;

            else

                pptr = NULL;

            free(tmp);
            shorter = TRUE;
        }
    }
    return pptr;
}

struct node *search(struct node *root, int skey)
{
    if (root == NULL)
    {
        printf("not found\n");
        return root;
    }
    else if (root->info == skey)
    {
        printf("found\n");
        return root;
    }
    else if (root->info < skey)
    {
        return search(root->right, skey);
    }
    else
    {
        return search(root->left, skey);
    }
}

int height(struct node *root)
{
    if (root == NULL)
        return 0;

    int choice1 = height(root->left), choice2 = height(root->right);
    return 1 + (choice1 > choice2 ? choice1 : choice2);
}

int level_nodes(struct node *root, int ht)
{
    if (root == NULL || ht < 1)
        return 0;
    if (ht == 1)
        return 1;
    else
    {
        int left_ct = level_nodes(root->left, ht - 1);
        int right_ct = level_nodes(root->right, ht - 1);
        return left_ct + right_ct;
    }
}

int width(struct node *root)
{
    int h = height(root);
    int ans = 0;

    for (int i = 1; i <= h; i++)
    {
        int temp = level_nodes(root, i);
        ans = (ans > temp) ? ans : temp;
    }

    return ans;
}

void visit_all(struct node *root, int *maximum, int *minimum)
{
    if (root == NULL)
        return;

    *maximum = (root->info > *maximum) ? root->info : *maximum;
    *minimum = (root->info < *minimum) ? root->info : *minimum;

    visit_all(root->left, maximum, minimum);
    visit_all(root->right, maximum, minimum);
}

void max_min(struct node *root)
{
    int maximum, minimum;
    struct node *ptr = root;
    while (ptr->left != NULL)
        ptr = ptr->left;
    minimum = ptr->info;
    ptr = root;
    while (ptr->right != NULL)
        ptr = ptr->right;
    maximum = ptr->info;
    printf("Min: %d, Max: %d\n", minimum, maximum);
}

void decreasing(struct node *root)
{
    if (root == NULL)
        return;

    decreasing(root->right);
    printf("%d ", root->info);
    decreasing(root->left);
}

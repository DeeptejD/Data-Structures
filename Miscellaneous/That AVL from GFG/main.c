#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data, height;
    struct node *left, *right;
};

int height(struct node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main(int argc, char const *argv[])
{

    return 0;
}

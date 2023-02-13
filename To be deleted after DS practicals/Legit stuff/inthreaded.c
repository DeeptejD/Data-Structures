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

struct node *insert(struct node *root, int info)
{
    
}

int main(int argc, char const *argv[])
{

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int reclinear(int arr[], int size, int x)
{

    // the idea to searching recursively is that we recusively compare with the last element until we find the element
    int ind;
    size--;
    if (size >= 0)
    {
        if (arr[size] == x)
            ind = size;
        else
            ind = reclinear(arr, size, x);
    }
    else
        return -1;
    return ind;
}

int linears(int arr[], int size, int x)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int altlinear(int arr[], int size, int x)
{
    int i = 0;
    while ((arr[i] != x) && (i < size))
        i++;
    return (i < size ? i : -1);
}

int main(int argc, char const *argv[])
{
    int arr[] = {34, 56, 78, 21, 23, 21, 34, 56, 78, 9, 2, 3, 67, 69};
    int size = sizeof(arr) / sizeof(arr[0]);
    if (reclinear(arr, size, 78))
        printf("Found\n");
    else
        printf("Not found\n");

    if (altlinear(arr, size, 34) > -1)
        printf("Found\n");
    else
        printf("Not found\n");

    if (linears(arr, size, 2))
        printf("Found\n");
    else
        printf("Not found\n");
    return 0;
}

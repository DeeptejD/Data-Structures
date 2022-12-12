#include <stdio.h>

int Linear(float arr[], int low, int up, float item)
{
    if (low > up)
        return -1;
    if (arr[low] == item)
        return 1;
    Linear(arr, low + 1, up, item);
}

int main(int argc, char const *argv[])
{
    float arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float item;
    int n = sizeof(arr) / sizeof(arr[0]);
    scanf("%f", &item);
    if (Linear(arr, 0, n - 1, item) == -1)
        printf("Item not present\n");
    else
        printf("Item is present\n");
    return 0;
}

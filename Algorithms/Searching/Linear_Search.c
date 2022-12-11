#include <stdio.h>

int Linear_Search(int arr[], int n, int item)
{
    int i = 0;
    while (i < n && arr[i] != item)
        i++;
    if (i < n)
        return i;
    return -1;
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter item to be searched: ");
    int item, loc;
    scanf("%d", &item);
    if ((loc = Linear_Search(arr, n, item)) != -1)
        printf("%d found at index %d\n", item, loc);
    else
        printf("%d not present\n", item);
    return 0;
}

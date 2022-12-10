#include <stdio.h>

int binarySearchNR(int arr[], int item, int n, int low, int up)
{
    int mid;
    while (low <= up)
    {
        mid = (low + up) / 2;
        if (item < arr[mid])
            up = mid - 1;
        else if (item > arr[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

void Insertion_Sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1, k = arr[i];
        while (j >= 0 && k < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = k;
    }
}

int binarySearchR(int arr[], int item, int low, int up)
{
    int mid;
    if (low > up)
        return -1;
    mid = (low + up) / 2;
    if (item < arr[mid])
        binarySearchR(arr, item, low, mid - 1);
    else if (item > arr[mid])
        binarySearchR(arr, item, mid + 1, up);
    else
        return mid;
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    int arr[n], loc;
    for (int i = 0; i < n; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    Insertion_Sort(arr, n);
    printf("After Sorting: ");
    for (int i = 0; i < n; i++)
        printf("%3d", arr[i]);
    printf("\nEnter item to be searched: ");
    int item;
    scanf("%d", &item);
    if ((loc = binarySearchNR(arr, item, n, 0, n - 1)) != -1)
        printf("%d found at index %d\n", item, loc);
    else
        printf("%d not found\n", item);
    printf("Enter item to be searched: ");
    scanf("%d", &item);
    if ((loc = binarySearchR(arr, item, 0, n - 1)) != -1)
        printf("%d found at index %d\n", item, loc);
    else
        printf("%d not found\n", item);
    return 0;
}

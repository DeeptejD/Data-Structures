#include <stdio.h>

// iterative binary search
int bs(int arr[], int size, int x)
{
    int low = 0, up = size - 1;
    while (low <= up)
    {
        int mid = (low + up) / 2;
        if (x < arr[mid])
            up = mid - 1;
        else if (x > arr[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

// recursive binary search
int bsrec(int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == x)
        return mid;
    if (x < arr[mid])
        bsrec(arr, low, mid - 1, x);
    else
        bsrec(arr, mid + 1, high, x);
}

// utility function to sort the array0
void insort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1, key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// utility function to display array
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int arr[] = {23, 45, 67, 21, 67, 21, 90, 2, 3, 67, 91, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    insort(arr, size);
    display(arr, size);
    if (bs(arr, size, 3) != -1)
        printf("Found\n");
    else
        printf("Not found\n");
    if (bsrec(arr, 0, size - 1, 1) != -1)
        printf("Found\n");
    else
        printf("Not found\n");
    return 0;
}

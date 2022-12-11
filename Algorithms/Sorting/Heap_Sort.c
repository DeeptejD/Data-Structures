// HEAP SORT

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%3d", arr[i]);
    printf("\n");
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    int i;
    // build heap part
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // actual sorting
    // we swap and heapify
    for (i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    heap_sort(arr, n);
    printf("The sorted array is: ");
    display(arr, n);
    return 0;
}

#include <stdio.h>

// insertion sort
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

// Bubble sort

// selection sort

// utility function to swap
void swapnums(int *a, int *b)
{
    int temp = *a;
    *a = *b, *b = temp;
}

void selsort(int arr[], int size)
{
    // idea: we select the index of the min element from the array and swap the current with that element
    for (int i = 0; i < size; i++)
    {
        int min = i; // keeps a track of the min index
        for (int j = i + 1; j < size; j++)
            min = arr[j] < arr[min] ? j : min;
        if (min != i)
            swapnums(&arr[min], &arr[i]);
    }
}

// bubble sort
void bubb(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swapnums(&arr[j], &arr[j + 1]);
}

// merge sort

void merge(int arr[], int left, int mid, int right)
{
    int n1, n2, i, j;
    n1 = mid - left + 1;
    n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++, k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++, k++;
    }
}

void mergesort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// utitlity function to show elements
void show(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int arr[] = {23, 45, 67, 21, 67, 21, 90, 2, 3, 67, 91, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr, 0, size - 1);
    show(arr, size);
    return 0;
}

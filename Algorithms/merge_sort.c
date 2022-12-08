#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid; // right minus mid because mid actually lies before the right part
    int L[n1], R[n2];
    // splitting the parent array
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j]; // for right half left is mid+1

    i = 0;
    j = 0;
    k = left;
    // entering elements from each subarray in a sorted manner while (i < n1 && j < n2)
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

    // remaining elements
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
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

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d, ", arr[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    // printf("Enter number of elements: ");
    // scanf("%d", &n);
    int arr[] = {28, 66, 16, 76, 71, 86, 94, 97, 56, 95};
    int n = sizeof(arr) / sizeof(arr[0]);
    // printf("Insert elements\n");
    // for (int i = 0; i < n; i++)
    //     scanf("%d", &arr[i]);
    printArray(arr, n);
    printf("Sorted array: ");
    mergesort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}

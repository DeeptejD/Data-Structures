// // // selection sort
// #include <stdio.h>

// // void show(int arr[], int n)
// // {
// //     for (int i = 0; i < n; i++)
// //         printf("%d, ", arr[i]);
// //     printf("\n");
// // }

// // void swap(int *a, int *b)
// // {
// //     int temp = *a;
// //     *a = *b;
// //     *b = temp;
// // }

// // void selection_sort(int arr[], int n)
// // {
// //     for (int i = 0; i < n - 1; i++)
// //     {
// //         int min_index = i;
// //         for (int j = i; j < n; j++)
// //         {
// //             if (arr[j] < arr[i])
// //                 min_index = j;
// //         }
// //         if (min_index != i)
// //             swap(&arr[min_index], &arr[i]);
// //         else
// //         {
// //             while (arr[i] != arr[min_index])
// //                 i++;
// //         }
// //     }
// // }

// // void bubble(int arr[], int n)
// // {
// //     int i; // no of passes n-1
// //     for (i = 0; i < n - 1; i++)
// //     {
// //         int x = 0;

// //         for (int j = 0; j < n - 1 - i /*minus i because after each pass the rightmost or the largest element is at its right place*/; j++)
// //         {
// //             if (arr[j] > arr[j + 1])
// //             {
// //                 swap(&arr[j], &arr[j + 1]);
// //                 x++;
// //             }
// //         }
// //         if (!x)
// //             break;
// //     }
// // }

// // void insertion_sort(int arr[], int n)
// // {
// //     int i, j, k;
// //     for (i = 1; i < n; i++)
// //     {
// //         k = arr[i];
// //         for (j = i - 1; j >= 0 && k < arr[j]; j--)
// //             arr[j + 1] = arr[j];
// //         arr[j + 1] = k;
// //     }
// // }

// // void shell_sort(int arr[], int n)
// // {
// //     int i, j, k, incr;
// //     printf("Enter max increment (odd value): ");
// //     scanf("%d", &incr);
// //     while (incr >= 1)
// //     {
// //         for (i = incr; i < n; i++)
// //         {
// //             k = arr[i];
// //             for (j = i - incr; j >= 0 && k < arr[j]; j = j - incr)
// //                 arr[j + incr] = arr[j];
// //             arr[j + incr] = k;
// //         }
// //         incr = incr - 2;
// //     }
// // }

// // int main(int argc, char const *argv[])
// // {
// //     int n;
// //     printf("Enter number of elements: ");
// //     scanf("%d", &n);
// //     int arr[n];
// //     for (int i = 0; i < n; i++)
// //     {
// //         printf("Enter element %d: ", i + 1);
// //         scanf("%d", &arr[i]);
// //     }
// //     printf("Before Sort: ");
// //     show(arr, n);
// //     printf("Slection Sort\n");
// //     selection_sort(arr, n);
// //     show(arr, n);
// //     printf("Bubble Sort\n");
// //     bubble(arr, n);
// //     show(arr, n);
// //     printf("Insertion Sort\n");
// //     insertion_sort(arr, n);
// //     show(arr, n);
// //     printf("Shell sort\n");
// //     shell_sort(arr, n);
// //     show(arr, n);
// //     return 0;
// // }

// void merge(int arr1[], int arr2[], int arr3[], int n1, int n2)
// {
//     int i, j, k;
//     i = j = k = 0;
//     while((i<n1) && (j<n2))
//     {
//         if(arr1[i]<arr2[j])
//             arr3[k++]=arr1[i++];
//         else
//             arr3[k++] = arr2[j++];
//     }
//     while(i<n1)
//         arr3[k++] = arr1[i++];
//     while(j<n2)
//         arr3[k++] = arr2[j++];
// }

// int main(int argc, char const *argv[])
// {
    
//     return 0;
// }

#include<stdio.h>

void quick(int arr[], int size)
{
    
}

int main(int argc, char const *argv[])
{
    int arr[]={34, 56, 12, 39, 20, 23, 78};
    int n = sizeof(arr) / sizeof(arr[0]);
    quick(arr, 0);

    return 0;
}


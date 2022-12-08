#include <stdio.h>

void show(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d, ", arr[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int n, temp;
    printf("Enter number: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    show(arr, n);
    for (int i = 0; i < n - 1; i++) // no of passes
    {
        int swaps = 0;
        for (int j = 0; j < n - i - 1; j++) // exclusing the last elements cuz they sorted
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
        if (!swaps)
            break;
    }
    printf("Sorted list: ");
    show(arr, n);
    return 0;
}

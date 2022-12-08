#include <stdio.h>

int isMin(int a, int b)
{
    return (a < b);
}

void swapnum(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void show(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d, ", arr[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Before Sort: ");
    show(arr, n);
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i; // holds index of min element
        for (int j = i + 1; j < n; j++)
        {
            if (isMin(arr[j], arr[min]))
            {
                min = j;
            }
        }
        swapnum(&arr[i], &arr[min]);
    }
    printf("After Sort:  ");
    show(arr, n);
    return 0;
}

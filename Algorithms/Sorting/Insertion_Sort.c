#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Insert elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
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
    printf("Sorted array is: ");
    for (int i = 0; i < n; i++)
        printf("%3d", arr[i]);

    return 0;
}

// THIS CODE IS NOT COMPLETE (mainly cuz shell sort sucks, sry Donald Shell)

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int incr;
    printf("Enter max increment: ");
    scanf("%d", &incr);
    int i, j, k;
    while (incr >= 1)
    {
        for (i = incr; i < n; i++)
        {
            k = arr[i];
            for (j = i - incr; j >= 0 && k < arr[j]; j = j - incr)
                arr[j + incr] = arr[j];
            arr[j + incr] = k;
        }
        incr = incr - 2;
    }

    return 0;
}

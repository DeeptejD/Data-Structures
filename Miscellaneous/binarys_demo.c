#include<stdio.h>
#define MAX 100

int binary_search(int arr[], int low, int up, int key)
{
    if(low<up)
    {
        int mid = (low+(up-low))/2;
        }
}

int main(int argc, char const *argv[])
{
    int arr[MAX], n;
    printf("Enter howmany numbers: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the key tp be searched: ");
    scanf("%d", &key);
    if(binary_search(arr, n, key))
        printf("%d is found\n", key);
    else
        printf("%d not found\n", key);
    return 0;
}

// insertion sort
#include <stdio.h>

void insertionsort(int arr[], int low, int high)
{
    int n = high - low + 1;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int n;
    printf("Enter the number of terms:");
    scanf("%d", &n);
    int arr[n];

    printf("\nEnter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    insertionsort(arr, 0, n - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
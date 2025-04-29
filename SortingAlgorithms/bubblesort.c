// bubble sort
#include <stdio.h>

void bubblesort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    bubblesort(arr, n);
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
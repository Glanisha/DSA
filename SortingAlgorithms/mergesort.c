// merge sort
#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = 0;
    int temp[high - low + 1];

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
    for (int x = 0; x < (high - low + 1); x++)
    {
        arr[low + x] = temp[x];
    }
}

void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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

    mergesort(arr, 0, n - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
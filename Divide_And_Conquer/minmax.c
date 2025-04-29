// mimax with divide and conquer approach
#include <stdio.h>

typedef struct
{
    int min;
    int max;
} num;

num minmax(int arr[], int low, int high)
{
    num result;
    if (low == high)
    {
        result.min = arr[low];
        result.max = arr[high];
        return result;
    }

    if (low + 1 == high)
    {
        if (arr[low] < arr[high])
        {
            result.min = arr[low];
            result.max = arr[high];
            return result;
        }
        else
        {
            result.min = arr[high];
            result.max = arr[low];
            return result;
        }
    }

    int mid = (high + low) / 2;

    num res1 = minmax(arr, low, mid);
    num res2 = minmax(arr, mid + 1, high);

    if (res1.min < res2.min)
    {
        result.min = res1.min;
    }
    else
    {
        result.min = res2.min;
    }
    if (res1.max > res2.max)
    {
        result.max = res1.max;
    }
    else
    {
        result.max = res2.max;
    }

    return result;
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

    num result = minmax(arr, 0, n - 1);

    printf("\nMinimum value: %d", result.min);
    printf("\nMaximum value: %d\n", result.max);

    return 0;
}
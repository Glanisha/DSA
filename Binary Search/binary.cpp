#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid = start + ((end - start) / 2);

    while (start <= end)
    {
        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

        mid = start + ((end - start) / 2);
    }
    return -1;
}

int main()
{
    int arr[7] = {1, 2, 3, 6, 7, 8, 9};
    int index = binarySearch(arr, 7, 10);
    cout << index;
}
#include <stdio.h>

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int isSorted = 1;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                isSorted = 0;
            }
        }
        
        if (isSorted)
            break;
    }
}

// TC: O(N^2)
// SC: O(1)
#include <stdio.h>

// Find kth smallest element in unsorted array of distinct elements

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int partition(int arr[], int l, int r, int k)
{
    int pivot = arr[l];
    int i = l, j = r;

    while (i < j)
    {
        while (arr[i] <= pivot && i < r)
            i++;
        while (arr[j] > pivot && j > l)
            j--;

        if (i < j)
            swap(&arr[i], &arr[j]);
    }

    swap(&arr[l], &arr[j]);

    if (j == k - 1)
        return pivot;
    if (j < k - 1)
        return partition(arr, j + 1, r, k);
    else
        return partition(arr, l, j - 1, k);
}

int quickSelect(int k, int arr[], int n)
{
    return partition(arr, 0, n - 1, k);
}

// TC: O(N)
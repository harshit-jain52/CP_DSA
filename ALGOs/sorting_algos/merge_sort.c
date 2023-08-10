#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int i, j, k;
    int left[n1], right[n2];

    for (i = 0; i < n1; i++)
        left[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    merge(arr, l, mid, r);
}

// TC: O(NlogN)
// SC : O(N) + RSS
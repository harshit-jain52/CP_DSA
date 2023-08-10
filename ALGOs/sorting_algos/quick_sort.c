#include <stdio.h>

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int partition(int arr[], int l, int r)
{
    // choosing pivot = first element
    int pivot = arr[l];
    int i = l + 1, j = r;

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

    return j;

    // choosing pivot = last element
    /*
    int pivot= arr[r];
    int i=l;

    for(int j=l;j<=r;j++){
        if(arr[j]<pivot){
            swap(&arr[i],&arr[j]);
            i++;
        }
    }

    swap(&arr[r],&arr[i]);

    return i;
    */
}

void quickSort(int arr[], int l, int r)
{
    if (l >= r)
        return;

    int pi = partition(arr, l, r);
    quickSort(arr, l, pi - 1);
    quickSort(arr, pi + 1, r);
}

// TC: O(NlogN)
// SC : O(1) + RSS
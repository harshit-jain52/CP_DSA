#include <stdio.h>

int binarySearch(int arr[], int n, int key)
{
    int lo = 0, hi = n - 1, mid;

    while (lo <= hi)
    {
        mid = (lo + hi) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] > key)
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    return -1;
}

int lowerBound(int arr[], int n, int key)
{
    int lo = 0, hi = n - 1, mid;
    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;

        if (arr[mid] >= key)
            hi = mid;
        else
            lo = mid + 1;
    }

    if (arr[lo] >= key)
        return lo;
    
    if (arr[hi] >= key)
        return hi;
    
    return -1;
}

int upperBound(int arr[], int n, int key){
    int lo = 0, hi = n - 1, mid;
    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;

        if (arr[mid] > key)
            hi = mid;
        else
            lo = mid + 1;
    }

    if (arr[lo] > key)
        return lo;
    
    if (arr[hi] > key)
        return hi;
    
    return -1;
}
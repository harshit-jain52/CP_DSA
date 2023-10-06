#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 1000

// MIN-HEAP

int size = 0; // size of Heap

// Helper Methods for Indices
int Root() { return 1; } // highest priority
int parent(int i) { return i / 2; }
int leftChild(int i) { return 2 * i; }
int rightChild(int i) { return 2 * i + 1; }

// Helper Methods for Node Testing
int hasParent(int i) { return i != Root(); }
int isValidNode(int i) { return i <= size; }

// Utility Functions
void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int front(int H[]) // O(1)
{
    if (size == 0)
    {
        printf("\nfront: Empty Priority Queue\n");
        exit(0);
    }

    return H[Root()];
}

void shiftUp(int H[], int idx)
{
    while (hasParent(idx) && (H[parent(idx)] > H[idx]))
    {
        swap(&H[parent(idx)], &H[idx]);
        idx = parent(idx);
    }
}

void shiftDown(int H[], int idx)
{
    while (isValidNode(leftChild(idx)))
    {
        int child = leftChild(idx);

        if (isValidNode(rightChild(idx)) && H[rightChild(idx)] < H[leftChild(idx)])
            child = rightChild(idx);

        if (H[idx] > H[child])
            swap(&H[idx], &H[child]);
        else
            break;

        idx = child;
    }
}

void push(int H[], int newNum) // O(logN)
{
    if (size == CAPACITY)
    {
        printf("\npush: Full Priority Queue\n");
        exit(0);
    }

    H[++size] = newNum; // insert at the last
    shiftUp(H, size);
}

void pop(int H[]) // O(logN)
{
    if (size == 0)
    {
        printf("\npop: Empty Priority Queue\n");
        exit(0);
    }

    H[Root()] = H[size--]; // move last element at root
    shiftDown(H, Root());
}

void heapify(int H[], int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++) // Put all elements acc to heap-structure property
        H[i + 1] = arr[i];

    size = n;

    // Enforce heap-order property
    for (i = size / 2; i >= 1; i--) // Shift Down all elements starting from first non-leaf node upto the root
        shiftDown(H, i);
}

int main()
{
    int H[CAPACITY + 1]; // 1-based indexing

    int arr[] = {51, 43, 93, 18, 42, 99, 54, 2, 74};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Build Heap

    /*
    William's Approach: Push n times

    for(int i=0, i<n, i++){
        push(H,arr[i]);
    }

    TC: Avg O(N); Worst Case: O(NlogN)
    */

    // Floyd's Method
    heapify(H, arr, n); // O(N)
}
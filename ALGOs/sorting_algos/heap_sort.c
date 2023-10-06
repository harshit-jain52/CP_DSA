#include <stdio.h>
#include <stdlib.h>

int size = 0;

int Root() { return 1; }
int parent(int i) { return i / 2; }
int leftChild(int i) { return 2 * i; }
int rightChild(int i) { return 2 * i + 1; }
int hasParent(int i) { return i != Root(); }
int isValidNode(int i) { return i <= size; }
void swap(int *x, int *y);
void shiftDown(int H[], int idx);
void pop(int H[]);
int front(int H[]);

void heapSort(int arr[], int n) // array is 1-based
{
    int i;
    // Build Max Heap
    size = n;
    for (i = size / 2; i >= 1; i--)
        shiftDown(arr, i);

    // Pop N times
    int lastIdx, lastElem;
    while (size > 0)
    {
        lastIdx = size;
        lastElem = front(arr);
        pop(arr);
        arr[lastIdx] = lastElem;
    }

    // TC: O(NlogN)
    // SC: O(1)
}

int front(int H[])
{
    if (size == 0)
    {
        printf("\nfront: Empty Priority Queue\n");
        exit(0);
    }

    return H[Root()];
}

void shiftDown(int H[], int idx)
{
    while (isValidNode(leftChild(idx)))
    {
        int child = leftChild(idx);

        if (isValidNode(rightChild(idx)) && H[rightChild(idx)] > H[leftChild(idx)])
            child = rightChild(idx);

        if (H[idx] < H[child])
            swap(&H[idx], &H[child]);
        else
            break;
    }
}

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void pop(int H[])
{
    if (size == 0)
    {
        printf("\npop: Empty Priority Queue\n");
        exit(0);
    }

    H[Root()] = H[size--];
    shiftDown(H, Root());
}
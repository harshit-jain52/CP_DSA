#include <stdio.h>
#include <stdlib.h>

int size = 0;

void swap(int *x, int *y);
int Root() { return 1; }
int parent(int i) { return i / 2; }
int leftChild(int i) { return 2 * i; }
int rightChild(int i) { return 2 * i + 1; }
int hasParent(int i) { return i != Root(); }
int isValidNode(int i) { return i <= size; }
void pop(int H[]);
int front(int H[]);
void shiftDown(int H[], int idx);

void printKLargest(int arr[], int n, int k) // O(N + KlogN)
{
    // O(N): Create Max Heap of N elements
    int *maxHeap = (int *)malloc((n + 1) * sizeof(int));

    int i;
    for (i = 0; i < n; i++)
        maxHeap[i + 1] = arr[i];

    size = n;
    for (i = size / 2; i >= 1; i--)
        shiftDown(maxHeap, i);
    
    // O(KlogN): Pop k times
    while(k--){
        printf("%d ",front(maxHeap));
        pop(maxHeap);
    }
}

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
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

        idx = child;
    }
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

int main()
{
    int arr[] = {12, 5, 787, 1, 23, 11, 7, 787};
    printKLargest(arr, 8, 4);
}
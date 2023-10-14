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
void push(int H[], int newNum, int k);
void pop(int H[]);
int front(int H[]);
void shiftUp(int H[], int idx);
void shiftDown(int H[], int idx);

void printKLargest(int arr[], int n, int k) // O(K + NlogK)
{
    // O(K): Create Min Heap of First K elements
    int *minHeap = (int *)malloc((k + 2) * sizeof(int));
    int i;
    for (i = 0; i < k; i++)
        minHeap[i + 1] = arr[i];

    size = k;
    for (i = size / 2; i >= 1; i--)
        shiftDown(minHeap, i);

    // O((N-K)logK): Heap contains k largest elemets so far
    for (i = k; i < n; i++)
    {
        if (arr[i] > front(minHeap))
        {
            pop(minHeap);
            push(minHeap, arr[i], k);
        }
    }

    // O(KlogK): (optional) Sort the heap in descending order
    int lastIdx, lastElem;
    while (size > 0)
    {
        lastIdx = size;
        lastElem = front(minHeap);
        pop(minHeap);
        minHeap[lastIdx] = lastElem;
    }

    for (i = 1; i <= k; i++)
    {
        printf("%d ", minHeap[i]);
    }

    free(minHeap);
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

void push(int H[], int newNum, int k)
{
    if (size == k)
    {
        printf("\npush: Full Priority Queue\n");
        exit(0);
    }

    H[++size] = newNum;
    shiftUp(H, size);
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
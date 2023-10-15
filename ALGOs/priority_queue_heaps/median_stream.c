#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 1000

int ct = 0;

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int Root() { return 1; }
int parent(int i) { return i / 2; }
int leftChild(int i) { return 2 * i; }
int rightChild(int i) { return 2 * i + 1; }

int hasParent(int i) { return i != Root(); }
int isValidNode(int i, int size) { return i <= size; }
int front(int H[]) { return H[Root()]; }

void shiftUp(int H[], int idx);
void shiftDown(int H[], int *sz, int idx);
void push(int H[], int *sz, int num);
void pop(int H[], int *sz);

void balanceHeaps(int maxheap[], int minheap[], int *maxsz, int *minsz)
{
    ct++;
    if (*maxsz > (ct + 1) / 2)
    {
        int elem = front(maxheap);
        push(minheap, minsz, -elem);
        pop(maxheap, maxsz);
    }
    else if (*minsz > ct / 2)
    {
        int elem = front(minheap);
        push(maxheap, maxsz, -elem);
        pop(minheap, minsz);
    }
}

double getMedian(int maxheap[], int minheap[])
{
    if (ct % 2 == 1)
        return front(maxheap);
    else
    {
        double tmp = front(maxheap) - front(minheap);
        return tmp / 2;
    }
}
void insertHeap(int x, int maxheap[], int minheap[], int *maxsz, int *minsz)
{
    if (*maxsz == 0 || x < front(maxheap))
        push(maxheap, maxsz, x);
    else
        push(minheap, minsz, -x);

    balanceHeaps(maxheap, minheap, maxsz, minsz);

    printf("%.1f ", getMedian(maxheap, minheap));
}

int main()
{
    int n = 8;
    ct = 0;
    int stream[] = {4, 5, 2, 15, 1, 3, 100, 2};
    int maxheap[CAPACITY], minheap[CAPACITY];
    int maxsz = 0, minsz = 0;

    for (int i = 0; i < n; i++)
    {
        insertHeap(stream[i], maxheap, minheap, &maxsz, &minsz);
    }
}

void shiftUp(int H[], int idx)
{
    while (hasParent(idx) && (H[parent(idx)] < H[idx]))
    {
        swap(&H[idx], &H[parent(idx)]);
        idx = parent(idx);
    }
}

void shiftDown(int H[], int *sz, int idx)
{
    while (isValidNode(leftChild(idx), *sz))
    {
        int child = leftChild(idx);

        if (isValidNode(rightChild(idx), *sz) && (H[rightChild(idx)] > H[leftChild(idx)]))
            child = rightChild(idx);

        if (H[idx] < H[child])
            swap(&H[idx], &H[child]);
        else
            break;

        idx = child;
    }
}

void push(int H[], int *sz, int num)
{
    *sz = *sz + 1;
    H[*sz] = num;

    shiftUp(H, *sz);
}

void pop(int H[], int *sz)
{
    H[Root()] = H[*sz];
    *sz = *sz - 1;

    shiftDown(H, sz, Root());
}
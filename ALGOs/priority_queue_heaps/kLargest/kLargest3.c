#include <stdio.h>
#include <stdlib.h>

int orgsize = 0;
int hpsize = 0;

typedef struct
{
    int val; // Number
    int org; // Index in original heap
} node;

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void swapNode(node *x, node *y)
{
    node tmp = *x;
    *x = *y;
    *y = tmp;
}

int Root() { return 1; }
int parent(int i) { return i / 2; }
int leftChild(int i) { return 2 * i; }
int rightChild(int i) { return 2 * i + 1; }
int hasParent(int i) { return i != Root(); }

int isValid(int i) { return i <= orgsize; }
void shiftDown(int H[], int idx);

int isValidNode(int i) { return i <= hpsize; }
node frontNode(node H[]) { return H[Root()]; };
void pushNode(node H[], node new);
void popNode(node H[]);
void shiftUpNode(node H[], int idx);
void shiftDownNode(node H[], int idx);

void printKLargest(int arr[], int n, int k) // O(N + KlogK)
{
    // O(N): Build Max Heap of size N
    int *orgHeap = (int *)malloc((n + 1) * sizeof(int));

    int i;
    for (i = 0; i < n; i++)
        orgHeap[i + 1] = arr[i];

    orgsize = n;
    for (i = orgsize / 2; i >= 1; i--)
        shiftDown(orgHeap, i);

    // Initialize smaller heap
    node *hp = (node *)malloc(n * sizeof(node));
    hpsize = 0;

    int idx = Root();
    for (i = 0; i < k; i++) // O(KlogK)
    {
        printf("%d ", orgHeap[idx]);

        if (i == k)
            return;

        node tmp;
        if (isValid(leftChild(idx)))
        {
            tmp.val = orgHeap[leftChild(idx)];
            tmp.org = leftChild(idx);
            pushNode(hp, tmp);
        }
        if (isValid(rightChild(idx)))
        {
            tmp.val = orgHeap[rightChild(idx)];
            tmp.org = rightChild(idx);
            pushNode(hp, tmp);
        }

        tmp = frontNode(hp);
        popNode(hp);
        idx = tmp.org;
    }
}

int main()
{
    int arr[] = {12, 5, 787, 1, 23, 11, 7, 787};
    printKLargest(arr, 8, 4);
}

void pushNode(node H[], node new)
{
    H[++hpsize] = new;
    shiftUpNode(H, hpsize);
}

void popNode(node H[])
{
    H[Root()] = H[hpsize--];
    shiftDown(H, Root());
}

void shiftUpNode(node H[], int idx)
{
    while (hasParent(idx) && H[parent(idx)].val < H[idx].val)
    {
        swapNode(&H[parent(idx)], &H[idx]);
        idx = parent(idx);
    }
}

void shiftDownNode(node H[], int idx)
{
    while (isValidNode(leftChild(idx)))
    {
        int child = leftChild(idx);

        if (isValidNode(rightChild(idx)) && H[rightChild(idx)].val > H[leftChild(idx)].val)
            child = rightChild(idx);

        if (H[idx].val < H[child].val)
            swapNode(&H[idx], &H[child]);
        else
            break;

        idx = child;
    }
}

void shiftDown(int H[], int idx)
{
    while (isValid(leftChild(idx)))
    {
        int child = leftChild(idx);

        if (isValid(rightChild(idx)) && H[rightChild(idx)] > H[leftChild(idx)])
            child = rightChild(idx);

        if (H[idx] < H[child])
            swap(&H[idx], &H[child]);
        else
            break;

        idx = child;
    }
}
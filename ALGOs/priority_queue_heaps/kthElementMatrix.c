#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int val;
    int row;
    int col;
} node;

void swap(node *x, node *y)
{
    node tmp = *x;
    *x = *y;
    *y = tmp;
}

int size = 0;
int Root() { return 1; }
int parent(int i) { return i / 2; }
int leftChild(int i) { return 2 * i; }
int rightChild(int i) { return 2 * i + 1; }
int hasParent(int i) { return i != Root(); }
int isValidNode(int i) { return i <= size; }
node front(node H[]);
void shiftUp(node H[], int idx);
void shiftDown(node H[], int idx);
void pop(node H[]);
void push(node H[], node newNode);

int KthSmallestElementInMatrix(int *mat, int n, int k)
{
    // O(N): Min Heap of first row
    node *heap = (node *)malloc((n + 1) * sizeof(node));
    int i;
    for (i = 0; i < n; i++)
    {
        node tmp = {*((mat + i * n) + 0), 0, i};
        heap[i + 1] = tmp;
    }

    size = n;
    for (i = size / 2; i >= 1; i--)
        shiftDown(heap, i);

    // Remove first element from heap and push next element in the same column
    for (i = 1; i < k; i++)
    {
        node tmp = front(heap);
        pop(heap);
        if (tmp.row < n - 1)
        {
            node add = {*((mat + tmp.col * n) + tmp.row + 1), tmp.row + 1, tmp.col};
            push(heap, add);
        }
    }

    int ans = front(heap).val;
    free(heap);
    return ans;
}

int main()
{
    int arr[][4] = {{16, 28, 60, 64},
                    {22, 41, 63, 91},
                    {27, 50, 87, 93},
                    {36, 78, 87, 94}};

    printf("%d\n", KthSmallestElementInMatrix((int *)arr, 4, 3));
}

node front(node H[])
{
    return H[Root()];
}

void shiftUp(node H[], int idx)
{
    while (hasParent(idx) && (H[parent(idx)].val > H[idx].val))
    {
        swap(&H[idx], &H[parent(idx)]);
        idx = parent(idx);
    }
}

void shiftDown(node H[], int idx)
{
    while (isValidNode(leftChild(idx)))
    {
        int child = leftChild(idx);

        if (isValidNode(rightChild(idx)) && (H[rightChild(idx)].val < H[leftChild(idx)].val))
            child = rightChild(idx);

        if (H[idx].val > H[child].val)
            swap(&H[idx], &H[child]);
        else
            break;

        idx = child;
    }
}

void pop(node H[])
{
    H[Root()] = H[size--];
    shiftDown(H, Root());
}

void push(node H[], node newNode)
{
    H[++size] = newNode;
    shiftUp(H, size);
}

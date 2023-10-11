#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *newNode(int val)
{
    node *vertex = (node *)malloc(sizeof(node));
    vertex->data = val;
    vertex->left = NULL;
    vertex->right = NULL;

    return vertex;
}

int searchInorder(int inorder[], int val, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

node *buildFromPreorderInorder(int preStart, int preEnd, int inStart, int inEnd, int preOrder[], int inOrder[])
{
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    node *root = newNode(preOrder[preStart]);

    // where is the root in inOrder?
    // can be optimized by hashing
    int inRoot = searchInorder(inOrder, root->data, inStart, inEnd);
    int numsLeft = inRoot - inStart;

    root->left = buildFromPreorderInorder(preStart + 1, preStart + numsLeft, inStart, inRoot - 1, preOrder, inOrder);
    root->right = buildFromPreorderInorder(preStart + numsLeft + 1, preEnd, inRoot + 1, inEnd, preOrder, inOrder);

    return root;
}

node *buildFromPostorderInorder(int postStart, int postEnd, int inStart, int inEnd, int postOrder[], int inOrder[])
{
    if (postStart > postEnd || inStart > inEnd)
        return NULL;

    node *root = newNode(postOrder[postEnd]);

    // where is the root in inOrder?
    // can be optimized by hashing
    int inRoot = searchInorder(inOrder, root->data, inStart, inEnd);
    int numsLeft = inRoot - inStart;

    root->left = buildFromPostorderInorder(postStart, postStart + numsLeft - 1, inStart, inRoot - 1, postOrder, inOrder);
    root->right = buildFromPostorderInorder(postStart + numsLeft, postEnd - 1, inRoot + 1, inEnd, postOrder, inOrder);

    return root;
}

node *BSTfromPreOrder(int preOrder[], int n, int upperBound, int *idx)
{
    if (*idx == n || preOrder[*idx] > upperBound)
        return NULL;

    node *curr = newNode(preOrder[*idx]);
    *idx = *idx + 1;

    curr->left = BSTfromPreOrder(preOrder, n, curr->data, idx);
    curr->right = BSTfromPreOrder(preOrder, n, upperBound, idx);

    return curr;
}
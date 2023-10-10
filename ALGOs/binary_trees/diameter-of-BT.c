#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int postOrderHeight(node *root, int *d)
{
    if (root == NULL)
        return 0;

    int leftHeight = postOrderHeight(root->left, d);
    int rightHeight = postOrderHeight(root->right, d);

    *d = max(*d, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(node *root)
{
    int diameter = 0;
    int *p = &diameter;
    postOrderHeight(root, p);

    return diameter;
}

// O(N)

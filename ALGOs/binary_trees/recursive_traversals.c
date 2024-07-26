#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

/*
DFS:
(i) Pre-Order Traversal: root-left-right
(ii) In-order Traversal: left-root-right
(iii) Post-Order Traversal: left-right-root
*/

void preOrder(node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node *vertex)
{
    if (vertex == NULL)
        return;

    inOrder(vertex->left);
    printf("%d ", vertex->data);
    inOrder(vertex->right);
}

void postOrder(node *vertex)
{
    if (vertex == NULL)
        return;

    postOrder(vertex->left);
    postOrder(vertex->right);
    printf("%d ", vertex->data);
}

node *prev = NULL;
void flattenBT(node *curr) // Binary Tree to Linked List in pre-order
{
    if (curr == NULL)
        return;

    flattenBT(curr->right);
    flattenBT(curr->left);

    curr->right = prev;
    curr->left = NULL;
    prev = curr;
}
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
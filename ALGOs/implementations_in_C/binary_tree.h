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


/*
int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);


    printf("\n");
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
}
*/
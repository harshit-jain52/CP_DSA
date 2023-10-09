#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *lca(node *root, node *p, node *q)
{
    if (root == NULL || root == p || root == q)
        return root;

    node *l = lca(root->left, p, q);
    node *r = lca(root->right, p, q);

    if (l == NULL)
        return r; // lca in right subtree
    if (r == NULL)
        return l; // lca in left subtree

    return root;
}
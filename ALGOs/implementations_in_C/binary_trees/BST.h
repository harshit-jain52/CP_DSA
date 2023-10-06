#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *newNode(int val) // O(depth)
{
    node *vertex = (node *)malloc(sizeof(node));
    vertex->data = val;
    vertex->left = NULL;
    vertex->right = NULL;

    return vertex;
}

node *insertNode(node *root, int val) // O(depth)
{
    if (root == NULL)
        root = newNode(val);
    else if (val > root->data)
        root->right = insertNode(root->right, val);
    else if (val < root->data)
        root->left = insertNode(root->left, val);

    return root;
}

node *getMax(node *root) // O(depth)
{
    if (root->right != NULL)
        return getMax(root->right);
    else
        return root;
}

node *getMin(node *root) // O(depth)
{
    if (root->left != NULL)
        return getMin(root->left);
    else
        return root;
}

node *deleteNode(node *root, int val) // O(depth)
{
    if (root == NULL)
        return root;

    if (val > root->data)
        root->right = deleteNode(root->right, val);
    else if (val < root->data)
        root->left = deleteNode(root->left, val);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        if (root->left == NULL)
        {
            node *tmp = root;
            root = root->right;
            free(tmp);
        }
        else if (root->right == NULL)
        {
            node *tmp = root;
            root = root->left;
            free(tmp);
        }
        else
        {
            node *MaxInLeft = getMax(root->left);                 // finds the biggest node in the left branch
            root->data = MaxInLeft->data;                         // copy data
            root->left = deleteNode(root->left, MaxInLeft->data); // recursively delete the max node in left

            /*
            Easier approach

            node *MaxInLeft = getMax(root->left); // finds the biggest node in the left branch
            MaxInLeft->right = root->right;       // SHIFT the right subtree

            node *tmp = root;
            root = root->left;
            free(tmp);
            */

            /*
            Alternatively,

            node *MinInRight = getMin(root->right);                 // finds the smallest node in the right branch
            root->data = MinInRight->data;                          // copy data
            root->right = deleteNode(root->right, MinInRight->data); // recursively delete the min node in right
            */
        }
    }

    return root;
}

node *findNode(node *root, int key) // O(depth)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;
    if (root->data > key)
        return findNode(root->left, key);
    if (root->data < key)
        return findNode(root->right, key);
}

void printSorted(node *root) // In-Order Traversal of BST; O(N)
{
    if (root == NULL)
        return;

    printSorted(root->left);
    printf("\t[ %d ]\t", root->data);
    printSorted(root->right);
}

node *inOrderSuccessor(node *root, int key)
{
    node *succ = NULL;
    node *curr = root;

    while (curr)
    {
        if (curr->data > key)
        {
            succ = curr;
            curr = curr->left;
        }
        else
            curr = curr->right;
    }

    return succ;
}

node *inOrderPredecessor(node *root, int key)
{
    node *pre = NULL;
    node *curr = root;

    while (curr)
    {
        if (curr->data < key)
        {
            pre = curr;
            curr = curr->right;
        }
        else
            curr = curr->left;
    }

    return pre;
}

node *kthSmallest(node *root, int *k) // pointer to integer is passed
{
    if (root == NULL)
        return NULL;

    node *l = kthSmallest(root->left, k);
    if (l != NULL)
        return l;

    *k = *k - 1;
    if (*k == 0)
        return root;

    return kthSmallest(root->right, k);
}

node *kthLargest(node *root, int *k) // pointer to integer is passed
{
    if (root == NULL)
        return NULL;

    node *r = kthLargest(root->right, k);
    if (r != NULL)
        return r;

    *k = *k - 1;
    if (*k == 0)
        return root;

    return kthLargest(root->left, k);
}

node *LCA(node *root, node *p, node *q) // Lowest Common Ancestor
{
    if (p->data > q->data)
        return LCA(root, q, p);

    node *curr = root;

    while (!(curr->data >= p->data && curr->data <= q->data))
    {
        if (curr->data < p->data)
            curr = curr->right;
        else
            curr = curr->left;
    }

    return curr;
}
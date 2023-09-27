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
            node *MaxInLeft = getMax(root->left);                 // finds the biggest node in the left branch (inorder predecessor)
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

            node *MinInRight = getMax(root->right);                 // finds the smallest node in the left branch (inorder successor)
            root->data = MinInRight->data;                          // copy data
            root->left = deleteNode(root->right, MinInRight->data); // recursively delete the min node in right
            */
        }
    }

    return root;
}

int findNode(node *root, int key) // O(depth)
{
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
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
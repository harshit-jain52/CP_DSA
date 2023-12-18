#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
} node;

int max(int x, int y) // Utility Function
{
    return (x > y) ? x : y;
}

node *newNode(int val) // O(logN)
{
    node *vertex = (node *)malloc(sizeof(node));
    vertex->data = val;
    vertex->left = NULL;
    vertex->right = NULL;

    return vertex;
}

int getHeight(node *root) // O(1)
{
    if (root == NULL)
        return -1;

    return root->height;
}

node *getMax(node *root) // O(logN)
{
    if (root->right != NULL)
        return getMax(root->right);
    else
        return root;
}

node *getMin(node *root) // O(logN)
{
    if (root->left != NULL)
        return getMin(root->left);
    else
        return root;
}

node *rightRotate(node *parent) // O(1)
{
    node *child = parent->left;

    parent->left = child->right;
    parent->height = 1 + max(getHeight(parent->left), getHeight(parent->right));

    child->right = parent;
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    parent = child;
    return parent;
}

node *leftRotate(node *parent) // O(1)
{
    node *child = parent->right;

    parent->right = child->left;
    parent->height = 1 + max(getHeight(parent->left), getHeight(parent->right));

    child->left = parent;
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    parent = child;
    return parent;
}

node *retrace(node *root) // O(1)
{
    if (root == NULL)
        return NULL;

    if ((getHeight(root->left) - getHeight(root->right)) > 1) // left-heavy
    {
        if (getHeight(root->left->left) < getHeight(root->left->right)) // left subtree is right heavy
        {
            root->left = leftRotate(root->left);
        }
        root = rightRotate(root);
    }
    else if ((getHeight(root->right) - getHeight(root->left)) > 1) // right-heavy
    {
        if (getHeight(root->right->left) > getHeight(root->right->right)) // right subtree is left heavy
        {
            root->right = rightRotate(root->right);
        }
        root = leftRotate(root);
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    return root;
}

node *insertNode(node *root, int val) // O(logN)
{
    if (root == NULL)
        root = retrace(newNode(val));
    else if (val > root->data)
        root->right = insertNode(root->right, val);
    else if (val < root->data)
        root->left = insertNode(root->left, val);

    return retrace(root);
}

node *deleteNode(node *root, int val) // O(logN)
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
            node *MinInRight = getMin(root->right);                 // finds the smallest node in the right branch
            root->data = MinInRight->data;                          // copy data
            root->right = deleteNode(root->right, MinInRight->data); // recursively delete the min node in right
        }
    }

    return retrace(root);
}

int findNode(node *root, int key) // O(logN)
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

void printTree(node *root, int idx) // Pre-Order Traversal
{
    if (root == NULL)
        return;

    printf("%d [%d] ", root->data, idx);
    printTree(root->left, idx + 1);
    printTree(root->right, idx + 1);
}

/*
int main()
{
    node *root = NULL;
    int a[] = {2, 18, 42, 43, 69, 54, 74, 93, 99, 100, 6};
    for (int i = 0; i < 11; i++)
    {
        root = insertNode(root, a[i]);
        printTree(root, 0);
        printf("\n");
    }
}
*/
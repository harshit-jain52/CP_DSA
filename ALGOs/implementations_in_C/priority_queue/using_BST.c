#include <stdio.h>
#include <stdlib.h>

// Priority Queue: Balanced BST Implementation

typedef struct node
{
    int priority; // lower value -> higher priority
    struct node *left;
    struct node *right;
    int height; // height-balanced
} node;

node *newNode(int p)
{
    node *vertex = (node *)malloc(sizeof(node));
    vertex->priority = p;
    vertex->left = NULL;
    vertex->right = NULL;

    return vertex;
}

int max(int x, int y);
int getHeight(node *root);
node *getMax(node *root);
node *getMin(node *root);
node *rightRotate(node *parent);
node *leftRotate(node *parent);
node *retrace(node *root);
node *insertNode(node *root, int val);
node *deleteNode(node *root, int val);

int front(node *root) // O(logN)
{
    node *tmp = getMin(root);

    if (tmp == NULL)
    {
        printf("\nfront: Empty Priority Queue\n");
        exit(0);
    }
    return tmp->priority;
}

node *pop(node *root) // O(logN)
{
    node *tmp = getMin(root);
    if (tmp == NULL)
    {
        printf("\npop: Empty Priority Queue\n");
        exit(0);
    }

    return deleteNode(root, tmp->priority);
}

node *push(node *root, int newNum) // O(logN)
{
    return insertNode(root, newNum);
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

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int getHeight(node *root)
{
    if (root == NULL)
        return -1;

    return root->height;
}

node *getMax(node *root)
{
    if (root->right != NULL)
        return getMax(root->right);
    else
        return root;
}

node *getMin(node *root)
{
    if (root->left != NULL)
        return getMin(root->left);
    else
        return root;
}

node *rightRotate(node *parent)
{
    node *child = parent->left;

    parent->left = child->right;
    parent->height = 1 + max(getHeight(parent->left), getHeight(parent->right));

    child->right = parent;
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    parent = child;
    return parent;
}

node *leftRotate(node *parent)
{
    node *child = parent->right;

    parent->right = child->left;
    parent->height = 1 + max(getHeight(parent->left), getHeight(parent->right));

    child->left = parent;
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    parent = child;
    return parent;
}

node *retrace(node *root)
{
    if (root == NULL)
        return NULL;

    if ((getHeight(root->left) - getHeight(root->right)) > 1)
    {
        if (getHeight(root->left->left) < getHeight(root->left->right))
        {
            root->left = leftRotate(root->left);
        }
        root = rightRotate(root);
    }
    else if ((getHeight(root->right) - getHeight(root->left)) > 1)
    {
        if (getHeight(root->right->left) > getHeight(root->right->right))
        {
            root->right = rightRotate(root->right);
        }
        root = leftRotate(root);
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    return root;
}

node *insertNode(node *root, int val)
{
    if (root == NULL)
        root = retrace(newNode(val));
    else if (val > root->priority)
        root->right = insertNode(root->right, val);
    else if (val < root->priority)
        root->left = insertNode(root->left, val);

    return retrace(root);
}

node *deleteNode(node *root, int val)
{
    if (root == NULL)
        return root;

    if (val > root->priority)
        root->right = deleteNode(root->right, val);
    else if (val < root->priority)
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
            node *MinInRight = getMax(root->right);
            root->priority = MinInRight->priority;
            root->left = deleteNode(root->right, MinInRight->priority);
        }
    }

    return retrace(root);
}

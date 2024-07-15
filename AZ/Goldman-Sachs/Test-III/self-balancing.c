#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
} node;

int max(int x, int y)
{
    return (x > y) ? x : y;
}

node *newNode(int val)
{
    node *vertex = (node *)malloc(sizeof(node));
    vertex->data = val;
    vertex->left = NULL;
    vertex->right = NULL;

    return vertex;
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

node *insertNode(node *root, int val)
{
    if (root == NULL)
        root = retrace(newNode(val));
    else if (val > root->data)
        root->right = insertNode(root->right, val);
    else if (val < root->data)
        root->left = insertNode(root->left, val);

    return retrace(root);
}

void printTree(node *root) // Pre-Order Traversal
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    printTree(root->left);
    printTree(root->right);
    free(root);
}

void solve(){
    int wt, flag;
    node* root = NULL;
    while(1){
        scanf("%d %d",&wt,&flag);
        root = insertNode(root,wt);
        if(flag==0) break;
    }

    printTree(root);
    printf("\n");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
}
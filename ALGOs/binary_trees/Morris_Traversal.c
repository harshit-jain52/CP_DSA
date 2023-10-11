#include <stdio.h>
#include <stdlib.h>

// Threaded Binary Tree

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

void inOrder(node *root) // left-curr-right
{
    node *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL) // can't go left, so print value and go right
        {
            printf("%d ", curr->data);
            curr = curr->right;
        }
        else
        {
            node *prev = curr->left;

            while (prev->right != NULL && prev->right != curr) // go right in left subtree until either NULL or a thread is encountered
            {
                prev = prev->right;
            }
            if (prev->right == NULL) // create thread
            {
                prev->right = curr;
                curr = curr->left;
            }
            else // remove thread (left subtree has been traversed)
            {
                prev->right = NULL;
                printf("%d ", curr->data);
                curr = curr->right;
            }
        }
    }
}

void preOrder(node *root) // curr-left-right
{
    node *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL) // can't go left, so print value and go right
        {
            printf("%d ", curr->data);
            curr = curr->right;
        }
        else
        {
            node *prev = curr->left;

            while (prev->right != NULL && prev->right != curr) // go right until either NULL or a thread is encountered
            {
                prev = prev->right;
            }
            if (prev->right == NULL) // create thread (after this we traverse left subtree)
            {
                prev->right = curr;
                printf("%d ", curr->data); // the line different from inOrder
                curr = curr->left;
            }
            else // remove thread
            {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
}

void flattenBT(node *root) // Binary Tree to Linked List in pre-order
{
    node *curr = root;

    while (curr)
    {
        if (curr->left)
        {
            node *prev = curr->left;
            while (prev->right)
            {
                prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}
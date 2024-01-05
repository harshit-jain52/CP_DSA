#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *makeNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node *));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

Node *findMiddleNode(Node *head)
{
    Node *slowptr = head;
    Node *fastptr = head->next;

    while (fastptr && fastptr->next)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }

    return slowptr;
}

Node *mergeTwoLL(Node *head1, Node *head2)
{
    Node *dummyHead = makeNode(-1);
    Node *mover1 = head1, *mover2 = head2;
    Node *merger = dummyHead;

    while (mover1 && mover2)
    {
        if (mover1->data < mover2->data)
        {
            merger->next = mover1;
            merger = merger->next;
            mover1 = mover1->next;
        }
        else
        {
            merger->next = mover2;
            merger = merger->next;
            mover2 = mover2->next;
        }
    }

    if (mover1)
        merger->next = mover1;
    else
        merger->next = mover2;

    return dummyHead->next;
}

Node *mergeSortLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *mid = findMiddleNode(head);
    Node *left = head, *right = mid->next;
    mid->next = NULL;

    left = mergeSortLL(left);
    right = mergeSortLL(right);

    return mergeTwoLL(left, right);
}

// TC: O((N + N/2)logN)
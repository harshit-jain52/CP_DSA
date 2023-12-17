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

Node *arrayToLL(int arr[], int sz) // O(N)
{
    if (sz <= 0)
        return NULL;

    Node *head = makeNode(arr[0]);
    Node *mover = head;
    for (int i = 1; i < sz; i++)
    {
        Node *tmp = makeNode(arr[i]);
        mover->next = tmp;
        mover = tmp;
    }

    return head;
}

void printLL(Node *head) // O(N)
{
    Node *mover = head;
    while (mover)
    {
        printf("%d ", mover->data);
        mover = mover->next;
    }
}

int lengthOfLL(Node *head) // O(N)
{
    int len = 0;
    Node *mover = head;
    while (mover)
    {
        len++;
        mover = mover->next;
    }

    return len;
}

int searchinLL(Node *head, int value) // O(N)
{
    Node *mover = head;

    while (mover)
    {
        if (mover->data == value)
            return 1;

        mover = mover->next;
    }

    return 0;
}

Node *deleteHead(Node *head) // O(1);
{
    if (head == NULL)
        return head;

    Node *tmp = head;
    head = head->next;
    free(tmp);

    return head;
}

Node *deleteTail(Node *head) // O(N)
{
    if (head == NULL)
        return head;
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    Node *mover = head;
    while (mover->next->next)
        mover = mover->next;

    Node *tail = mover->next;
    mover->next = NULL;
    free(tail);

    return head;
}

Node *deletePosition(Node *head, int pos) // O(N)
{
    if (head == NULL)
        return head;

    if (pos == 1)
    {
        Node *tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }

    Node *tmp = head;
    Node *prev = NULL;

    int ct = 0;
    while (tmp)
    {
        ct++;
        if (ct == pos)
        {
            prev->next = tmp->next;
            free(tmp);
            break;
        }
        prev = tmp;
        tmp = tmp->next;
    }

    return head;
}

Node *deleteValue(Node *head, int val) // O(N)
{
    if (head == NULL)
        return head;

    if (head->data == val)
    {
        Node *tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }

    Node *tmp = head;
    Node *prev = NULL;

    while (tmp)
    {
        if (tmp->data == val)
        {
            prev->next = tmp->next;
            free(tmp);
            break;
        }
        prev = tmp;
        tmp = tmp->next;
    }

    return head;
}

Node *insertHead(Node *head, int el) // O(1)
{
    Node *newNode = makeNode(el);
    newNode->next = head;
    return newNode;
}

Node *insertTail(Node *head, int el) // O(N)
{
    if (head == NULL)
        return makeNode(el);

    Node *mover = head;
    while (mover->next)
        mover = mover->next;

    mover->next = makeNode(el);

    return head;
}

Node *insertPosition(Node *head, int el, int pos) // O(N)
{
    if (pos == 1)
    {
        Node *newNode = makeNode(el);
        newNode->next = head;
        return newNode;
    }

    Node *tmp = head;

    int ct = 0;
    while (tmp)
    {
        ct++;
        if (ct == pos - 1)
        {
            Node *newNode = makeNode(el);
            newNode->next = tmp->next;
            tmp->next = newNode;
            break;
        }
    }

    return head;
}

Node *insertValue(Node *head, int el, int val) // insert el before val; O(N)
{
    if (head == NULL)
        return head;

    if (head->data == val)
    {
        Node *newNode = makeNode(el);
        newNode->next = head;
        return newNode;
    }

    Node *tmp = head;
    while (tmp->next)
    {
        if (tmp->next->data == val)
        {
            Node *newNode = makeNode(el);
            newNode->next = tmp->next;
            tmp->next = newNode;
            break;
        }
    }

    return head;
}

Node *findMiddleNode(Node *head) // Tortoise-Hare Method
{
    Node *fastptr = head;
    Node *slowptr = head;

    while (fastptr && fastptr->next)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }

    return slowptr;
}

int detectLoop(Node *head)
{
    Node *fastptr = head;
    Node *slowptr = head;

    while (fastptr && fastptr->next)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;

        if (slowptr == fastptr)
            return 1;
    }

    return 0;
}

Node *startingNodeOfLoop(Node *head)
{
    int loopFound = 0;

    Node *fastptr = head;
    Node *slowptr = head;

    while (fastptr && fastptr->next)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;

        if (slowptr == fastptr)
        {
            loopFound = 1;
            break;
        }
    }

    if (!loopFound)
        return NULL;

    slowptr = head;

    while (slowptr != fastptr)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next;
    }

    return slowptr;
}

int lengthOfLoop(Node *head)
{
    int loopFound = 0;

    Node *fastptr = head;
    Node *slowptr = head;

    while (fastptr && fastptr->next)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;

        if (slowptr == fastptr)
        {
            loopFound = 1;
            break;
        }
    }

    if (!loopFound)
        return 0;

    int len = 1;
    fastptr = fastptr->next;
    while (fastptr != slowptr)
    {
        len++;
        fastptr = fastptr->next;
    }

    return len;
}
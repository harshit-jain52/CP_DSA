#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node *makeNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

Node *arrayToDLL(int arr[], int sz) // O(N)
{
    if (sz <= 0)
        return NULL;

    Node *head = makeNode(arr[0]);
    Node *mover = head;
    for (int i = 1; i < sz; i++)
    {
        Node *tmp = makeNode(arr[i]);
        tmp->prev = mover;
        mover->next = tmp;
        mover = tmp;
    }

    return head;
}

Node *deleteHead(Node *head) // O(1)
{
    if (head == NULL)
        return head;

    Node *back = head;
    head = head->next;

    if (head)
        head->prev = NULL;

    free(back);
    return head;
}

Node *deleteTail(Node *head) // O(1)
{
    if (head == NULL)
        return head;
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    Node *tail = head;
    while (tail->next)
        tail = tail->next;

    Node *back = tail->prev;
    back->next = NULL;
    free(tail);

    return head;
}

Node *deletePosition(Node *head, int pos) // O(N)
{
    if (head == NULL)
        return head;

    Node *tmp = head;

    int ct = 0;
    while (tmp)
    {
        ct++;
        if (ct == pos)
            break;
        tmp = tmp->next;
    }

    if (ct < pos)
        return head;

    Node *back = tmp->prev;
    Node *front = tmp->next;

    if (back == NULL && front == NULL)
    {
        free(tmp);
        return NULL;
    }

    if (back == NULL)
        return deleteHead(head);

    if (front == NULL)
        return deleteTail(head);

    back->next = front;
    front->prev = back;
    free(tmp);
    return head;
}

void deleteNode(Node *node) // node can't be head; O(1)
{
    Node *back = node->prev;
    Node *front = node->next;

    back->next = front;

    if (front != NULL)
        front->prev = back;

    free(node);
}

Node *insertBeforeHead(Node *head, int el) // O(1)
{
    Node *newHead = makeNode(el);
    newHead->next = head;
    if (head)
        head->prev = newHead;

    return newHead;
}

Node *insertAfterTail(Node *head, int el) // O(N)
{
    if (head == NULL)
        return makeNode(el);

    Node *tail = head;
    while (tail->next)
    {
        tail = tail->next;
    }

    Node *newTail = makeNode(el);
    newTail->prev = tail;
    tail->next = newTail;

    return head;
}

Node *insertBeforePos(Node *head, int el, int pos) // O(N)
{
    if (pos == 1)
        return insertBeforeHead(head, el);

    Node *tmp = head;
    int ct = 0;
    while (tmp->next)
    {
        ct++;
        if (ct == pos)
            break;
        tmp = tmp->next;
    }

    if (ct < pos)
        return head;

    Node *back = tmp->prev;
    Node *newNode = makeNode(el);
    newNode->prev = back;
    newNode->next = tmp;
    back->next = newNode;
    tmp->prev = newNode;

    return head;
}

void *insertBeforeNode(Node *node, int el) // node can't be head; O(1)
{
    Node *back = node->prev;
    Node *newNode = makeNode(el);
    newNode->next = node;
    newNode->prev = back;
    back->next = newNode;
    node->prev = newNode;
}

Node *reverseDLL(Node *head)
{
    Node *cur = head;
    while (cur)
    {
        Node *back = cur->prev;
        Node *front = cur->next;

        cur->next = back;
        cur->prev = front;

        if (front == NULL)
            break;
        cur = front;
    }

    return cur;

    // if (head == NULL || head->next == NULL)
    //     return head;

    // Node *back = NULL;
    // Node *cur = head;

    // while (cur)
    // {
    //     back = cur->prev;

    //     cur->prev = cur->next;
    //     cur->next = back;

    //     cur = cur->prev;
    // }

    // return back->prev;
}

Node *deleteAllOccurences(Node *head, int el)
{
    Node *tmp = head;

    while (tmp)
    {
        Node *back = tmp->prev;
        Node *front = tmp->next;

        if (tmp->data == el)
        {
            if (back)
                back->next = front;
            else
                head = front;

            if (front)
                front->prev = back;

            free(tmp);
        }
        tmp = front;
    }

    return head;
}
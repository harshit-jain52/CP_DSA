#include <stdio.h>
#include <stdlib.h>

// Priority Queue: Sorted List Implementation

typedef struct node
{
    int priority; // lower value -> higher priority
    struct node *next;
} node;

node *createNode(int p)
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp->priority = p;
    tmp->next = NULL;

    return tmp;
}

int isEmpty(node *head)
{
    return head == NULL;
}

int front(node *head) // highest priority element; O(1)
{
    if (isEmpty(head))
    {
        printf("\nfront: Empty Priority Queue\n");
        exit(0);
    }

    return head->priority;
}

node *pop(node *head) // remove highest priority element; O(1)
{
    if (isEmpty(head))
    {
        printf("\npop: Empty Priority Queue\n");
        exit(0);
    }

    node *temp = head;
    head = head->next;
    free(temp);

    return head;
}

node *push(node *head, int newNum) // push new element at correct place; O(N)
{
    node *newNode = createNode(newNum);

    if (head->priority > newNum) // insertion at start of list
    {
        newNode->next = head;
        return newNode;
    }
    else
    {
        node *curr = head;
        node *prev = head;

        while (curr->priority < newNum)
        {
            if (curr->next != NULL)
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                curr->next = newNode; // insertion at end of list
                return head;
            }
        }

        newNode->next = prev->next;
        prev->next = newNode;

        return head;
    }
}

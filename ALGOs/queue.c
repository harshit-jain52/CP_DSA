#include <stdio.h>
#define MAXLEN 10000
#define datatype int

typedef struct
{
    datatype arr[MAXLEN]; // maximum size of the queue is MAXLEN-1
    int front;
    int back;
} queue;

queue init()
{
    queue Q;

    Q.front = 0;
    Q.back = MAXLEN - 1;

    return Q;
}

int isEmpty(queue Q)
{
    return (Q.front == (Q.back + 1) % MAXLEN);
}

int isFull(queue Q)
{
    return (Q.front == (Q.back + 2) % MAXLEN);
}

datatype front(queue Q)
{
    if (isEmpty(Q))
    {
        printf("\nfront: Empty Queue\n");
        return NULL;
    }

    return Q.arr[Q.front];
}

queue enqueue(queue Q, datatype elem)
{
    if (isFull(Q))
    {
        printf("\nenqueue: Full Queue\n");
        return Q;
    }

    Q.back = (++Q.back) % MAXLEN;
    Q.arr[Q.back] = elem;
    return Q;
}

queue dequeue(queue Q)
{
    if (isEmpty(Q))
    {
        printf("\ndequeue: Empty Queue\n");
        return Q;
    }

    Q.front = (++Q.front) % MAXLEN;
    return Q;
}

/*
void printQueue(queue Q)
{
    if (isEmpty(Q))
        return;

    int i = Q.front;

    while (1)
    {
        printf("%d ", Q.arr[i]);
        if (i == Q.back)
            break;
        i = (++i) % MAXLEN;
    }
}
*/
#include <stdio.h>
#define MAXLEN 10000
#define datatype int

typedef struct
{
    datatype arr[MAXLEN];
    int top;
} stack;

stack init()
{
    stack S;

    S.top = -1;
    return S;
}

int isEmpty(stack S)
{
    return (S.top == -1);
}

int isFull(stack S)
{
    return (S.top == MAXLEN - 1);
}

datatype top(stack S)
{
    if (isEmpty(S))
    {
        printf("\ntop: Empty Stack\n");
        return NULL;
    }

    return S.arr[S.top];
}

stack push(stack S, datatype elem)
{
    if (isFull(S))
    {
        printf("\npush: Full Stack\n");
        return S;
    }

    S.arr[++S.top] = elem;
    return S;
}

stack pop(stack S)
{
    if (isEmpty(S))
    {
        printf("\npop: Empty Stack\n");
        return S;
    }

    --S.top;
    return S;
}

/*
void printStack(stack S)
{
    int i;
    for (i = S.top; i >= 0; i--)
    {
        printf("%d ", S.arr[i]);
    }
}
*/
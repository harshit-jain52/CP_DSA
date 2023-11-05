#include <stdio.h>
#include <stdlib.h>

// Graph Implementation
typedef struct node
{
    int data;
    struct node *next;

} node;

typedef struct graph
{
    int vnum;
    node **adjList;
    int *vis;
} graph;

node *createNode(int val);
graph *createGraph(int vertices);
void addEdge(graph *g, int src, int dest);

// Queue Implementation
#define MAXLEN 10000
#define datatype int

typedef struct
{
    datatype arr[MAXLEN];
    int front;
    int back;
} queue;

queue init();
int isEmpty(queue Q);
datatype front(queue Q);
queue enqueue(queue Q, datatype elem);
queue dequeue(queue Q);

// Breadth First Search
void BFS(graph *g, int src, int *dist)
{
    dist[src] = 0;
    g->vis[src] = 1;

    queue q = init();
    q = enqueue(q, src);

    int cur_v, child_v;
    while (!isEmpty(q))
    {
        cur_v = front(q);
        q = dequeue(q);

        node* trav = g->adjList[cur_v];
        while (trav != NULL)
        {
            child_v = trav->data;

            if (g->vis[child_v] != 1)
            {
                g->vis[child_v] = 1;
                dist[child_v] = dist[cur_v] + 1;
                q = enqueue(q, child_v);
            }
            trav = trav->next;
        }
    }
}

int main()
{
}

node *createNode(int val)
{
    node *vertex = (node *)malloc(sizeof(node));
    vertex->data = val;
    vertex->next = NULL;
    
    return vertex;
}

graph *createGraph(int vertices)
{
    graph *g = (graph *)malloc(sizeof(graph));

    g->vnum = vertices;
    g->adjList = (node **)malloc((vertices + 1) * sizeof(node *));
    g->vis = (int *)malloc((vertices + 1) * sizeof(int));

    int i;
    for (i = 1; i <= vertices; i++)
    {
        g->adjList[i] = NULL;
        g->vis[i] = 0;
    }

    return g;
}

void addEdge(graph *g, int src, int dest)
{
    node *newNode = createNode(dest);
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;
}

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

datatype front(queue Q)
{
    return Q.arr[Q.front];
}

queue enqueue(queue Q, datatype elem)
{
    Q.back = (++Q.back) % MAXLEN;
    Q.arr[Q.back] = elem;
    return Q;
}

queue dequeue(queue Q)
{
    Q.front = (++Q.front) % MAXLEN;
    return Q;
}

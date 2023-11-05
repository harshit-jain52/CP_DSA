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
    int *recur_stack;
    int *inDegree;
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

// Detect Cycle

int detectCycle(graph *g, int v)
{
    g->vis[v] = 1;
    g->recur_stack[v] = 1;
    int ans = 0;

    int child_v;
    node *trav = g->adjList[v];
    while (trav != NULL)
    {
        child_v = trav->data;

        if (g->recur_stack[child_v] == 1)
        {
            ans = 1;
            break;
        }

        if (g->vis[child_v] == 0)
        {
            ans |= detectCycle(g, child_v);
        }

        trav = trav->next;
    }

    g->recur_stack[v] = 0;
    return ans;
}

int isCyclePresent(graph *g, int n)
{
    int i, ans = 0;
    for (i = 1; i <= n; i++)
    {
        if (g->vis[i] == 0)
        {
            ans |= detectCycle(g, i);
        }
    }

    return ans;
}

// Topological Sort using Kahn's Algo
void kahn(graph *g, int n, int *topoSort)
{
    if (isCyclePresent(g, n))
    {
        printf("\nNot a Directed Acyclic Graph\n");
        return;
    }

    queue q = init();
    int i, idx = 0;

    for (i = 1; i <= n; i++)
        if (g->inDegree[i] == 0)
            q = enqueue(q, i);

    int cur_v, next_v;
    while (!isEmpty(q))
    {
        cur_v = front(q);
        q = dequeue(q);

        topoSort[idx++] = cur_v;

        node *trav = g->adjList[cur_v];
        while (trav != NULL)
        {
            next_v = trav->data;

            g->inDegree[next_v]--;
            if (g->inDegree[next_v] == 0)
                q = enqueue(q, next_v);

            trav = trav->next;
        }
    }
}

// Topological Sort Using DFS
void DFS(graph *g, int v, int *topoSort, int *idx)
{
    g->vis[v] = 1;

    int child_v;
    node *trav = g->adjList[v];

    while (trav != NULL)
    {
        child_v = trav->data;
        if (g->vis[child_v] != 1)
        {
            DFS(g, child_v, topoSort, idx);
        }
        trav = trav->next;
    }

    topoSort[*idx] = v;
    *idx = *idx + 1;
}

void reverse(int *arr, int sz)
{
    int i = 0, j = sz - 1, tmp;

    while (i < j)
    {
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        i++;
        j--;
    }
}

void topoSortDFS(graph *g, int n, int *topoSort)
{
    if (isCyclePresent(g, n))
    {
        printf("\nNot a Directed Acyclic Graph\n");
        return;
    }

    int i, idx = 0;
    for (i = 1; i <= n; i++)
        g->vis[i] = 0;

    for (i = 1; i <= n; i++)
    {
        if (g->vis[i] == 0)
            DFS(g, i, topoSort, &idx);
    }

    reverse(topoSort, idx);
}

int main()
{
    int n, m, i;
    int x, y;

    scanf("%d %d", &n, &m);

    graph *g = createGraph(n);

    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        addEdge(g, x, y);
    }

    int *sequence = (int *)malloc((n + 1) * sizeof(int));

    kahn(g, n, sequence);
    // topoSortDFS(g, n, sequence);
    
    for (i = 0; i < n; i++)
    {
        printf("%d ", sequence[i]);
    }
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
    g->recur_stack = (int *)malloc((vertices + 1) * sizeof(int));
    g->inDegree = (int *)malloc((vertices + 1) * sizeof(int));

    int i;
    for (i = 1; i <= vertices; i++)
    {
        g->adjList[i] = NULL;
        g->vis[i] = 0;
        g->recur_stack[i] = 0;
        g->inDegree[i] = 0;
    }

    return g;
}

void addEdge(graph *g, int src, int dest)
{
    node *newNode = createNode(dest);
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;
    g->inDegree[dest]++;
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

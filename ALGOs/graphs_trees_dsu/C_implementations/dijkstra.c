#include <stdio.h>
#include <stdlib.h>

// Weighted Graph Implementation
typedef struct node
{
    int data;
    int weight;
    struct node *next;

} node;

typedef struct graph
{
    int vnum;
    node **adjList;
    int *vis;
} graph;

node *createNode(int val, int wt);
graph *createGraph(int vertices);
void addEdge(graph *g, int src, int dest, int weight);

// Min-Heap Implementation

typedef struct
{
    int vertex;
    int reachDist;
} pair;

void swap(pair *x, pair *y)
{
    pair tmp = *x;
    *x = *y;
    *y = tmp;
}

int size = 0;
int Root() { return 1; }
int parent(int i) { return i / 2; }
int leftChild(int i) { return 2 * i; }
int rightChild(int i) { return 2 * i + 1; }
int hasParent(int i) { return i != Root(); }
int isValidNode(int i) { return i <= size; }
pair front(pair H[]) { return H[Root()]; }
void shiftUp(pair H[], int idx);
void shiftDown(pair H[], int idx);
void push(pair H[], pair newPair);
void pop(pair H[]);

// Dijkstra
const int INF = 1e9;

void dijkstra(graph *g, int src, int n, int *dist)
{
    int i;
    for (i = 1; i <= n; i++)
        dist[i] = INF;

    pair *pq = (pair *)malloc((n + 1) * sizeof(pair));
    size = 0;

    pair tmp = {src, 0};
    dist[src] = 0;
    push(pq, tmp);

    int curr_v, curr_dist, child_v, wt;
    node *trav;

    while (size > 0)
    {
        tmp = front(pq);
        curr_v = tmp.vertex, curr_dist = tmp.reachDist;
        pop(pq);

        if (g->vis[curr_v] == 1)
            continue;

        g->vis[curr_v] = 1;

        trav = g->adjList[curr_v];
        while (trav != NULL)
        {
            child_v = trav->data;
            wt = trav->weight;

            if (curr_dist + wt < dist[child_v])
            {
                dist[child_v] = curr_dist + wt;
                tmp = (pair){child_v, dist[child_v]};
                push(pq, tmp);
            }
            trav = trav->next;
        }
    }
}

int main()
{
    int n, m, i;
    int x, y, wt;

    scanf("%d %d", &n, &m);

    graph *g = createGraph(n);

    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &x, &y, &wt);
        addEdge(g, x, y, wt);
    }

    int *dist = (int *)malloc((n + 1) * sizeof(int));
    dijkstra(g, 1, n, dist);

    for (i = 1; i <= n; i++)
    {
        printf("%d ", dist[i]);
    }
}

node *createNode(int val, int wt)
{
    node *vertex = (node *)malloc(sizeof(node));
    vertex->data = val;
    vertex->weight = wt;
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

void addEdge(graph *g, int src, int dest, int weight)
{
    node *newNode = createNode(dest, weight);
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;
}

void shiftUp(pair H[], int idx)
{
    while (hasParent(idx) && (H[parent(idx)].reachDist > H[idx].reachDist))
    {
        swap(&H[parent(idx)], &H[idx]);
        idx = parent(idx);
    }
}

void shiftDown(pair H[], int idx)
{
    while (isValidNode(leftChild(idx)))
    {
        int child = leftChild(idx);

        if (isValidNode(rightChild(idx)) && H[rightChild(idx)].reachDist < H[leftChild(idx)].reachDist)
            child = rightChild(idx);

        if (H[idx].reachDist > H[child].reachDist)
            swap(&H[idx], &H[child]);
        else
            break;

        idx = child;
    }
}

void push(pair H[], pair newPair)
{
    H[++size] = newPair;
    shiftUp(H, size);
}

void pop(pair H[])
{
    H[Root()] = H[size--];
    shiftDown(H, Root());
}

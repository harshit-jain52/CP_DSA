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

void DFS(graph *g, int v)
{
    g->vis[v] = 1;
    int child_v;
    node *trav = g->adjList[v];

    while (trav != NULL)
    {
        child_v = trav->data;
        if (g->vis[child_v] != 1)
        {
            DFS(g, child_v);
        }
        trav = trav->next;
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
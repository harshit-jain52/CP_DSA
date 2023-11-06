#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

typedef struct
{
    int u;
    int v;
    int wt;
} edge;

// Sorting Implementation
void mergeSort(edge arr[], int l, int r);
void merge(edge arr[], int l, int m, int r);

// DSU Implementation
typedef struct
{
    int *parent;
    int *rank;
} dsu;

void makeSet(int u, dsu *d);
int find(int u, dsu *d);
void unionByRank(int u, int v, dsu *d);
dsu *createDSU(int n);

int kruskal(edge *edges, int n, int m)
{   
    mergeSort(edges, 0, m - 1);
    dsu *d = createDSU(n);

    int mst_cost = 0;
    int i, a, b, wt;
    edge e;
    for (i = 0; i < m; i++)
    {
        e = edges[i];
        a = e.u, b = e.v, wt = e.wt;

        if (find(a, d) == find(b, d))
            continue;

        unionByRank(a, b, d);
        mst_cost += wt;
    }

    for (i = 1; i <= n; i++)
    {
        if (find(i, d) != find(1, d))
            return -1;
    }

    return mst_cost;
}

int main()
{
    int n, m, i;
    int x, y, w;

    scanf("%d %d", &n, &m);

    edge *edges = (edge *)malloc(m * sizeof(edge));

    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &x, &y, &w);
        edges[i] = (edge){x, y, w}; // Assume Undirected
    }

    int mst_cost = kruskal(edges, n, m);

    if (mst_cost == -1)
        printf("Spanning Tree not possible");
    else
        printf("%d", mst_cost);
}

void makeSet(int u, dsu *d)
{
    d->parent[u] = u;
    d->rank[u] = 1;
}

int find(int u, dsu *d)
{
    if (u == d->parent[u])
        return u;

    return d->parent[u] = find(d->parent[u], d);
}

void unionByRank(int u, int v, dsu *d)
{
    u = find(u, d);
    v = find(v, d);

    if (u == v)
        return;

    if (d->rank[u] < d->rank[v])
        swap(&u, &v);

    d->parent[v] = u;
    d->rank[u] += d->rank[v];
}

dsu *createDSU(int n)
{
    dsu *d = (dsu *)malloc((n + 1) * sizeof(dsu));

    d->parent = (int *)malloc((n + 1) * sizeof(int));
    d->rank = (int *)malloc((n + 1) * sizeof(int));

    int i;
    for (i = 1; i <= n; i++)
        makeSet(i, d);
    
    return d;
}

void merge(edge arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int i, j, k;

    edge *left = (edge *)malloc(n1 * sizeof(edge));
    edge *right = (edge *)malloc(n2 * sizeof(edge));

    for (i = 0; i < n1; i++)
        left[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (left[i].wt <= right[j].wt)
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void mergeSort(edge arr[], int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    merge(arr, l, mid, r);
}
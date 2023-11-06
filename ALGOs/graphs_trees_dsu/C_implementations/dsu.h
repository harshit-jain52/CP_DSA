#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *parent;
    int *rank;
} dsu;

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
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

    return d->parent[u] = find(d->parent[u], d); // Path Compression
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
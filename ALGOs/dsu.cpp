#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
int set_size[N];
int depth[N];

void make(int v)
{
    parent[v] = v;
    set_size[v] = 1;
    depth[v] = 0;
}

int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]); // path compression
}

void unionBySize(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (set_size[a] < set_size[b])
            swap(a, b);

        parent[b] = a;
        set_size[a] += set_size[b];
    }
}

void unionByDepth(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (depth[a] < depth[b])
            swap(a, b);

        parent[b] = a;

        if (depth[a] == depth[b])
            depth[a]++;
    }
}

//  Amortrized Time Complexity O(α(n)); α(n)--> inverse Ackermann function: grows verrrrry slowly
// Time complexity without path compression: O(log(n))
int main()
{
}
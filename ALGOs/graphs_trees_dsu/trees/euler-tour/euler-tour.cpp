// Flattening a tree into an array to easily query and update subtrees.

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int timer = 0;
vector<int> tree[N];
vector<int> startTime(N, 0);
vector<int> endTime(N, 0);

void euler_tour(int v, int par)
{
    startTime[v] = timer++;

    for (int child : tree[v])
    {
        if (child == par)
            continue;

        euler_tour(child, v);
    }
    endTime[v] = timer;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int root = 1;
    euler_tour(root, -1);

    int arr[n]; // Tree Traversal Array

    for (int i = 1; i <= n; i++)
        arr[startTime[i]] = i; // index of node in flattened array = startTime

    // subtree size (including node) = endTime - startTime
}
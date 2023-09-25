#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 2e5 + 5;

vector<int> tree[N];
int dist[N];

void dfs(int vertex, int par)
{
    dist[vertex] = dist[par] + 1;
    for (auto child : tree[vertex])
    {
        if (child == par)
            continue;
        dfs(child, vertex);
    }
}

void initialize(int root)
{
    dist[root] = 0;
    for (auto child : tree[root])
    {
        dfs(child, root);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    initialize(1);
    int maxdist = 0, deepest = -1;

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] > maxdist)
        {
            maxdist = dist[i];
            deepest = i;
        }
    }

    initialize(deepest);
    int diameter = 0;

    for (int i = 1; i <= n; i++)
        diameter = max(diameter, dist[i]);

    cout << diameter;
}
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e5 + 5;
int a[N];
ll sum;
vector<int> tree[N];
multiset<int> maxheap; // right half
multiset<int> minheap; // left half (including median)

void balanceHeaps()
{
    while (maxheap.size() > minheap.size())
    {
        int tmp = *(maxheap.begin());
        maxheap.erase(maxheap.begin());
        minheap.insert(-tmp);
    }

    while (minheap.size() - maxheap.size() > 1)
    {
        int tmp = -(*(minheap.begin()));
        minheap.erase(minheap.begin());
        maxheap.insert(tmp);
    }
}

void insert(int v)
{
    if ((minheap.empty() && (a[v] < *(maxheap.begin()))) || (a[v] <= abs(*(minheap.begin()))))
        minheap.insert(-a[v]);
    else
        maxheap.insert(a[v]);

    balanceHeaps();
}

void remove(int v)
{
    auto it = minheap.find(-a[v]);
    if (it != minheap.end())
    {
        minheap.erase(it);
        return;
    }

    it = maxheap.find(a[v]);
    maxheap.erase(it);

    balanceHeaps();
}

int median()
{
    return -(*(minheap.begin()));
}

void dfs(int v, int par)
{
    insert(v);
    int sz = maxheap.size() + minheap.size();
    if (sz & 1)
        sum += median();

    for (int child : tree[v])
    {
        if (child == par)
            continue;
        dfs(child, v);
    }
    remove(v);
}

void reset(int n)
{
    sum = 0;
    maxheap.clear();
    minheap.clear();
    for (int i = 1; i <= n; i++)
    {
        tree[i].clear();
        cin >> a[i];
    }
}

void solve()
{
    int n;
    cin >> n;
    reset(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0);
    cout << sum << endl;
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
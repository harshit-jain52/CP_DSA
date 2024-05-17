#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 5;

int n;
vector<int> g[N];
int subTreeSz[N];
vector<int> centroids;

void dfs(int v, int pp)
{
    subTreeSz[v] = 1;
    for (auto ch : g[v])
    {
        if (ch == pp)
            continue;

        dfs(ch, v);
        subTreeSz[v] += subTreeSz[ch];
    }

    bool isCentroid = true;
    for (auto ch : g[v])
    {
        if (ch != pp)
        {
            if (2 * subTreeSz[ch] > n)
                isCentroid = false;
        }
    }
    if (2 * (n - subTreeSz[v]) > n)
        isCentroid = false;

    if (isCentroid)
        centroids.push_back(v);
}

int main()
{
    FASTIO

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0);
    cout << centroids[0];
}
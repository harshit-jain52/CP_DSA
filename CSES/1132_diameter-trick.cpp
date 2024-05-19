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

vector<int> g[N];
vector<int> dist(N);

void dfs(int v, int pp, int dd)
{
    dist[v] = dd;

    for (auto ch : g[v])
    {
        if (ch != pp)
            dfs(ch, v, dd + 1);
    }
}

int main()
{
    FASTIO
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // find diameter ends
    dfs(1, 0, 0);
    int end1 = 1;
    for (int i = 2; i <= n; i++)
    {
        if (dist[end1] < dist[i])
            end1 = i;
    }

    dfs(end1, 0, 0);
    int end2 = 1;
    for (int i = 2; i <= n; i++)
    {
        if (dist[end2] < dist[i])
            end2 = i;
    }
    vector<int> dist1 = dist;
    dfs(end2, 0, 0);

    for (int i = 1; i <= n; i++)
        cout << max(dist1[i], dist[i]) << " ";
}
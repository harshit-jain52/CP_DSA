#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
#define sz(x) (int)(x).size()
const int M = 1e9 + 7;

// http://www.usaco.org/index.php?page=viewproblem2&cpid=491

const int N = 4e4 + 10;
const int INF = 1e7;

vector<int> g[N];

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (sz(name))
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void bfs(int src, vector<int> &lev)
{
    queue<int> q;
    q.push(src);
    lev[src] = 0;

    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop();

        for (int child : g[cur_v])
        {
            if (lev[child] == INF)
            {
                lev[child] = lev[cur_v] + 1;
                q.push(child);
            }
        }
    }
}

int main()
{
    setIO("piggyback");
    
    ll b, e, p;
    int n, m;

    cin >> b >> e >> p >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> lev1(n + 1, INF), lev2(n + 1, INF), levn(n + 1, INF);

    bfs(1, lev1);
    bfs(2, lev2);
    bfs(n, levn);

    ll mincost = 1e15;

    for (int i = 1; i <= n; i++)
    {
        mincost = min(mincost, b * lev1[i] + e * lev2[i] + p * levn[i]);
    }

    cout << mincost << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
set<int> g[N];
int color[N];
int par[N];
int vis[N];
vector<vector<int>> allCycles;
vector<vector<int>> connected;

void reset(int n)
{
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        color[i] = 0;
        par[i] = 0;
        vis[i] = 0;
    }
    allCycles.clear();
    connected.clear();
}

void dfs(int v, int p)
{
    if (color[v] == 2)
        return;

    if (color[v] == 1)
    {
        vector<int> cycle;

        int cur = p;
        cycle.push_back(cur);

        while (cur != v)
        {
            cur = par[cur];
            cycle.push_back(cur);
        }

        allCycles.push_back(cycle);
        return;
    }

    par[v] = p;
    color[v] = 1;

    for (int child : g[v])
    {
        if (child == par[v])
            continue;

        dfs(child, v);
    }

    color[v] = 2;
}

void dfs2(int v, vector<int> &vec)
{
    vis[v] = 1;
    vec.push_back(v);

    for (auto child : g[v])
    {
        if (vis[child])
            continue;
        dfs2(child, vec);
    }
}

bool solve()
{
    int n, m;
    cin >> n >> m;

    vector<bool> stable(n + 1, false);

    reset(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
        {
            stable[a] = true;
            continue;
        }

        g[a].insert(b);
        g[b].insert(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            vector<int> tmp;
            dfs2(i, tmp);
            connected.push_back(tmp);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
            dfs(i, 0);
    }

    for (auto vec : connected)
    {
        if (vec.size() == 1 && !stable[vec[0]])
            return false;

        if (vec.size() == 2)
        {
            if (stable[0] || stable[1])
            {
                stable[vec[0]] = stable[vec[1]] = true;
            }
            else
                return false;
        }
    }

    for (auto vec : allCycles)
    {
        if (vec.size() % 2 == 1)
        {
            for (auto num : vec)
            {
                stable[num] = true;
            }
        }
    }
    for (auto vec : allCycles)
    {
        if (vec.size() % 2 == 0)
        {
            bool isthere = false;
            for (auto num : vec)
            {
                isthere |= stable[num];
            }
            if (isthere == true)
            {
                for (auto num : vec)
                    stable[num] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!stable[i])
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        if (solve())
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sz(x) (int)(x).size()
typedef long long ll;
const int N = 1e5 + 10;

// http://www.usaco.org/index.php?page=viewproblem2&cpid=838#

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);

    if (sz(name))
    {

        freopen((name + ".in").c_str(), "r", stdin);

        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int n, m;
vector<vector<int>> obs;
vector<int> g[N];
vector<bool> visited;
vector<bool> recur_stack;
vector<int> ans;
vector<int> indegree;

bool detectCycle(int vertex)
{
    recur_stack[vertex] = 1;
    visited[vertex] = true;
    bool ans = false;

    for (auto child : g[vertex])
    {
        if (recur_stack[child])
        {
            ans = true;
            break;
        }
        if (visited[child])
            continue;

        ans |= detectCycle(child);
    }

    recur_stack[vertex] = 0;

    return ans;
}

bool isCycle(int n)
{
    visited.assign(n + 1, false);
    recur_stack.assign(n + 1, false);

    bool final = false;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            final |= detectCycle(i);
    }

    return final;
}

bool check(int idx)
{
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
    }

    for (int i = 0; i <= idx; i++)
    {
        for (int j = 0; j < obs[i].size() - 1; j++)
        {
            g[obs[i][j]].push_back(obs[i][j + 1]);
        }
    }

    return !isCycle(n);
}

void kahn(int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            pq.push(i);
    }

    while (!pq.empty())
    {
        int cur_v = pq.top();
        pq.pop();

        ans.push_back(cur_v);

        for (int next : g[cur_v])
        {
            indegree[next]--;

            if (indegree[next] == 0)
                pq.push(next);
        }
    }
}

void ordering(int idx)
{
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
    }

    indegree.assign(n + 1, 0);
    for (int i = 0; i <= idx; i++)
    {
        for (int j = 0; j < obs[i].size() - 1; j++)
        {
            g[obs[i][j]].push_back(obs[i][j + 1]);
            indegree[obs[i][j + 1]]++;
        }
    }

    kahn(n);
}

int main()
{
    setIO("milkorder");
    cin >> n >> m;
    obs.resize(m);
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        obs[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            cin >> obs[i][j];
        }
    }

    int lo = 0, hi = m - 1, mid;

    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;

        if (check(mid))
            lo = mid;
        else
            hi = mid - 1;
    }

    int x;
    if (check(hi))
        x = hi;
    else if (check(lo))
        x = lo;
    else
        x = -1;

    ordering(x);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << (i != n - 1 ? " " : "");
    }
}
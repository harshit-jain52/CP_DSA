#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
typedef long long ll;

const int N = 1e5 + 10;
const int UNVISITED = -1;
vector<int> graph[N];
vector<int> ids(N, UNVISITED);
vector<int> lo(N, INF);
vector<bool> onStack(N, false);
vector<pair<int, int>> bridges;

int id = 1;

vector<int> tree[N];
ll dp[N];

void dfs(int v, stack<int> &st)
{
    st.push(v);
    onStack[v] = true;
    ids[v] = lo[v] = id++;

    for (int child : graph[v])
    {
        if (ids[child] == UNVISITED)
            dfs(child, st);

        if (onStack[child])
        {
            lo[v] = min(lo[v], lo[child]);
        }
        else
            bridges.push_back({v, child}); // Bridge
    }

    if (ids[v] == lo[v])
    {
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            onStack[node] = false;
            lo[node] = ids[v];
            if (node == v)
                break;
        }
    }
}

ll treedfs(int v, vector<ll> &sccSum)
{
    if (dp[v] != -1)
        return dp[v];

    ll ans = sccSum[v];
    for (int child : tree[v])
    {
        ans = max(ans, sccSum[v] + treedfs(child, sccSum));
    }

    return dp[v] = ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    ll coins[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> coins[i];

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
    {
        if (ids[i] == UNVISITED)
        {
            stack<int> s;
            dfs(i, s);
        }
    }

    int ct = 1;
    map<int, int> mp;

    for (int i = 1; i <= n; i++)
    {
        if (mp.find(lo[i]) == mp.end())
            mp[lo[i]] = ct++;
    }

    vector<ll> sccSum(ct, 0);
    for (int i = 1; i <= n; i++)
    {
        sccSum[mp[lo[i]]] += coins[i];
    }

    // for (int i = 1; i < ct; i++)
    // {
    //     cout << sccSum[i] << " ";
    // }

    set<pair<int, int>> br;
    for (auto it : bridges)
    {
        br.insert({mp[lo[it.first]], mp[lo[it.second]]});
    }

    // now we have a directed acyclic graph with each scc of original graph as a vertex and bridges as edges
    memset(dp, -1, sizeof(dp));

    for (auto it : br)
    {
        tree[it.first].push_back(it.second);
    }

    ll final = 0;
    for (int i = 1; i < ct; i++)
    {
        final = max(final, treedfs(i, sccSum));
    }

    cout << final;
}
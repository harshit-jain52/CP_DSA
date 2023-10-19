#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

const int N = 1e5 + 10;
const int UNVISITED = -1;
vector<int> graph[N];
vector<int> ids(N, UNVISITED);
vector<int> lo(N, INF);
vector<bool> onStack(N, false);
int id = 1;

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
            lo[v] = min(lo[v], lo[child]);
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

int main()
{
    int n, m;
    cin >> n >> m;
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

    cout << ct - 1 << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << mp[lo[i]] << " ";
    }
}
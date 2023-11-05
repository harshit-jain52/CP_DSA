#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

vector<pair<int, ll>> g[N]; // weighted graph
vector<bool> taken(N, false);

void process(int v, set<pair<ll, int>> &st)
{
    taken[v] = true;
    for (auto child : g[v])
    {
        int child_v = child.first;
        ll wt = child.second;

        if (!taken[child_v])
            st.insert({wt, child_v});
    }
}

ll prim()
{
    ll mst_cost = 0;
    set<pair<ll, int>> st; // weight,node
    process(1, st);

    while (st.size() > 0)
    {
        auto node = *st.begin();
        int v = node.second;
        ll w = node.first;
        st.erase(st.begin());

        if (!taken[v])
        {
            mst_cost += w;
            process(v, st);
        }
    }

    return mst_cost;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        ll wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt});
        g[y].push_back({x, wt});
    }

    cout << prim();
}
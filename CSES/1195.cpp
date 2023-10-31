#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const ll INF = 1e15;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, ll>> g[n + 1];
    vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));
    vector<vector<bool>> vis(n + 1, vector<bool>(2, false));

    while (m--)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        g[a].push_back({b, c});
    }

    multiset<pair<ll, pair<int, int>>> st;
    st.insert({0, {1, 0}});
    st.insert({0, {1, 1}});
    dist[1][0] = dist[1][1] = 0;

    while (st.size() > 0)
    {
        auto node = *st.begin();
        int v = node.second.first;
        bool used = node.second.second;
        ll d = node.first;
        st.erase(st.begin());

        if (vis[v][used])
            continue;

        vis[v][used] = true;

        for (auto child : g[v])
        {
            int child_v = child.first;
            ll wt = child.second;

            if (d + wt < dist[child_v][used])
            {
                dist[child_v][used] = d + wt;
                st.insert({d + wt, {child_v, used}});
            }

            if (!used && d + wt / 2 < dist[child_v][1])
            {
                dist[child_v][1] = d + wt / 2;
                st.insert({d + wt / 2, {child_v, 1}});
            }
        }
    }

    cout << min(dist[n][0], dist[n][1]);
}
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const ll INF = 1e16;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, ll>> graph[n + 1];
    vector<vector<ll>> dist(n + 1, vector<ll>(k + 1, INF));

    while (m--)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    multiset<pair<ll, int>> st;
    st.insert({0, 1});
    dist[1][1] = 0;

    while (!st.empty())
    {
        auto node = *st.begin();
        int v = node.second;
        ll d = node.first;
        st.erase(st.begin());

        if (dist[v][k] < d)
            continue;

        for (auto child : graph[v])
        {
            int child_v = child.first;
            ll wt = child.second;

            if (dist[child_v][k] > d + wt)
            {
                dist[child_v][k] = d + wt;
                st.insert({dist[child_v][k], child_v});
                sort(dist[child_v].begin() + 1, dist[child_v].end());
            }
        }
    }

    for (int i = 1; i <= k; i++)
    {
        cout << dist[n][i] << " ";
    }
}
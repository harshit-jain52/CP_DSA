#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const ll INF = 1e16;

vector<pair<int, ll>> graph[N];
vector<ll> dist(N, INF);
vector<bool> vis(N, false);
vector<int> routes(N, 0);
vector<int> maxnum(N, 0);
vector<int> minnum(N, 0);

void djisktra()
{
    dist[1] = 0;
    routes[1] = 1;

    multiset<pair<long, int>> st;
    st.insert({0, 1});

    while (!st.empty())
    {
        auto node = *st.begin();
        st.erase(st.begin());
        int v = node.second;

        if (vis[v])
            continue;

        vis[v] = true;

        for (auto child : graph[v])
        {
            int child_v = child.first;
            ll wt = child.second;

            if (dist[v] + wt == dist[child_v])
            {
                routes[child_v] = (routes[child_v] + routes[v]) % M;
                minnum[child_v] = min(minnum[child_v], minnum[v] + 1);
                maxnum[child_v] = max(maxnum[child_v], maxnum[v] + 1);
            }

            else if (dist[v] + wt < dist[child_v])
            {
                dist[child_v] = dist[v] + wt;
                routes[child_v] = routes[v];
                minnum[child_v] = minnum[v] + 1;
                maxnum[child_v] = maxnum[v] + 1;

                st.insert({dist[child_v], child_v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
    }

    djisktra();

    cout << dist[n] << " " << routes[n] << " " << minnum[n] << " " << maxnum[n] << endl;
}
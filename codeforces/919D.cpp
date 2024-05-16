#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    FASTIO
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<int> g[n];
    vector<int> indegree(n, 0);

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        indegree[y]++;
    }

    queue<int> q;
    vector<int> topo;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        topo.push_back(cur);

        for (int next : g[cur])
        {
            indegree[next]--;
            if (indegree[next] == 0)
                q.push(next);
        }
    }

    if (topo.size() != n)
    {
        cout << -1;
        return 0;
    }

    int dp[n][26];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            dp[i][j] = (s[i] == 'a' + j);
        }
    }

    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int cur = topo[i];
        for (int next : g[cur])
        {
            for (int j = 0; j < 26; j++)
            {
                dp[cur][j] = max(dp[cur][j], (s[cur] == 'a' + j) + dp[next][j]);
                ans = max(ans, dp[cur][j]);
            }
        }
    }

    cout << ans;
}
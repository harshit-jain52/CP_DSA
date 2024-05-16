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

    vector<int> revg[n + 1];
    vector<int> outdegree(n + 1, 0);

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        revg[y].push_back(x);
        outdegree[x]++;
    }

    priority_queue<int> pq;
    vector<int> topo;
    for (int i = 1; i <= n; i++)
    {
        if (outdegree[i] == 0)
            pq.push(i);
    }

    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        topo.push_back(cur);

        for (int prev : revg[cur])
        {
            outdegree[prev]--;
            if (outdegree[prev] == 0)
                pq.push(prev);
        }
    }

    reverse(topo.begin(), topo.end());
    for (int c : topo)
        cout << c << " ";
}
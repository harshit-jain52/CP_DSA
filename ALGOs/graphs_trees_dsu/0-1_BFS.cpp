#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> g[N];
vector<int> lev(N, INF);

void bfs(int src)
{
    deque<int> dq;
    dq.push_back(src);
    lev[src] = 0;

    while (!dq.empty())
    {
        int cur_v = dq.front();
        dq.pop_front();

        for (auto child : g[cur_v])
        {
            int child_v = child.first;
            int wt = child.second;

            if (lev[cur_v] + wt < lev[child_v])
            {
                lev[child_v] = lev[cur_v] + wt;

                if (wt == 1)
                    dq.push_back(child_v);

                else
                    dq.push_front(child_v);
            }
        }
    }

    // Time Complexity: O(V + E);
}

int main()
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int n1, n2, wt;
        cin >> n1 >> n2 >> wt;
        g[n1].push_back({n2, wt});
    }
}
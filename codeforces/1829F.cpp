#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> g[n + 1];

        while (m--)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        map<int, int> ct;
        for (int i = 1; i <= n; i++)
        {
            ct[g[i].size()]++;
        }

        if (ct.size() == 2)
        {
            int x = (*(--ct.end())).first;
            cout << x << " " << x - 1;
        }
        else
        {
            int x, y;
            for (auto it : ct)
            {
                if (it.second == 1)
                {
                    x = it.first;
                }
                else if (it.first != 1)
                {
                    y = it.first - 1;
                }
            }

            cout << x << " " << y;
        }
        cout << endl;
    }
}
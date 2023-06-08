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
        int m, i;
        cin >> m;
        int k = m;
        vector<vector<int>> v(m);
        while (k--)
        {
            int n, temp;
            cin >> n;
            for (i = 0; i < n; i++)
            {
                cin >> temp;
                v[k].push_back(temp);
            }
        }
        int flag;
        vector<int> a(50001, 0);
        vector<int> p;
        for (i = 0; i < m; i++)
        {
            flag = 0;
            for (auto it : v[i])
            {
                if (flag == 0 && a[it] == 0)
                {
                    p.push_back(it);
                    flag = 1;
                }
                a[it]++;
            }
        }

        if (p.size() == m)
        {
            for (i = m - 1; i >= 0; i--)
            {
                cout << p[i] << " ";
            }
        }
        else
        {
            cout << -1;
        }
        cout << '\n';
    }
}
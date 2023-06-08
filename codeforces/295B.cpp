#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    ll a[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    reverse(x.begin(), x.end()); // adding vertices

    vector<ll> ans;
    for (int k = 0; k < n; k++)
    {
        int k_v = x[k];
        ll sum = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                a[i][j] = min(a[i][j], a[i][k_v] + a[k_v][j]);
            }
        }

        for (int i = 0; i <= k; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                sum += a[x[i]][x[j]];
            }
        }
        ans.push_back(sum);
    }

    for (auto it = ans.end() - 1; it >= ans.begin(); it--)
    {
        cout << *it << " ";
    }
}
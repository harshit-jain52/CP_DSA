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
    int n;
    ll x;
    cin >> n >> x;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    map<ll, pair<int, int>> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (m.find(x - a[i] - a[j]) != m.end())
            {
                auto p = m[x - a[i] - a[j]];
                cout << i + 1 << " " << j + 1 << " " << p.first + 1 << " " << p.second + 1;
                return 0;
            }
        }

        for (int j = i - 1; j >= 0; j--)
            m[a[i] + a[j]] = {i, j};
    }

    cout << "IMPOSSIBLE";
}
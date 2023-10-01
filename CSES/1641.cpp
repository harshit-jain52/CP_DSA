#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    ll x;
    cin >> n >> x;

    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<ll, int> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (m.find(x - a[i] - a[j]) != m.end())
            {
                cout << m[x - a[i] - a[j]] << " " << i + 1 << " " << j + 1;
                return 0;
            }
        }
        m[a[i]] = i + 1;
    }

    cout << "IMPOSSIBLE";
}
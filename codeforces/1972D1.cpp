#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    int ct = 0;
    for (int b = 1; b <= m; b++)
    {
        for (int s = 2 * b; s - b <= n; s += b)
        {
            int a = s - b;
            ll g = b * 1LL * __gcd(a, b);
            if (s % g == 0)
                ct++;
        }
    }

    cout << ct << endl;
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    char m[n][n];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> m[i][j];
        }
    }

    int ct = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; ++j)
        {
            int a = m[i][j], b = m[n - 1 - j][i], c = m[n - 1 - i][n - 1 - j], d = m[j][n - 1 - i];
            int maxall = max(a, max(b, max(c, d)));
            ct += 4 * maxall - (a + b + c + d);
        }
    }

    cout << ct / 4 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
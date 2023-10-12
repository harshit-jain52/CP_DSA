#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int isSubstring(string x, string s)
{
    int n = x.size(), m = s.size();
    int i, j, start;

    for (i = 0; i < n; i++)
    {
        start = i;
        for (j = 0; j < m; j++)
        {
            if (x[start++] != s[j])
                break;
            if (start == n && j != m)
                return -1;
        }
        if (j == m)
            return start;
    }

    return -1;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;
    // cout << x << " "<< s<< endl;

    while (x.size() <= 2 * m)
    {
        string tmp = x;
        x = x + tmp;
    }
    x = x + x;
    // cout << x << " "<< s<< endl;

    int ans = isSubstring(x, s);
    if (ans == -1)
    {
        cout << ans << endl;
        return;
    }

    int i = 0;
    for (int i = 0; i < 25; i++)
    {
        if (((1 << i) * n) >= ans)
        {
            cout << i << endl;
            return;
        }
    }
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
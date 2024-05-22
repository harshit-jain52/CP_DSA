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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ct1 = 0, ct0 = 0;
    if (s[0] == '1')
        ct1++;
    else
        ct0++;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == '1' && s[i] != s[i - 1])
            ct1++;
        if (s[i] == '0' && s[i] != s[i - 1])
            ct0++;
    }

    cout << min(ct1, ct0) << endl;
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
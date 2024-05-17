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
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    int ct = 0;
    while (v[0])
    {
        v[2]--;
        v[1]--;
        ct++;
        sort(v.begin(), v.end());
    }

    if ((v[2] - v[1]) % 2)
        cout << -1 << endl;
    else
    {
        ct += v[1];
        cout << ct << endl;
    }
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
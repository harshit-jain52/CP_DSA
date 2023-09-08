#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const ll INF = 1e15;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    ll leftempty[n + 1], rightempty[n + 1], leftstars[n + 1], rightstars[n + 1];
    leftempty[0] = 0, rightempty[n] = 0, leftstars[0] = 0, rightstars[n] = 0;

    for (int i = 0; i < n; i++)
    {
        leftempty[i + 1] = leftempty[i] + (ll)(s[i] == '.');
        leftstars[i + 1] = leftstars[i] + (ll)(s[i] == '*');
        rightempty[n - i - 1] = rightempty[n - i] + (ll)(s[n - i - 1] == '.');
        rightstars[n - i - 1] = rightstars[n - i] + (ll)(s[n - i - 1] == '*');
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     cout << leftempty[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << rightempty[i] << " ";
    // }
    // cout << endl;

    vector<ll> shifttoleft(n + 1, 0), shifttoright(n + 1, 0);
    shifttoleft[0] = 0, shifttoright[n] = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
            shifttoleft[i + 1] = leftempty[i + 1];

        if (s[n - 1 - i] == '*')
            shifttoright[n - 1 - i] = rightempty[n - 1 - i];

        shifttoleft[i + 1] += shifttoleft[i];
        shifttoright[n - 1 - i] += shifttoright[n - i];
    }
    
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << shifttoleft[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << shifttoright[i] << " ";
    // }
    // cout << endl;

    ll moves = INF;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '*')
            continue;

        ll leftm = (shifttoright[0] - shifttoright[i]) - leftstars[i] * rightempty[i];
        ll rightm = (shifttoleft[n] - shifttoleft[i + 1]) - rightstars[i + 1] * leftempty[i + 1];
        moves = min(moves, leftm + rightm);
    }

    if (moves == INF)
        cout << 0;
    else
        cout << moves;

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();
}
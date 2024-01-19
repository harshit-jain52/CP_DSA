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

    map<pair<int, int>, int> ct;
    int d = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'D')
            d++;
        else
            k++;
        int g = __gcd(d, k);
        cout << ++ct[make_pair(d / g, k / g)] << " ";
    }
    cout << endl;
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
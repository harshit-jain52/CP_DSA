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
    int hand = 0;
    ll tot = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        hand += (tmp - 1);
        tot += abs(hand);
    }
    cout << tot << endl;
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
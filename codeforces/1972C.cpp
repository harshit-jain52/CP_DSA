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
    ll n, k;
    cin >> n >> k;
    ll a[n];
    ll tot = k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        tot += a[i];
    }

    sort(a, a + n);
    ll smallest = -1;
    ll subtr = n - 1;
    int idx = -1;
    int ct0 = -1, ct1 = -1;
    for (int i = 1; i < n; i++)
    {
        if ((a[i] - a[i - 1]) * i <= k)
        {
            k -= i * (a[i] - a[i - 1]);
        }
        else
        {
            smallest = a[i - 1] + k / i;
            ct0 = k % i;
            ct1 = i - k % i;
            idx = i;
            break;
        }
    }

    if (idx != -1)
    {
        for (int j = idx; j < n; j++)
        {
            subtr += a[j] - (smallest + 1);
        }
    }

    cout << (tot - subtr) << endl;
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
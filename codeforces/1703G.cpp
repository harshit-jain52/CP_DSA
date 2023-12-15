#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
    // there's no point using a good key after a bad key, as..
    // using good-bad is always more optimal than bad-good
    // so keys: gggg...ggbbb...b

    int n;
    ll k;
    cin >> n >> k;

    ll a[n + 1];
    ll prefsum[n + 1];
    prefsum[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefsum[i] = prefsum[i - 1] + a[i];
    }

    ll maxcoins = prefsum[n] - k * n;

    for (int i = 1; i <= n; i++)
    {
        ll coins = prefsum[i - 1] - k * (i - 1);

        int num = 1;
        for (int j = i; j <= n && num < 30; j++, num++)
        {
            coins += a[j] / (1 << num);
        }

        maxcoins = max(maxcoins, coins);
    }

    cout << maxcoins << endl;
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
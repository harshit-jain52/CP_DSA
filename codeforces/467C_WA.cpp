#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool sortDec(ll a, ll b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, i;
    cin >> n >> m >> k;
    ll p[n], psum[n + 1];
    psum[0] = 0;

    for (i = 0; i < n; i++)
    {
        cin >> p[i];
        psum[i + 1] = psum[i] + p[i];
    }
    vector<ll> ksum;

    for (i = m; i <= n; i++)
    {
        ksum.push_back(psum[i] - psum[i - m]);
    }

    sort(ksum.begin(), ksum.end(), sortDec);

    ll sum = 0;
    for (i = 0; i < k; i++)
    {
        sum += ksum[i];
    }

    cout << sum;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<ll> &v, int k, ll maxsum)
{
    int n = v.size(), sub = 1;
    ll tmpsum = 0;
    for (int i = 0; i < n; i++)
    {
        if (tmpsum + v[i] > maxsum)
        {
            sub++;
            tmpsum = 0;
        }
        tmpsum += v[i];
    }

    return sub <= k;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> x(n);
    ll maxe = 0, sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        maxe = max(x[i], maxe);
        sum += x[i];
    }

    ll lo = maxe, hi = sum, mid;

    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;

        if (check(x, k, mid))
            hi = mid;
        else
            lo = mid + 1;
    }

    if (check(x, k, lo))
        cout << lo;
    else
        cout << hi;
}
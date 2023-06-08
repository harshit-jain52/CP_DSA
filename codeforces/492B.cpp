#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    ll l, temp;
    vector<ll> a;
    cin >> n >> l;

    for (i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());

    ll diff, maxdiff = 0;
    for (i = 1; i < a.size(); i++)
    {
        diff = a[i] - a[i - 1];
        if (diff > maxdiff)
        {
            maxdiff = diff;
        }
    }

    double r = maxdiff / 2.0;
    double b = max(a[0] - 0, l - a[n - 1]);
    cout << fixed << max(r, b);
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    cin >> n;
    vector<pair<ll, ll>> ab(n);

    for (i = 0; i < n; i++)
    {
        cin >> ab[i].first >> ab[i].second;
    }
    sort(ab.begin(), ab.end());
    ll maxb = ab[0].second;
    int count = 0;

    for (i = 1; i < n; i++)
    {
        if (ab[i].second < maxb)
        {
            count++;
        }
        else
        {
            maxb = ab[i].second;
        }
    }

    cout << count;
}
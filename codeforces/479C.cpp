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
    vector<ll> early;
    early.push_back(ab[0].second);

    for (i = 1; i < n; i++)
    {
        if (ab[i].second >= early[early.size() - 1])
        {
            early.push_back(ab[i].second);
        }
        else
        {
            early.push_back(ab[i].first);
        }
    }

    cout << early[n - 1];
}
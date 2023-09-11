#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    int n;
    cin >> n;

    ll time = 0;
    ll reward = 0;
    vector<pair<ll, ll>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        time += v[i].first;
        reward += (v[i].second - time);
    }

    cout << reward << endl;
}
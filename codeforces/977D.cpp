#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int powerOf3(ll x)
{
    int ct = 0;
    while (x > 0)
    {
        if (x % 3 != 0)
        {
            break;
        }
        ct++;
        x /= 3;
    }
    return ct;
}

bool cmp(pair<int, ll> x, pair<int, ll> y)
{
    if (x.first != y.first)
    {
        return x.first > y.first;
    }
    else
    {
        if (x.second != y.second)
        {
            return x.second < y.second;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    ll tmp;
    vector<pair<int, ll>> v;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back({powerOf3(tmp), tmp});
    }

    sort(v.begin(), v.end(), cmp);

    for (auto it : v)
    {
        cout << it.second << " ";
    }
}
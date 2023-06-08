#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
    {
        return a.first > b.first;
    }
    return a.second < b.second;
}

int main()
{
    int n, k, i;
    cin >> n >> k;
    vector<pair<int, int>> v(n);

    for (i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), comp);

    cout << count(v.begin(), v.end(), v[k - 1]);
}